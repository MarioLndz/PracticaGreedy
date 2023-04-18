//
// Created by mario on 29/03/23.
//

#include "punto.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

Punto::Punto(int la_x, int la_y) {
    this->x = la_x;
    this->y = la_y;

}

Punto::Punto (){
    this->x = 0;
    this->y = 0;
}

int Punto::getCuadrante() const {
    int cuadrante = 0;

    if (x > 0 && y >= 0){
        cuadrante = 1;
    } else if (x <= 0 && y > 0){
        cuadrante = 2;
    } else if (x < 0 && y <=0) {
        cuadrante = 3;
    } else if (x >= 0 && y < 0){
        cuadrante = 4;
    }

    return (cuadrante);

}

int Punto::getX() const{

    return (this->x);
}

int Punto::getY() const{

    return (this->y);
}

bool Punto::operator== (const Punto & otro) const{
    bool son_iguales = true;

    if (this->x != otro.x){
        son_iguales = false;
    } else if (this->y != otro.y){
        son_iguales = false;
    }

    return (son_iguales);

}

bool Punto::operator!= (const Punto & otro) const{
    return (!(*this == otro));
}


Punto& Punto::operator=(const Punto &p){
    this->x = p.getX();
    this->y = p.getY();

    return *this;
}

ostream & operator<< (ostream & os, const Punto & pt){
    os << "(" << pt.getX() << "," << pt.getY() << ")";

    return (os);
}

int Punto::distancia(Punto p){

    return(sqrt(pow(p.getX() - getX(),2) + pow(p.getY() - getY(),2)));

}