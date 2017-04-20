//
// Created by DELL on 08.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <set>
#include<algorithm>
namespace datastructures {

    class Word{
    public:
        Word();
        ~Word();
        Word(std::string word);
        operator std::string()const;
        bool operator==(const Word &word)const;
        bool operator!=(const Word &word)const;
        bool operator<(const Word &word)const;
        friend std::ostream &operator<<(std::ostream &out, Word &word);
    private:
        std::string word_;

    };
    class Counts{
    public:
        Counts();
        ~Counts();
        Counts(int count);
        operator int()const;
        bool operator==(const Counts &count);
        Counts &operator++();
        bool operator<(const Counts &count);
        bool operator>(const Counts &count);
        friend std::ostream &operator<<(std::ostream &out, Counts &count);
    private:
        int count_;

    };

    class WordCounter {
    public:
        WordCounter();
        ~WordCounter();
        WordCounter(std::initializer_list<Word> vec);
        int DistinctWords()const;
        int TotalWords()const;
        int operator[](std::string word);
        std::set<Word> Words();
        friend std::ostream &operator<<(std::ostream &out, WordCounter &count);
        static WordCounter FromInputStream(std::istream &in);
        void New(Word word);
        std::vector<std::pair<Word, Counts>> vec_;
        std::vector<Word> vec_word_;
    private:


    };

}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
