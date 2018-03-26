//
// Created by filip on 26.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <regex>

namespace nets
{
    class View
    {
        public:
            View(std::string text);

            ~View();
            std::string Render(const std::unordered_map <std::string, std::string> &model) const;

        private:
            std::string text_;
    };

}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
