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

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree){
        int i=0;
        int how_many_values=0;
        int how_many_left=0;
        int how_many_right=0;
        int how_many_e=0;
        std::string value="";
        std::unique_ptr<SmartTree> root;
        while(true){
            if (tree[i]=='['){
                how_many_left+=1;
            }
            if (tree[i]==']'){
                how_many_right+=1;
            }
            if (tree[i]='e'){
                how_many_e+=1;
            }
            if(tree[i]>47 && tree[i]<58) {
                value = value + (char) tree[i];
            }
            if(tree[i]==' '){
                    if(how_many_left==1){
                        root=CreateLeaf(std::stoi(value));
                        how_many_values+=1;
                    }
                    if(how_many_right==0 && how_many_left>1){
                        std::unique_ptr<SmartTree> left_tree_child=CreateLeaf(std::stoi(value));
                        InsertLeftChild(root, left_tree_child);
                        how_many_values+=1;

                    }

                    if(how_many_e==2){
                        std::unique_ptr<SmartTree> right_tree_child=CreateLeaf(std::stoi(value));
                        InsertRightChild(root, right_tree_child);
                        how_many_values+=1;
                    }
                value="";

                }
            i++;
            }


        }
    }
}