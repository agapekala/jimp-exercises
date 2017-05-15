//
// Created by DELL on 04.05.2017.
//

#include "Serialization.h"

namespace academia{
    Room::Room(){}

    Room::~Room(){}

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", number_);
        serializer->StringField("type", TypeToString(classroom_));
        serializer->Footer("room");
    }

    std::string Room::TypeToString(Room::Type type) const {
        switch(type){
            case Type::CLASSROOM:
                return "CLASSROOM";
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
        }
    }

    Serializer::Serializer() {}

    Serializer::Serializer(std::ostream *out) {
        out_=out;
    }

    Serializer::~Serializer() {}

    JsonSerializer::JsonSerializer() {}

    JsonSerializer::~JsonSerializer() {}

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        std::string value_str=std::to_string(value);
        *out_<<"\""<<field_name<<"\": "<<value_str<<", ";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        std::string value_str=std::to_string(value);
        *out_<<"\""<<field_name<<"\": "<<value_str<<" ,";
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        if(field_name=="type"){
            *out_<<"\""<<field_name<<"\": \""<<value<<"\"";
        } else {
            *out_ << "\"" << field_name << "\": \"" << value << "\"" << ", ";
        }
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        std::string value_str=std::to_string(value);
        *out_<<"\""<<field_name<<"\": "<<value_str<<", ";
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_<<"\"" + field_name + "\": ";
        value.Serialize(this);
        *out_<<", ";

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_<<"\""<<field_name<<"\": [";
        int iter=0;
        int size=value.size();
        for(const Serializable &n:value){
            iter++;
            n.Serialize(this);
            if(iter!=size){
                *out_<<", ";
            }
        }
        *out_<<"]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_<<"{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_<<"}";
    }


    Building::Building() {}

    Building::~Building() {}

    void Building::Serialize(Serializer *serializer) const {
        serializer->Header("building");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", number_);
        std::vector<std::reference_wrapper<const Serializable>> tmp;
        for(const Room &n : room_){
            tmp.emplace_back(n);
        }
        serializer->ArrayField("rooms", tmp);
        serializer->Footer("building");
    }

    int Building::Id() const {
        return id_;
    }

    XmlSerializer::XmlSerializer() {}

    XmlSerializer::~XmlSerializer() {}

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        std::string value_str=std::to_string(value);
        *out_<<"<"<<field_name<<">"<<value_str<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        std::string value_str=std::to_string(value);
        *out_<<"<"<<field_name<<">"<<value_str<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        std::string value_str=std::to_string(value);
        *out_<<"<"<<field_name<<">"<<value_str<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_ << "<" + field_name + ">";
        value.Serialize(this);
        *out_ <<  "<\\" + field_name + ">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_<<"<"<<field_name<<">";
        int iter=0;
        int size=value.size();
        for(const Serializable &n:value){
            iter++;
            n.Serialize(this);
        }
        *out_<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_<<"<"<<object_name<<">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_<<"<\\"<<object_name<<">";
    }


    BuildingRepository::BuildingRepository() {}

    BuildingRepository::~BuildingRepository() {}

    std::experimental::optional<Building> BuildingRepository::operator[](int id) const{
        for(auto &n:building_list_){
            if(n.Id()==id){
                return std::experimental::make_optional(n);
            }
        }
        return std::experimental::optional<Building>();
    }

    void BuildingRepository::StoreAll(Serializer *serializer) const {
        serializer->Header("building_repository");
        std::vector<std::reference_wrapper<const Serializable>> tmp;
        for(const Building &n : building_list_){
            tmp.emplace_back(n);
        }
        serializer->ArrayField("buildings",tmp);
        serializer->Footer("building_repository");
    }

    void BuildingRepository::Add(const Building &building) {
        building_list_.emplace_back(building);
    }
}
