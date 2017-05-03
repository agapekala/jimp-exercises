//
// Created by DELL on 27.04.2017.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H
#include<iostream>
#include <stdexcept>
namespace academia {

    class Pesel {
    public:
        Pesel();
        ~Pesel();
        Pesel(std::string pesel);
        std::string Get();

        void ValidatePesel(std::string pesel);

    private:
        std::string pesel_;
    };

    class AcademiaDataValidationError:std::runtime_error{
    public:
        AcademiaDataValidationError(std::string message);
        virtual ~AcademiaDataValidationError();
    private:
        std::string message_;
    };

    class InvalidPeselCharacter:public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(std::string message, int a);
        virtual ~InvalidPeselCharacter();

        void PeselCharacter(Pesel pesel);
    private:
        std::string message_;
    };

    class InvalidPeselLength:public AcademiaDataValidationError{
    public:
        InvalidPeselLength(std::string message);
        virtual ~InvalidPeselLength();

        void PeselCharacter(Pesel pesel);
    private:
        std::string message_;
    };


class InvalidPeselChecksum:public AcademiaDataValidationError{
public:
    InvalidPeselChecksum(std::string message, int a);
    virtual ~InvalidPeselChecksum();

    void PeselCharacter(Pesel pesel);
private:
    std::string message_;
};
}


#endif //JIMP_EXERCISES_PESEL_H
