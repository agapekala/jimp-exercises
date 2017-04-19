//
// Created by DELL on 08.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <set>
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
        friend std::ostream &operator<<(std::ostream &out, Counts &count);
    private:
        int count_;

    };

    class WordCounter {
    public:
        WordCounter();
        ~WordCounter();
        //WordCounter(std::initializer_list<std::pair<Word, Counts>> vec):vec_(vec){};
        WordCounter(std::initializer_list<Word> vec_word):vec_word_(vec_word){};
        int DistinctWords()const;
        int TotalWords()const;
        int operator[](std::string word);
        std::set<Word> Words();
        friend std::ostream &operator<<(std::ostream &out, WordCounter &count);

    private:
        std::vector<std::pair<Word, Counts>> vec_;
        std::vector<Word> vec_word_;
    };

}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
