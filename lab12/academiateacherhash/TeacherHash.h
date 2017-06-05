//
// Created by DELL on 04.06.2017.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H
#include<iostream>
#include<functional>

namespace academia {
    class TeacherId{
    public:
        TeacherId();
        TeacherId(int id);
        ~TeacherId();
        int Id()const;
        operator int();
        bool operator==(const TeacherId &id)const;
        bool operator!=(const TeacherId &id)const;
    private:
        int id_;
    };

    bool operator==(int i, const TeacherId& id);

    class Teacher{
    public:
        Teacher();
        ~Teacher();
        Teacher(TeacherId id, std::string name, std::string department);
        TeacherId Id()const;
        std::string Name()const;
        std::string Department()const;
        bool operator==(const Teacher &teacher)const;
        bool operator!=(const Teacher &teacher)const;
    private:
        TeacherId id_;
        std::string name_;
        std::string department_;
    };
    class TeacherHash {
    public:
        TeacherHash() {};
        ~TeacherHash(){};
        size_t operator()(const Teacher &teacher)const;

    private:
        Teacher teacher_;
    };
}


#endif //JIMP_EXERCISES_TEACHERHASH_H
