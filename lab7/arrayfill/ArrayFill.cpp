//
// Created by DELL on 20.04.2017.
//

#include "ArrayFill.h"

namespace arrays{

    int IncrementalFill::Value(int index) const{
        return start_+index*step_;
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    int SquaredFill::Value(int index) const {
        return a_*index*index +b_;
    }
    int RandomFill::Value(int index) const{
        return (*_distribution)(*_engine);
    }

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }
}