#include <iostream>
#include <queue>
#include <vector>
#include "Cancion.h"
#include <set>

using namespace std;

/*
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
*/

bool Pertenece(const vector<int> & v,int n){            // creo que vector no tiene ninguna función que lo compruebe

    bool pertenece=false;
    int contador=0;

    while(contador<v.size()&&!pertenece){

        if(v.at(contador)==n)
            pertenece=true;

        contador++;
    }

    return pertenece;
}

int MasLejano(const vector<int> & v, const vector<int> & l){   // devuelve el indice del mas lejano y sabemos de precondicion que si o si todos los elementos de v estan al menos una vez en l

    int indice=0;
    int max_distancia=0;

    for(int i=0;i<v.size();i++){

        bool encontrado = false;
        int contador=0;

        while(!encontrado && contador<l.size()){

            if(v.at(i)==l.at(contador)){
                encontrado=true;
            }
            else{
                contador++;
            }
        }

        if(contador>max_distancia){
            max_distancia=contador;
            indice=i;
        }

    }

    return indice;
}


// https://code-with-me.global.jetbrains.com/h0-lX-XK4jirUn_ZSL5btg#p=CL&fp=E39314F4DCA53A806D09956EDBE103D7C3B3AA43DE585ED7E7ACF1C66ADE4603

int main () {
    /*
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
     */

    vector<int> inmediato;    // canciones que están en la reproducción inmediata
    inmediato.push_back(4);
    inmediato.push_back(10);
    inmediato.push_back(7);
    inmediato.push_back(1);

    vector<int> seleccion;     // selección de canciones realizada por el cliente
    seleccion.push_back(3);
    seleccion.push_back(7);
    seleccion.push_back(2);
    seleccion.push_back(4);
    seleccion.push_back(5);
    seleccion.push_back(1);

    int NUM_INTERCAMBIOS = 0;

    for(int i = 0; i < seleccion.size(); ++i){

        if(!Pertenece(inmediato,seleccion.at(i))){         // caso en el que la canción no está en inmediato, en caso de que si lo esté no haermos nada

            // tenemos que eliminar un elemento de inmediato, para ello vamos a buscar el primer elemento de inmediato que no esté en selección

            bool alguno_no_pertenece=true;
            int contador;

            while(contador<inmediato.size()&&alguno_no_pertenece){

                alguno_no_pertenece=Pertenece(seleccion,inmediato.at(contador));

                if(!alguno_no_pertenece){
                    inmediato.at(contador)=seleccion.at(i);
                }

                contador++;
            }

            // ya habríamos realizado el intercambio
            //¿que hacer si todos los elementos de inmediato están alguna vez en selección?

            if(alguno_no_pertenece){       // este sería el caso en el que todos los elementos de seleccion están en inmediato

                // se me ocurre cambiar en el que este más lejos  si tenemos inmediato 1 2 3 y seleccion 4 6 2 3 9 1, entonces cambiar el 1
                inmediato.at(MasLejano(inmediato,seleccion))=seleccion.at(i);
                ++NUM_INTERCAMBIOS;


            }
        }
    }

    for(int i=0;i<inmediato.size();i++){
        cout << inmediato.at(i) << "\t";
    }

    cout << endl;
    cout << "NUMERO DE INTERCAMBIOS =\t" << NUM_INTERCAMBIOS << endl;

    return 0;
}