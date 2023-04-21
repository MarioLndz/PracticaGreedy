//
// Created by mario on 17/04/23.
//
#include "Cancion.h"

using namespace std;

Cancion::Cancion() {
    id=-1;
    num_reproducciones=0;
}

Cancion::Cancion(int _id, int _num_reproducciones){

    id=_id;
    num_reproducciones=_num_reproducciones;
}

int Cancion::getId() const {

    return id;
}

int Cancion::getNumReproducciones() const {

    return num_reproducciones;
}

void Cancion::aniadeReproduccion (){
    ++num_reproducciones;
}

bool Cancion::operator< (const Cancion & otro) const{
    return (this->num_reproducciones < otro.num_reproducciones ? true : false);
}

bool Cancion::operator== (const Cancion & otro) const{
    return (this->id == otro.id ? true : false);
}

ostream & operator<< (ostream & os, const Cancion & pt){
    os << "ID: " << pt.id << "\tNumReproducciones: " << pt.num_reproducciones;
    return (os);
}
