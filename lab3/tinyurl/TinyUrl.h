//
// Created by Maria on 18.03.2017.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H


#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>

namespace tinyurl{

    struct TinyUrlCodec{
        std::map <std::string, std::string> tiny_map;
        std::array <char, 6> tiny_array;
    };


    void NextHash(std::array<char, 6> *state);
    std::unique_ptr<TinyUrlCodec> Init();
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}


#endif //JIMP_EXERCISES_TINYURL_H
