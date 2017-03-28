//
// Created by DELL on 27.03.2017.
//

#include "SimpleTemplateEngine.h"

namespace nets {
    using ::std::ostream;
    using ::std::endl;

    View::View(std::string pattern){
        pattern_=pattern;
    }
    View::~View(){}

    std::string View::Render(const std::unordered_map <std::string, std::string> &model) const{
        int i,j=0;
        std::string str="", word, new_str, sentence=pattern_;
        int size=pattern_.size(), count=0;
        bool flag=true;
        for(i=0; i<size; i++){
            if(sentence[i]=='{' && sentence[i+1]=='{' && sentence[i+2]!='{'){
                flag=false;
            }
            if(sentence[i-3]!='}' && sentence[i-2]=='}' && sentence[i-1]=='}'){
                flag=true;
            }
            if(flag==true){
                new_str+=sentence[i];
            }
            else{
                str += sentence[i];
                if(sentence[i-1]!='}' && sentence[i]=='}' && sentence[i+1]!='}'){
                    count+=1;
                }
                if(sentence[i-1]=='}' && sentence[i]=='}' && sentence[i-2]!='}'){
                    if(count!=0){
                        word=str;
                    }
                    else {
                        str.erase(0, 2);
                        str.erase(str.size() - 2);
                        for (auto iter = model.begin(); iter != model.end(); ++iter) {
                            if (iter->first == str) {
                                word = iter->second;
                            }
                        }
                    }
                    str="";
                    count=0;
                }
                new_str+=word;
                word="";
            }
        }
        return new_str;
    }
}