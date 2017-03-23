//
// Created by Maria on 21.03.2017.
//

#include "SmartTree.h"
namespace datastructures {
    std::unique_ptr<SmartTree> CreateLeaf(int value){
        std::unique_ptr<SmartTree> p = std::make_unique<SmartTree>();
        p->value=value;
        p->right=nullptr;
        p->left=nullptr;
        return p;
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        tree->left=move(left_subtree);
        return tree;
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right=move(right_subtree);
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr->left!=nullptr){
            PrintTreeInOrder(unique_ptr->left, out);
        }
        (*out)<<unique_ptr->value<<", ";
        if(unique_ptr->right!=nullptr){
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        std::string str;
        str+="[";
        str=str+std::to_string(tree->value);
        if(tree->left==nullptr){
            str=str+" [none]";
        }
        if(tree->left!=nullptr){
            str=str+" "+DumpTree(tree->left);
        }
        if(tree->right==nullptr) {
            str = str + " [none]";
        }
        if(tree->right!=nullptr){
            str=str+" "+DumpTree(tree->right);
        }
        str+="]";
        return str;
    }

    //std::unique_ptr<SmartTree> RestoreTree(const std::string &tree);
}