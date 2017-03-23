//
// Created by Maria on 18.03.2017.
//

#include <utility>
#include <string>
#include <array>
#include <memory>
#include "TinyUrl.h"

namespace tinyurl {


    std::unique_ptr<TinyUrlCodec> Init() {
        std::unique_ptr<TinyUrlCodec> p = std::make_unique<TinyUrlCodec>();
        return p;
    }

    void NextHash(std::array<char, 6> *state) {
        unsigned int i = 5;
        while ((*state)[i] == 'z') {
            (*state)[i] = 48;
            i--;
            }
        if(((*state)[i]>47&&(*state)[i]<57 )|| ((*state)[i]>64&&(*state)[i]<90) || ((*state)[i]>96 && (*state)[i]<122)) {
            (*state)[i] += 1;
        }

        if ((*state)[i] == 57) {
            (*state)[i] = 65;
        }
        if ((*state)[i] == 90) {
            (*state)[i] = 97;
        }

    }
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        std::string newurl;
        for(int i=0; i<6; i++){
            (*codec)->tiny_array[i]=url[i];
        }
        NextHash(&(*codec)->tiny_array);
        for(int i=0; i<6; i++){
            newurl[i]=(*codec)->tiny_array[i];
        }
        (*codec)->tiny_map[newurl]=url;
        return newurl;
    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        return (codec)->tiny_map.find(hash)->second;
    }

}

