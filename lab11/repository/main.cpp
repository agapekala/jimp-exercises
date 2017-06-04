//
// Created by DELL on 18.05.2017.
//

#include "Repository.h"

using::academia::Repository;
using::academia::Room;

int main(){
    Room room1 {117, "218", Room::Type::COMPUTER_LAB};
    Room room2 {200, "123", Room::Type::LECTURE_HALL};
    Repository<Room> repo{room1, room2};
    std::cout<<repo.Size()<<'\n';
    std::cout<<repo[117].Name();

}