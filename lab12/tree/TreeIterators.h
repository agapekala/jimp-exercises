//
// Created by DELL on 06.06.2017.
//



#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "Tree.h"
#include <vector>

namespace tree{
    template <class T>
    class PreOrder{
    };

    template<class T>
    class PreOrderTreeIterator {
    public:
        PreOrderTreeIterator() {}

        ~PreOrderTreeIterator() {}

        PreOrderTreeIterator(Tree<T> node) {
            pointer_ = node;
        }

        PreOrderTreeIterator &operator++() {
            return pointer_.Get_Vector().find(pointer_).next();
        }


    private:
        Tree<T> pointer_;

    };

    template<class T>
    class PreOrderTreeView{};

    template <class T>
    class InOrder{

    };

    template<class T>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(){}
        ~InOrderTreeIterator(){}
        InOrderTreeIterator(const Tree<T> &node){
            pointer_ = std::make_shared<Tree<T>>(node);
        }

        void operator()(const Tree<T> &node){
            pointer_ = std::make_shared<Tree<T>>(node);
        }

        void operator++(){
        }

        T operator*(){
            return (*pointer_.get()).Value();
        }

        bool operator!=(InOrderTreeIterator &iterator2){
            return pointer_!=iterator2.pointer_;
        }

    private:
        std::shared_ptr<Tree<T>> pointer_;
    };

    template<class T>
    class InOrderTreeView{};

    template <class T>
    class PostOrder{

    };

    template<class T>
    class PostOrderTreeIterator{
    public:
        PostOrderTreeIterator(){}
        ~PostOrderTreeIterator(){}
        PostOrderTreeIterator(const Tree<T> &node){
            pointer_ = std::make_shared<Tree<T>>(node);
        }

        void operator()(const Tree<T> &node){
            pointer_ = std::make_shared<Tree<T>>(node);
        }

        void operator++(){
        }

        T operator*(){
            return (*pointer_.get()).Value();
        }

        bool operator!=(PostOrderTreeIterator &iterator2){
            return pointer_!=iterator2.pointer_;
        }

    private:
        std::shared_ptr<Tree<T>> pointer_;
    };

    template<class T>
    class PostOrderTreeView{};

}

class TreeIterators {

};


#endif //JIMP_EXERCISES_TREEITERATORS_H

