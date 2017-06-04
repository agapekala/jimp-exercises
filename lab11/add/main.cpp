//
// Created by DELL on 18.05.2017.
//

#include <vector>
#include "Add.h"

int main() {
    int result1 = Add(2, 7);
    std::complex<int> num1(1,-3), num2(2,5);
    auto result2=Add(num1, num2);
    double result3=Add(12.0234,4.7841);
    std::cout<<result1<<'\n';
    std::cout<<result2.real() <<"+"<< result2.imag()<<"i"<<'\n';
    std::cout<<result3<<'\n';

    std::vector<int> v{1,2,3,4,5,6};
    for(auto n:v){
        std::cout<<Value(&n)<<", ";
    }

    std::cout<<'\n';
    int a=100;
    int * mypointer=&a;
    std::cout<<Value(mypointer)<<'\n';

    std::shared_ptr<int> origin = std::make_shared<int>(3);
    std::cout<<Value(origin);

}
