//
// Created by DELL on 11.03.2017.
//

#include "Polybius.h"
#include <fstream>
int main(int argc, char *argv[]){
    //std::ifstream file(argv[1]);

    if(*argv[3]=='1'){
        char line[256];
        std::string str;
        std::fstream file(argv[1]);
        std::ofstream encrypted(argv[2], std::ios_base::in | std::ios_base::app);
        if(!file){
            std::cout<<"Błąd otwarcia pliku!"<<std::endl;
        }
        while(!file.eof()){
            file.getline(line, 256);
            str=PolybiusCrypt(line);
            encrypted<<str;
        }
        file.close();
        encrypted.close();
    }

    if(*argv[3]=='0'){
        char line[256];
        std::string str;
        std::fstream file(argv[1]);
        std::ofstream decrypted(argv[2], std::ios_base::in | std::ios_base::app);
        if(!file){
            std::cout<<"Błąd otwarcia pliku!"<<std::endl;
        }
        while(!file.eof()){
            file.getline(line, 256);
            str=PolybiusDecrypt(line);
            decrypted<<str;
        }
        file.close();
        decrypted.close();
    }
    return 0;
}