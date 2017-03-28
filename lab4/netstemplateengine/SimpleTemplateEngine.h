//
// Created by DELL on 27.03.2017.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include<iostream>
#include <string>
#include <unordered_map>
namespace nets{

    class View {
    public:
        View();
        View(std::string pattern);
        ~View();
        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    private:
        std::string pattern_;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
