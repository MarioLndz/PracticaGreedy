//
// Created by mario on 17/04/23.
//

#ifndef JUKEBOX_CANCION_H
#define JUKEBOX_CANCION_H

#endif //JUKEBOX_CANCION_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Cancion {
private:
    int id;
    int num_reproducciones;

public:

    Cancion();

    Cancion(int _id, int _num_reproducciones=0);

    int getId() const;

    int getNumReproducciones() const;

    bool operator< (const Cancion & otro) const;

    bool operator== (const Cancion & otro) const;

    void aniadeReproduccion ();

    friend ostream & operator<< (ostream & os, const Cancion & pt);
};
