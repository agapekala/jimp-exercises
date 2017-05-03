//
// Created by DELL on 27.04.2017.
//

#include"CircleException.h"


int main(){
    try{
        drawBall();
    }catch(BallException b){
        cout << "Blad podczas rysowania kuli" << endl;
    }
    catch(CircleException a) {
        cout << "Blad podczas rysowania kola" << endl;
    }
}