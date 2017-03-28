//
// Created by DELL on 27.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <iostream>
#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

namespace nets{
    using std::experimental::optional;
     class JsonValue{
     public:
         JsonValue();
         JsonValue(std::string name);
         JsonValue(int int_number);
         JsonValue(double double_number);
         JsonValue(bool flag);
         JsonValue(std::vector<JsonValue> tab);
         JsonValue(std::map<std::string, JsonValue> object);
         ~JsonValue();

         std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
         std::string ToString() const;

     private:
         optional <std::string> name_;
         optional<int> int_number_;
         optional<double> double_number_;
         optional<bool> flag_;
         optional<std::vector<JsonValue>> tab_;
         optional<std::map<std::string, JsonValue>> object_;
     };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
