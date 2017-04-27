//
// Created by DELL on 20.04.2017.
//
#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H
#include<vector>
#include<iostream>
#include <random>
#include<memory>


namespace arrays {
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };


    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int start, int step = 1) : start_{start}, step_{step} {}

        virtual int Value(int index) const override;

    private:
        int start_, step_;

    };


    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}

        virtual int Value(int index) const override;

    private:
        int value_;
    };

    class SquaredFill:public ArrayFill{
    public:
        SquaredFill(int a=1, int b=0):a_{a}, b_{b}{}
        virtual int Value(int index) const override;
    private:
        int a_, b_;
    };


    class RandomFill:public ArrayFill{
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> engine , std::unique_ptr<std::uniform_int_distribution<int>>distribution): _engine(std::move(engine)),
                                                                                                                                          _distribution(std::move(distribution)){}
        virtual int Value(int index) const override;
    private:
        std::unique_ptr<std::default_random_engine> _engine;
        std::unique_ptr<std::uniform_int_distribution<int>> _distribution;

    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);


}

#endif //JIMP_EXERCISES_ARRAYFILL_H
