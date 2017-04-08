//
// Created by DELL on 06.04.2017.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include<iostream>
#include <string>
#include <initializer_list>
#include <vector>
namespace academia {
    class StudyYear{
    public:
        StudyYear();
        StudyYear(int year);
        ~StudyYear();
        StudyYear &operator++();
        StudyYear &operator--();
        bool operator<(StudyYear const &new_year)const;
        bool operator>(StudyYear const &new_year)const;
        bool operator==(const StudyYear &new_year);
        friend std::ostream &operator<<(std::ostream &out, StudyYear &new_year);
        friend std::istream &operator>>(std::istream &is, StudyYear &new_year);

        operator int()const;
    private:
        int year_;
    };

    class Student {
    public:
        Student();
        Student(std::string id, std::string first_name, std::string last_name, std::string program, StudyYear year)
        :id_(id), first_name_(first_name), last_name_(last_name), program_(program), year_(year){};
        ~Student();
        std::string Id()const;
        std::string FirstName()const;
        std::string LastName()const;
        std::string Program()const;
        StudyYear Year()const;
        void ChangeLastName(std::string new_name);
        void ChangeFirstName(std::string new_name);
        bool operator==(const Student &student);
        friend std::istream &operator>>(std::istream &is, Student& student);
        friend std::ostream &operator<<(std::ostream &out, Student &student);
        operator int()const;

    private:
        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;
    };
    class StudentRepository{
    public:
        StudentRepository();
        ~StudentRepository();
        StudentRepository(const std::initializer_list<Student> &repo): repo_(repo){
        };
        size_t StudentCount()const;
        Student &operator[](std::string id);
        bool operator==(const StudentRepository &student_repo)const;
        friend std::ostream &operator<<(std::ostream &out, StudentRepository &student_repo);
    private:
        std::vector<Student> repo_;
    };
    std::string SubstrStr(int i,int iter, std::string format);
}



#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
