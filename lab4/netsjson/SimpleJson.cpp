//
// Created by DELL on 27.03.2017.
//

#include "SimpleJson.h"

namespace nets{
    using ::std::ostream;
    using ::std::endl;

    JsonValue::JsonValue(bool flag) {
        flag_=std::experimental::make_optional(flag);
    }
    JsonValue::JsonValue(double double_number) {
        double_number_=std::experimental::make_optional(double_number);
    }
    JsonValue::JsonValue(int int_number) {
        int_number_=std::experimental::make_optional(int_number);
    }
    JsonValue::JsonValue(std::map<std::string, JsonValue> object) {
        object_=std::experimental::make_optional(object);
    }
    JsonValue::JsonValue(std::string name) {
        name_=std::experimental::make_optional(name);
    }
    JsonValue::JsonValue(std::vector<JsonValue> tab) {
        tab_=std::experimental::make_optional(tab);
    }
    JsonValue::~JsonValue(){};

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{
        if(object_) {
            //std::map<std::string, JsonValue> new_object=object_;
            for (auto iter :*object_) {
                if (iter.first == name) {
                    return std::experimental::make_optional(iter.second);
                }
                return std::experimental::optional<JsonValue>{};
            }
        }
        return {};
    }
    std::string JsonValue::ToString() const{
        if(int_number_){
            return std::to_string(*int_number_);
        }
    }
}