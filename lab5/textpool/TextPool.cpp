//
// Created by DELL on 03.04.2017.
//

#include <iostream>
#include "TextPool.h"

using namespace pool;
using namespace std;

namespace pool{
    TextPool::TextPool(){};
    TextPool::~TextPool() {};
    TextPool::TextPool(TextPool &&new_vec){
        vec_ ={};
        swap(vec_,new_vec.vec_);
    }
    TextPool &TextPool::operator=(TextPool &&new_vec){
        if (this == &new_vec) {
            return new_vec;
        }
        vec_ ={};
        swap(vec_,new_vec.vec_);
    }

    std::experimental::string_view TextPool::Intern(const std::string &str){
            for(auto n:vec_) {
                if (n == str) {
                    return n;
                }
            }
        vec_.insert(std::experimental::string_view(str));
        return std::experimental::string_view(str);
    }
    size_t TextPool::StoredStringCount() const{
        size_t count=0;
        for(auto n:vec_){
            count+=1;
        }

        return count;
    }
}