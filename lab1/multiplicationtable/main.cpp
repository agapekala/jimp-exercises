#include <iostream>
#include "MultiplicationTable.h"
using namespace std;

int main(){
    int tab[10][10];
    MultiplicationTable(tab);
    PrintMultiplicationTable(tab);
    return 0;
}
