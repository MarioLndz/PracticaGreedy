//
// Created by mario on 23/04/23.
//

#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int main (int argc, char * argv[]){
    if (argc != 2 && argc != 3){
        cout << "ERROR: FALTA NUMERO DE NODOS A GENERAR" << endl;
        exit (-1);
    }

    srand(time(NULL));

    int aux = atoi(argv[1]);
    const int NUM_CASOS = aux;
    string fichero = argc == 2 ? "data_jukebox" : argv[2];

    ofstream file;
    file.open(fichero.c_str());

    if (!file){
        cout << "ERROR ABRIENDO ARCHIVO" << endl;
        exit (-1);
    }

    file << NUM_CASOS << endl;

    int distancias[NUM_CASOS][NUM_CASOS];

    for (int i = 0; i < NUM_CASOS; ++i){
        distancias[i][i] = -1;
        for (int j = i+1; j < NUM_CASOS; ++j){
            distancias[i][j] = rand()%101;
            distancias[j][i] = distancias[i][j];
        }
    }

    for (int i = 0; i < NUM_CASOS; ++i) {
        for (int j = 0; j < NUM_CASOS; ++j){
            file << distancias[i][j] << "\t";
        }
        file << endl;
    }

    file.close();

    return (0);
}