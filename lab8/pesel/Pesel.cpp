//
// Created by DELL on 27.04.2017.
//

#include "Pesel.h"

namespace academia{

    Pesel::Pesel() {}

    Pesel::~Pesel() {}

    Pesel::Pesel(std::string pesel) {
        pesel_=pesel;
    }

    void Pesel::ValidatePesel(std::string pesel) {
        InvalidPeselLength("str", 1).PeselCharacter(pesel);
        InvalidPeselCharacter("").PeselCharacter(pesel);
        InvalidPeselChecksum("", 1).PeselCharacter(pesel);
    }

    std::string Pesel::Get() {
        return pesel_;
    }


    AcademiaDataValidationError::AcademiaDataValidationError(std::string message):std::runtime_error(message) {
        message_=message;
    }

    AcademiaDataValidationError::~AcademiaDataValidationError() {}



    InvalidPeselCharacter::InvalidPeselCharacter(std::string message, int a) : AcademiaDataValidationError(message) {
        message_=message;
    }

    InvalidPeselCharacter::~InvalidPeselCharacter() {}

    void InvalidPeselCharacter::PeselCharacter(Pesel pesel) {
        int size=pesel.Get().size();
        std::string str=pesel.Get();
        for(int i=0; i<size; i++){
            if(str[i]< '0' or str[i]>'9'){
                throw InvalidPeselCharacter(message_);
            }
        }
    }


    InvalidPeselLength::InvalidPeselLength(std::string message): AcademiaDataValidationError(message) {
        message_=message;
    }

    void InvalidPeselLength::PeselCharacter(Pesel pesel) {
       if (pesel.Get().size()==11){
           throw InvalidPeselLength(message_);
       }
    }

    InvalidPeselLength::~InvalidPeselLength() {}



    InvalidPeselChecksum::InvalidPeselChecksum(std::string message, int a) : AcademiaDataValidationError(message) {
        message_=message;
    }

    InvalidPeselChecksum::~InvalidPeselChecksum() {}

    void InvalidPeselChecksum::PeselCharacter(Pesel pesel) {
        std::string str=pesel.Get();
        int a=9*str[0]+7*str[1]+3*str[2]+str[3]+9*str[4]+7*str[5]+3*str[6]+str[7]+9*str[8]+7*str[9];
        if(a%10!=str[10]){
            throw InvalidPeselChecksum(message_, a);
        }
    }


}