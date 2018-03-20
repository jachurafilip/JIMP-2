//
// Created by filip on 20.03.18.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <string>
#include <array>
#include <memory>

namespace tinyurl {
    struct codec {
        std::array<char,6> hash;
        std::string url;


    };

    using TinyUrlCodec = struct codec;
    std::unique_ptr<TinyUrlCodec> Init();
    void MoveHash(std::array<char,6> *state, int i);
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);

};


#endif //JIMP_EXERCISES_TINYURL_H
