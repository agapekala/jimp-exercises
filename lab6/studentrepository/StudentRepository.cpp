//
// Created by DELL on 06.04.2017.
//

#include "StudentRepository.h"

namespace academia{
    using::std::string;
    using::std::cout;
    using::std::ostream;

    std::string SubstrStr(int i,int iter, std::string format){
        int j=i;
        std::string str="";
        while(format[j]!='"'){
            str+=format[j];
            j++;
        }
        return str;
    }

    //Student
    Student::Student() {};
    Student::~Student(){}

    std::string Student::Id()const {
        return id_;
    }

    std::string Student::FirstName()const {
        return first_name_;
    }

    std::string Student::LastName()const {
        return last_name_;
    }

    std::string Student::Program()const {
        return program_;
    }

    StudyYear Student::Year()const {
        return year_;
    }

    void Student::ChangeLastName(std::string new_name) {
        last_name_=new_name;
    }
    void Student::ChangeFirstName(std::string new_name) {
        first_name_=new_name;
    }

    bool Student::operator==(const Student &student) {
        return year_==student.year_;
    }

    Student::operator int() const {
        return year_;
    }


    std::istream &operator>>(std::istream &is, Student &student) {
        std::string format, id="", first_name="", last_name="", program="", year="";
        getline(is, format);
        int iter=0, year_num=5;
        for(int i=0; i<format.length(); i++){
            if(format[i-2]==' ' and format[i-1]=='"' and iter==0){
                id=SubstrStr(i,iter,format);
                iter++;
            }

        else if(format[i-2]==' ' and format[i-1]=='"' and iter==1){
            first_name=SubstrStr(i,iter,format);
            iter++;
        }

        else if(format[i-2]==' ' and format[i-1]=='"' and iter==2){
            last_name=SubstrStr(i,iter,format);
            iter++;
        }

        else if(format[i-2]==' ' and format[i-1]=='"' and iter==3){
            program=SubstrStr(i,iter,format);
            iter++;
        }

        else if(format[i-1]==' ' and format[i+1]=='}' and iter==4){
            year=format[i];
            year_num=std::stoi(year);
        }

        }
        student.id_=id;
        student.first_name_=first_name;
        student.last_name_=last_name;
        student.program_=program;
        student.year_=StudyYear(year_num);

    }

    std::ostream &operator<<(std::ostream &out, Student &student) {
        return out<<"Student {id: \""<<student.id_<<"\", first_name: \""<<student.first_name_<<"\", last_name: \""<<student.last_name_
                <<"\", program: \""<<student.program_<<"\", year: "<<student.year_<<"}";
    }


    //StudyYear
    StudyYear::StudyYear() {
        year_=1;
    }
    StudyYear::StudyYear(int year) {
        year_=year;
    }
    StudyYear::~StudyYear() {};
    StudyYear &StudyYear::operator++(){
        ++year_;
        return *this;
    }
    StudyYear &StudyYear::operator--(){
        --year_;
        return *this;
    }
    bool StudyYear::operator<(StudyYear const &new_year)const{
        return year_<new_year.year_;
    }
    bool StudyYear::operator>(StudyYear const &new_year)const{
        return year_>new_year.year_;
    }
    bool StudyYear::operator==(const StudyYear &new_year){
        return year_==new_year.year_;
    }
    std::ostream &operator<<(std::ostream &out, StudyYear &new_year){
        return out<<new_year.year_;
    }
    StudyYear::operator int()const{
        return year_;
    }

    std::istream &operator>>(std::istream &is, StudyYear &new_year) {
        is>>new_year.year_;
        return is;
    }

    //StudentRepository

    StudentRepository::StudentRepository() {};
    StudentRepository::~StudentRepository() {}

    size_t StudentRepository::StudentCount() const {
        size_t count=0;
        for(auto n:repo_){
            count++;
        }
        return count;
    }

    Student &StudentRepository::operator[](std::string id) {
        for(auto &n:repo_){
            if(n.Id()==id){
                return n;
            }
        }
    }

    bool StudentRepository::operator==(const StudentRepository &student_repo) const{
        return student_repo.StudentCount()==StudentCount();
    }

    std::ostream &operator<<(std::ostream &out, StudentRepository &student_repo){
        out<<"[";
        for(auto n:student_repo.repo_){
            out<<n;
            out<<","<<std::endl;
        }
        out<<"]";
    };

}