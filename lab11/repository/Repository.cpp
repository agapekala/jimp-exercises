//
// Created by DELL on 18.05.2017.
//

#include "Repository.h"
namespace academia {
    Room::Room() {}

    Room::~Room() {}

    std::string Room::TypeToString(Room::Type type) const {
        switch (type) {
            case Type::CLASSROOM:
                return "CLASSROOM";
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
        }
    }
    int Room::Id() const {
        return id_;
    }
    std::string Room::Name() const {
        return number_;
    }

}