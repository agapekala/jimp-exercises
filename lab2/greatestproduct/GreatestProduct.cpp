//
// Created by DELL on 12.03.2017.
//

#include "GreatestProduct.h"

int GreatestProduct(const std::vector<int> &numbers, int k){
    vector <int> v2;
    for(int i=0; i<k; i++){
        v2.emplace_back(0);
    }
    int a=0, tmp=0;
    for(int x:numbers){
        a=x;
        for(int &y:v2){
            if(a>y){
                tmp=y;
                y=a;
                a=tmp;
            }
        }

    }
    int product=1;
    for(int x:v2){
        product*=x;
    }
    return product;
}
