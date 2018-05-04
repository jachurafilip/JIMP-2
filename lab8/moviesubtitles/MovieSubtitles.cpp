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

                std::string start_time,end_time;
                for(int i=11; i>-1;i--)
                {
                    int k =0;
                    if(i==2 || i ==5)
                    {
                        start_time[i]=':';
                        end_time[i]=':';
                        k++;
                    }
                    else if(i==8)
                    {
                        start_time[i]=',';
                        end_time[i]=',';
                        k++;
                    }
                    else
                    {
                        start_time[i]='0'; //TODO
                    }

                }

                if(start>end) throw SubtitleEndBeforeStart(line_id,line[0]);

                start+=move;
                end+=move;
                if(start<0) throw NegativeFrameAfterShift(line_id,line[0]);

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
