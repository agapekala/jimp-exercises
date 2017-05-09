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
        *out_<<field_name;

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_<<"\""<<field_name<<"\": [";
        int iter=0;
        int size=value.size();
        for(const Serializable &n:value){
            iter++;
            JsonSerializer serial{out_};
            n.Serialize(&serial);
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
        serializer->ArrayField("rooms", room_);
        serializer->Footer("building");
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
        *out_<<"<"<<field_name<<">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_<<"<"<<field_name<<">";
        int iter=0;
        int size=value.size();
        for(const Serializable &n:value){
            iter++;
            XmlSerializer serial{out_};
            n.Serialize(&serial);
        }
        *out_<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_<<"<"<<object_name<<">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_<<"<\\"<<object_name<<">";
    }

}
