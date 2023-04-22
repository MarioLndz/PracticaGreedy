#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool Pertenece(const vector<int> & v,int n){            // creo que vector no tiene ninguna función que lo compruebe

    bool pertenece=false;
    int contador=0;

    while(!pertenece && contador<v.size()){

        if(v.at(contador)==n)
            pertenece=true;

        contador++;
    }

    return pertenece;
}

int CancionMasLejana (const vector<int> & inmediato, const vector<int> & peticiones, int pos_inicial){
    int indice = 0;
    int max_distancia = 0;
    int contador = 0;

    for (int i = 0; contador != peticiones.size() && i < inmediato.size(); ++i){
        bool encontrado = false;
        contador = pos_inicial;

        while (contador < peticiones.size() && !encontrado){
            if (inmediato.at(i) == peticiones.at(contador)){
                encontrado = true;
            } else {
                ++contador;
            }
        }

        if (contador > max_distancia){
            max_distancia = contador;
            indice = i;
        }
    }
    return (indice);
}


int main (int argc, char * argv[]) {
    if (argc != 2){
        cout << "ERROR: NUMERO INCORRECTO DE ARGUMENTOS" << endl;
        exit (-1);
    }

    ifstream file;
    file.open(argv[1]);

    if (!file){
        cout << "ERROR ABRIENDO EL ARCHIVO" << endl;
        exit (-1);
    }

    vector<int> peticiones;  // peticiones de canciones realizadas por el cliente
    while (!file.eof()){
        int id;
        file >> id;

        peticiones.push_back(id);
    }
    file.close();

    const int NUM_PETICIONES = peticiones.size();
    const int TAMANIO_INMEDIATO = NUM_PETICIONES/5;

    vector<int> inmediato;    // canciones que están en la reproducción inmediata

    int NUM_INTERCAMBIOS = 0;

    cout << "VECTOR DE PETICIONES:\t";
    for (int i = 0; i < NUM_PETICIONES; ++i)
        cout << peticiones.at(i) << "\t";
    cout << endl;

    for (int i = 0; i < NUM_PETICIONES; ++i){
        if (!Pertenece(inmediato, peticiones.at(i))){
            if (inmediato.size() < TAMANIO_INMEDIATO){
                inmediato.push_back(peticiones.at(i));

            } else {
                inmediato.at(CancionMasLejana(inmediato, peticiones, i)) = peticiones.at(i);
                ++NUM_INTERCAMBIOS;
            }

        }
    }

    cout << "Se han necesitado realizar " << NUM_INTERCAMBIOS << " intercambios" << endl;


    return 0;
}