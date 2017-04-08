//
// Created by DELL on 07.04.2017.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include <iostream>
#include <vector>
namespace datastructures {
    class Iterator {
    public:
        Iterator();
        ~Iterator();
        Iterator(int *iter_int, std::string *iter_str);
        bool operator!=(const Iterator &iter);
        Iterator &operator++();
        std::pair<std::string, int> operator*();
    private:
        int *iter_int_;
        std::string *iter_str_;
    };

    class Zipper {
    public:
        Zipper();
        Zipper(std::vector<std::string> str, std::vector<int> int_vec);
        ~Zipper();
        Iterator begin();
        Iterator end();
        static Zipper zip(std::vector<std::string> str, std::vector<int> int_vec);

    private:
        std::vector<std::string> str_;
        std::vector<int> int_vec_;
    };
    int Foo(const std::vector<std::string> &v1, const std::vector<int> &v2);

}

#endif //JIMP_EXERCISES_ZIPPER_H
