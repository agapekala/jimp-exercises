//
// Created by DELL on 27.03.2017.
//

#include "SimpleJson.h"

namespace nets{
    using ::std::ostream;
    using ::std::endl;
    using ::std::literals::operator""s;

    JsonValue::JsonValue() {}

    JsonValue::JsonValue(bool flag) {
        flag_=flag;
    }
    JsonValue::JsonValue(double double_number) {
        double_number_=double_number;
    }
    JsonValue::JsonValue(int int_number) {
        int_number_=int_number;
    }
    JsonValue::JsonValue(std::map<std::string, JsonValue> object) {
        object_=object;
    }
    JsonValue::JsonValue(std::string name) {
        name_=name;
    }
    JsonValue::JsonValue(std::vector<JsonValue> tab) {
        tab_=tab;
    }

    JsonValue::~JsonValue(){};

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{
            for (auto iter : *object_) {
                if (iter.first == name) {
                    return std::experimental::make_optional(iter.second);
                }
                //return std::experimental::optional<JsonValue>{};
            }
        return {};
    }


    std::string JsonValue::ToString() const{
        if(int_number_){
            if(*int_number_==0){
                return ""s;
            }
            else {
                return std::to_string(*int_number_);
            }
        }
        if (flag_){
            if(flag_.value()==true){
                return "true";
            }
            else{
                return "false";
            }
        }
        if(double_number_){
            std::string str=std::to_string(*double_number_);
            int size=str.length();
            return str.substr(0, size-4);
        }
        if(name_){
            std::string new_name=*name_;
            size_t size=(*name_).length();
            size_t iter=0;

            for(int i=0; i<size; i++){
                if(((*name_)[i]=='"') || ((*name_)[i]=='\\')){
                    new_name.insert(i+iter, "\\");
                    iter++;
                }

            }
            return "\""+ new_name +"\""s;
        }
        if(object_){
            ;std::string str;
            std::string new_object="{";
            for(auto n:*object_){
                str=n.first;
                size_t size=(n.first.length());
                size_t iter=0;
                for(int j=0; j<size; j++){
                    if(n.first[j]=='"' || n.first[j]=='\\'){
                        str.insert(j+iter, "\\");
                        iter++;
                    }
                }
                new_object+="\"" + str +"\": "s;
                new_object+=(n.second.ToString()+", ");
            }
            new_object=new_object.erase(new_object.length()-2, 2);
            new_object+="}";
            return new_object;
        }
        if(tab_){
            std::string new_tab="[";
            for(auto n:*tab_){
                new_tab+=(n.ToString()+", ");
            }
            new_tab=new_tab.substr(0, new_tab.length()-2);
            new_tab+="]"s;
            return new_tab;
        }

    }

}