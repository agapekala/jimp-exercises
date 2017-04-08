//
// Created by DELL on 07.04.2017.
//

#include "Zipper.h"

namespace datastructures{
    Iterator::Iterator() {};
    Iterator::~Iterator() {};
    Iterator::Iterator(int *iter_int, std::string *iter_str) {
        iter_int_=iter_int;
        iter_str_=iter_str;
    }
    bool Iterator::operator!=(const Iterator &iter){
        return iter_int_!=iter.iter_int_;
    }
    Iterator &Iterator::operator++(){
        ++iter_int_;
        ++iter_str_;
        return *this;
    }

    std::pair<std::string, int> Iterator::operator*() {
        int a=*iter_int_;
        std::string b=*iter_str_;
        return std::pair<std::string, int> {b,a};
    }

    Zipper::Zipper() {};
    Zipper::~Zipper() {}

    Iterator Zipper::begin() {
        int *a=&int_vec_[0];
        std::string *b=&str_[0];
        return Iterator(a,b);
    }

    Zipper::Zipper(std::vector<std::string> str, std::vector<int> int_vec) {
        str_=str;
        int_vec_=int_vec;

    }

    Iterator Zipper::end() {
        int *a;
        std::string *b;
        if(int_vec_.size()<str_.size()) {
            a = &int_vec_[int_vec_.size()];
            b = &str_[int_vec_.size()];
        } else{
            a = &int_vec_[str_.size()];
            b = &str_[str_.size()];
        }
        return Iterator(a,b);
    }

    Zipper Zipper::zip(std::vector<std::string> str, std::vector<int> int_vec) {
        return Zipper(str, int_vec);
    }


    int Foo(const std::vector<std::string> &v1, const std::vector<int> &v2) {
        for (const std::pair<std::string,int> &p : Zipper::zip(v1,v2)) {
            if (p.first == "elo") {
                return p.second+4;
            }
        }
        return 0;
    }
}