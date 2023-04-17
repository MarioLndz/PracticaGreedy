#include <iostream>
#include <queue>
#include <vector>
#include "Cancion.h"
#include <set>

using namespace std;

// https://code-with-me.global.jetbrains.com/0tD7iDuIjaZfvQhPgYpaNg#p=CL&fp=822925F2AFF0EA271CB3072E68B90D0B71F615661DFCF94436CA541B4EBF8DDF

int buscaMenosReproducida (const vector<Cancion*> & canciones){

    int indice = 0;
    for(int i = 1; i < canciones.size(); ++i){

        if(*canciones[i] < *canciones[indice]){

            indice=i;

        }
    }

    return (indice);
}

bool buscarCancion(const Cancion & c, const vector<Cancion*> & v){

    bool salida=false;
    int contador=0;

    while(!salida && contador<v.size()){

        if(*v.at(contador) == c) {
            salida = true;
        }

        contador++;
    }

    return salida;
}


/*
 * TUTORIAL PARA WAN
 * PON ESTO EN LA TERMINAL: git config --global credential.helper store
 *                          git pull
 * PON USUARIO Y CONTRASEÑA SI TE LA PIDE
 */

int main () {
    const int NUM_CANCIONES = 5;
    const int TOPE = 3;

    vector<Cancion> jukebox;

    for (int i = 0; i < NUM_CANCIONES; ++i){
        jukebox.push_back(Cancion(i));
    }

    vector<Cancion*> cola_inmediata;

    int opcion = 0;
    while (opcion != -1){
        cout << "QUE CANCION QUIERES REPRODUCIR?\t[0-" << NUM_CANCIONES-1 << "]" << endl;
        cin >> opcion;

        if (opcion >= 0 && opcion <= (NUM_CANCIONES-1)){    // OPCION VALIDA
            jukebox.at(opcion).aniadeReproduccion();

            if(cola_inmediata.size() < TOPE){   // CABEN MAS CANCIONES
                if (!buscarCancion(jukebox.at(opcion), cola_inmediata))
                    cola_inmediata.push_back(&jukebox.at(opcion));

            } else {    // COLA_INMEDIATA LLENA
                if (!buscarCancion(jukebox.at(opcion), cola_inmediata)){
                    int indice = buscaMenosReproducida(cola_inmediata);
                    cola_inmediata[indice] = &jukebox.at(opcion);
                }

            }

            for (auto it = cola_inmediata.begin(); it != cola_inmediata.end(); ++it)
                cout << *(*it) << endl;
        }

    }

    return 0;
}