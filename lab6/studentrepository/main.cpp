//
// Created by DELL on 06.04.2017.
//
#include <iostream>
#include "StudentRepository.h"
using::academia::StudyYear;
using::academia::Student;
using::academia::StudentRepository;
int main(){
    //Student s1{"2031", "Katarzyna", "Bach", "informatyka", 3};
    Student s1{};
    std::cin>>s1;
    std::cout<<s1<<std::endl;
    //StudyYear s2(2);
    //std::cout<<s2;
    /*
    StudentRepository repo
            {{"2030", "Michał", "Karak", "architektura", 5}, {"2031", "Katarzyna", "Bach", "informatyka", 3}};
    std::cout<<repo<<std::endl;
    repo["2030"].ChangeFirstName("Andrzej");
    std::cout<<repo<<std::endl;
     */
    return 0;
}
