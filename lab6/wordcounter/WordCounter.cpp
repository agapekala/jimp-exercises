//
// Created by DELL on 08.04.2017.
//

#include "WordCounter.h"

namespace datastructures{
    Counts::Counts() {};
    Counts::~Counts() {};
    Counts::Counts(int count){
        count_=count;
    }

    Counts::operator int() const {
        return count_;
    }

    bool Counts::operator==(const Counts &count) {
        return count_==count.count_;
    }

    Counts &Counts::operator++() {
        ++count_;
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, Counts &count) {
        return out<<count.count_;
    }

    bool Counts::operator<(const Counts &count) {
        return count_<count.count_;
    }

    bool Counts::operator>(const Counts &count) {
        return count_>count.count_;
    }

    WordCounter::WordCounter(){
        vec_={};
    };

    WordCounter::WordCounter(std::initializer_list<Word> vec) {
        int iter=0;
        for (auto &n:vec) {
            iter=0;
            if (vec_.size() == 0) {
                vec_.push_back(std::make_pair(n, Counts(1)));
            } else {
                for (auto &m:vec_) {
                    if (n == m.first and &n!=vec.begin()) {
                        ++m.second;
                        iter++;
                    }
                }
                if(iter==0) {
                    vec_.push_back(std::make_pair(n, Counts(1)));
                }
            }
        }
    }

    WordCounter::~WordCounter() {}

    int WordCounter::DistinctWords() const {
        int size=vec_.size();
        return size;
    }

    int WordCounter::TotalWords() const {
        int iter=0;
        for(auto n: vec_){
            iter+=n.second;
        }
        return iter;
    }

    int WordCounter::operator[](std::string word) {
        int iter=0;
        for(auto n:vec_){
            if(n.first==Word(word)){
                iter=n.second;
            }
        }
        return iter;
    }

    std::set<Word> WordCounter::Words() {
        int iter=0;
        std::set<Word> tmp;
        for(auto n:vec_){
            tmp.insert(n.first);
        }
        return tmp;
    }

    std::ostream &operator<<(std::ostream &out, WordCounter &count) {
        for(int i=0; i<count.vec_.size();i++){
            out<<"{"<<count.vec_[i].first<<", "<<count.vec_[i].second<<"}"<<", ";
        }
        return out;
    }

    WordCounter WordCounter::FromInputStream(std::istream &in) {
        int letters=0;
        std::vector<Word> vec_word;
        //std::vector<std::pair<Word, Counts>> vec;
        WordCounter counter;
        if(!in){
            std::cout<<"Nie można otworzyć pliku!"<<std::endl;
        }
        char n;
        std::string tmp="";
        while(in.get(n)) {
            if((n>60 and n<123) or (n>64 and n<91)) {
                tmp += n;
            }
            else{
                vec_word.push_back(Word(tmp));
                tmp="";
            }
        }
        for(auto n:vec_word){
            counter.New(n);
        }

        return counter;
    }

    void WordCounter::New(Word word) {
        int iter=0;
        if (vec_.size() == 0) {
            vec_.push_back(std::make_pair(word, Counts(1)));
        } else {
            for (auto &m:vec_) {
                if (word == m.first ) {
                    ++m.second;
                    iter++;
                }
            }
            if(iter==0) {
                vec_.push_back(std::make_pair(word, Counts(1)));
            }
        }
    }



    Word::Word() {};
    Word::~Word() {};
    Word::Word(std::string word) {
        word_=word;
    }

    Word::operator std::string() const {
        return word_;
    }

    bool Word::operator==(const Word &word) const{
        return word_==word.word_;
    }

    bool Word::operator<(const Word &word) const {
        return word_<word.word_;
    }

    bool Word::operator!=(const Word &word) const {
        return word_!=word.word_;
    }

    std::ostream &operator<<(std::ostream &out, Word &word) {
        return out<<word.word_;
    }


}