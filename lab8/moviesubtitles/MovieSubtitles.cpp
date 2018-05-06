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


    void CheckForExceptions(const std::string &text, int delay, int prev)
    {
        std::regex pattern {R"((\d+)\n(\d{2}\:\d{2}\:\d{2},\d{3}) --> (\d{2}\:\d{2}\:\d{2},\d{3})\n((?:.+\n*)+))"};
        std::smatch match;
        if(!std::regex_match(text,match,pattern)) throw InvalidSubtitleLineFormat(prev+1,text);
        if(std::stoi(match[1].str())!=prev+1) throw OutOfOrderFrames(prev+1, match[1].str());
        if(match[2].str()>match[3].str()) throw SubtitleEndBeforeStart(prev+1,match[2].str()+" --> "+match[3].str());

    }


    std::string Pass(const std::string &time, int delay)
    {
        int czas[4];
        czas[0]=std::atoi(time.substr(0,2).c_str());
        czas[1]=std::atoi(time.substr(3,2).c_str());
        czas[2]=std::atoi(time.substr(6,2).c_str());
        czas[3]=std::atoi(time.substr(9,3).c_str());

        czas[3]+=delay;
        if(czas[3]>1000)
        {
            czas[3]-=1000;
            czas[2]++;
        }
        if(czas[2]>60)
        {
            czas[2]-=60;
            czas[1]++;
        }
        if(czas[1]>60)
        {
            czas[1]=-60;
            czas[0]++;
        }
        std::string output;
        for(int i=0; i<3;i++)
        {
            if(czas[i]<10)
            {
                output.push_back('0');
            }
            output.append(std::to_string(czas[i]));
            if(i==2) output.push_back(',');
            else output.push_back(':');
        }
        if(czas[3]<100) output.append("0");
        if(czas[3]<10) output.append("0");
        output.append(std::to_string(czas[3]));
        return output;
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *input,
                                              std::stringstream *output)
    {
        if (framerate < 1) {
            throw SubtitlesException(framerate, "Invalid framerate");
        }

        std::regex pattern {R"((\d+)\n(\d{2}\:\d{2}\:\d{2},\d{3}) --> (\d{2}\:\d{2}\:\d{2},\d{3})\n((?:.+\n*)+))"};
        std::regex next {R"(\n\n)"};

        std::smatch match;

        std::string line, file;
        int prev = 0;

        while (!(*input).eof())
        {
            std::getline(*input, line);
            file.append(line+"\n");
        }

        while(std::regex_search(file,match,next))
        {
            std::smatch match2;
            std::string record = match.prefix().str();
            CheckForExceptions(record, delay,prev);

            std::regex_match(record , match2, pattern);

            *output<<match2[1]<<"\n"<<Pass(match2[2].str(),delay)<<" --> "<<Pass(match2[3].str(),delay)<<"\n"<<match2[4].str()<<"\n\n";

            file = match.suffix().str();
            prev++;
        }
        if(delay<0) throw NegativeFrameAfterShift(1,file);

    }

    int SubtitleEndBeforeStart::LineAt() const {
        return line_;
    }

    int InvalidSubtitleLineFormat::LineAt() const {
        return line_;
    }
}
