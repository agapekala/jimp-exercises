//
// Created by DELL on 18.05.2017.
//

#ifndef JIMP_EXERCISES_REPOSITORY_H
#define JIMP_EXERCISES_REPOSITORY_H

#include<iostream>
#include<vector>
#include<initializer_list>
#include<map>

namespace academia {
    class Room {
    public:
        Room();

        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        std::string TypeToString(Type type) const;
        int Id() const;
        std::string Name() const;
        Room(int id, std::string number, Type classroom) : id_(id), number_(number), classroom_(classroom) {};
        ~Room();
    private:
        int id_;
        std::string number_;
        Type classroom_;
    };

    template<class T>
    class Repository{
    public:
        Repository(){};
        ~Repository(){};
        Repository(std::initializer_list<T> object):object_(object){};

        size_t Size() const{
        return object_.size();
        }

        T operator[](int id) const{
            for(auto n:object_){
                if(n.Id()==id){
                    return n;
                }
            }
            return T();
        }
        /*int NextId(){

        }*/

    private:
        std::vector<T> object_;
    };


}
#endif //JIMP_EXERCISES_REPOSITORY_H
