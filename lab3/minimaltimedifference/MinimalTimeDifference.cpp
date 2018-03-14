//
// Created by jachfili on 14.03.18.
//

#include "MinimalTimeDifference.h"
#include <regex>
namespace minimaltimedifference
{
    unsigned int ToMinutes(std::string time_HH_MM)
    {
        return (time_HH_MM[0] - 48) * 600 + (time_HH_MM[1] - 48) * 60 + (time_HH_MM[3] - 48) * 10 +
               (time_HH_MM[4] - 48);
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times)
    {
        std::regex pattern {R"(([0-1]?[0-9])|(2[0-3])):([0-5][0-9])"};
        std::vector<int> czasy;
        for (auto v: times)
        {
            std::string line {v};
            std::smatch match;
            if(std::regex_match(line,match,pattern))
            {
                int czas = ToMinutes(v);
                czasy.push_back(czas);
            }
        }
        std::sort(czasy.begin(),czasy.end());
        int min = czasy[1]-czasy[0];
        for (int i = 2; i<czasy.size();i++)
        {
            if (czasy[i]-czasy[i-1]<min) {
                min = czasy[i] - czasy[i - 1];
            }
        }
        return min;
    }
}
