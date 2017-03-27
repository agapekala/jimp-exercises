//
// Created by DELL on 17.03.2017.
//

#include "TinyUrl.h"

namespace tinyurl{

    std::unique_ptr<TinyUrlCodec> Init(){
        std::unique_ptr<TinyUrlCodec> new_object=std::make_unique<TinyUrlCodec>();
        return new_object;
    }
    void NextHash(std::array<char, 6> *state){
        unsigned int i=5;
        while((*state)[i]=='z'){
            (*state)[i]='0';
            i--;
        }
        if((*state)[i]<=121 && (*state)[i]>=97){
            (*state)[i]+=1;
        }
        if((*state)[i]<=89 && (*state)[i]>=65){
            (*state)[i]+=1;
        }
        if((*state)[i]<=56 && (*state)[i]>=48){
            (*state)[i]+=1;
        }
        if((*state)[i]=='9'){
            (*state)[i]='A';
        }
        if((*state)[i]=='Z'){
            (*state)[i]='a';
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        std::string str;
        for(int i=0; i<6; i++){
            (*codec)->new_array[i]=url[i];
        }
        NextHash(&(*codec)->new_array);
        for(int i; i<6; i++){
            str+=(*codec)->new_array[i];
        }
        (*codec)->new_map[str]=url;
        (*codec)->new_map["000000"]="000000";
        return str;
    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        std::string url;
        auto i = codec->new_map.find(hash);
        url=i->second;
        return url;
    }
}