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

    WordCounter::WordCounter(){
        vec_={};
        for(auto &n:vec_word_){
            for(auto &m:vec_) {
                if (n == m.first) {
                    ++m.second;
                } else if (m==*vec_.end() and m.first!=n) {
                    vec_.push_back(std::make_pair(n, Counts(1)));
                }
            }
        }
    };

    WordCounter::~WordCounter() {}

    int WordCounter::DistinctWords() const {
        int iter=0;
    std::vector<Word> tmp;
        for(auto n:vec_word_){
            for(auto p:tmp){
                if(p==n){
                    iter++;
                }
            }
            if(iter==0){
                tmp.push_back(n);
            }
        }
        int size=tmp.size();
        return size;
    }

    int WordCounter::TotalWords() const {
        int iter=0;
        for(auto n: vec_word_){
            iter++;
        }
        return iter;
    }

    int WordCounter::operator[](std::string word) {
        int iter=0;
        for(auto n:vec_word_){
            if(n==Word(word)){
                iter++;
            }
        }
        return iter;
    }

    std::set<Word> WordCounter::Words() {
        int iter=0;
        std::set<Word> tmp;

        for(auto n:vec_word_){
            for(auto m:tmp){
                if(&n==&m){
                    iter++;
                }
            }
            if (iter==0){
                tmp.insert(n);
            }
        }
        return tmp;
    }

    std::ostream &operator<<(std::ostream &out, WordCounter &count) {
        return out<<count.vec_[0].first<<", "<<count.vec_[0].second;
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