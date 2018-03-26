//
// Created by filip on 26.03.18.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
using std::string;
using std::unordered_map;

namespace nets
{

    View::View(string text)
    {
        text_ = text;
    }

    View::~View() {}

    std::string View::Render(const unordered_map<string, string> &model) const {
        int i;
        std::regex pattern(R"(\{\{\w+\}\})");
        std::smatch match;
        string output = text_;

        while (std::regex_search(output, match, pattern)){
            for (auto v: match)
            {
                string value = v.str();
                value = value.substr(2, v.length()-4);
                auto position = model.find(value);
                if (position != model.end())
                {
                    std::string key = position->first;
                    std::string change_to = position->second;

                    i=match.position();
                    output = output.replace(i, key.length()+4, change_to);

                }
                else
                {
                    i = match.position();
                    output = output.replace(i, value.length()+4, "");
                }
            }

        }
        return output;
    }
}
