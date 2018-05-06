//
// Created by filip on 04.05.18.
//

#include "MovieSubtitles.h"

namespace moviesubs {
    void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *input,
                                                           std::stringstream *output)
    {
        if(framerate<1)
        {
            throw  SubtitlesException(framerate,"Negative framerate");
        }

        int move = delay*framerate/1000;

        std::regex pattern(R"(\{(-?\d+)\}\{(-?\d+)\}(.+))");
        int line_id = 1;
        char buffer[1000];

        while(input->getline(buffer,1000))
        {
            std::cmatch line;
            if(std::regex_match(buffer,line,pattern))
            {
                int start = std::stoi(line[1])+move;
                int end = std::stoi(line[2])+move;
                if(start>end)
                {
                    throw(SubtitleEndBeforeStart(line_id,line[0]));

                }
                if(start<0)
                {
                    throw (NegativeFrameAfterShift(line_id,line[0]));
                }
                (*output)<<"{"<<start<<"}{"<<end<<"}"<<line[3]<<"\n";
            }
            else
            {
                throw(InvalidSubtitleLineFormat(line_id,line[0]));
            }


            line_id++;
        }
    }



    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *input,
                                              std::stringstream *output)
    {
        if(framerate<1)
        {
            throw SubtitlesException(framerate, "Invalid framerate");
        }
        int move = delay*framerate/1000;
        std::regex pattern{"(([0-9]+)\n(([0-9]{2,}):([0-9]{2}):([0-9]{2}),([0-9]{3}) --> ([0-9]{2,}):([0-9]{2}):([0-9]{2}),([0-9]{3}))((\n.*)+[\n]{1,2}))"}, line_pattern{".*\n.*\n(.*\n)+\n?[^0-9]"};
        int line_id=1,start,end;
        std::string text = input -> str();

        while(!text.empty())
        {
            int position = text.find("\n\n");
            if(position>text.length()) position = text.length()-2;
            std::string title = text.substr(0,position+2);
            text = text.substr(position+2,text.length());
            std::smatch line;
            if(std::regex_match(text,line,pattern))
            {
                start = 3600000*std::stoi(line[4].str())+60000*std::stoi(line[5].str())+1000*std::stoi(line[6].str())+std::stoi(line[7].str());
                end = 3600000*std::stoi(line[8].str())+60000*std::stoi(line[9].str())+1000*std::stoi(line[10].str())+std::stoi(line[11].str());

                if(start>end) throw SubtitleEndBeforeStart(line_id,line[0]);
                start+=move;
                end+=move;
                if(start<0) throw NegativeFrameAfterShift(line_id,line[0]);

                std::string start_time,end_time;

                start_time.append(std::to_string(start/3600000));
                start = start%3600000;
                start_time.push_back(':');
                end_time.append(std::to_string(end/3600000));
                end_time.push_back(':');
                end = end%3600000;

                start_time.append(std::to_string(start/60000));
                start = start%60000;
                start_time.push_back(':');
                end_time.append(std::to_string(end/60000));
                end_time.push_back(':');
                end = end%60000;

                start_time.append(std::to_string(start/1000));
                start = start%1000;
                start_time.push_back(',');
                end_time.append(std::to_string(end/1000));
                end_time.push_back(',');
                end = end%1000;

                (*output)<<line[2]<<"\n"<<start_time<<" --> "<<end_time;



            } else throw(InvalidSubtitleLineFormat(line_id,line[0]));
        }
    }

    int SubtitleEndBeforeStart::LineAt() const {
        return line_;
    }

    int InvalidSubtitleLineFormat::LineAt() const {
        return line_;
    }
}
