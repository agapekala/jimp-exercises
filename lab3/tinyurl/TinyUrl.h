//
// Created by DELL on 17.03.2017.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <iostream>
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>
namespace tinyurl{
    struct TinyUrlCodec{
        std::array<char, 6> new_array;
        std::map<std::string,std::string> new_map;
    };
    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H
