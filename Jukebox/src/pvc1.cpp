//
// Created by mario on 18/04/23.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Algoritmo de kruskal = Diapositiva 50
// Problema de viajante de comercio = Diapositiva 133

int main (int argc, char * argv[]){
    if (argc != 2) {
        cout << "NUMERO INCORRECTO DE ARGUMENTOS" << endl;
        exit(-1);
    }

    ifstream file;
    file.open(argv[1]);

    if (!file){
        cout << "ERROR ABRIENDO EL ARCHIVO" << endl;
        exit(-1);
    }

    int aux;
    file >> aux;

    const int NUM_NODOS = aux;

    int distancias[NUM_NODOS][NUM_NODOS];

    for (int i = 0; i < NUM_NODOS; ++i) {
        for (int j = 0; j < NUM_NODOS; ++j) {
            file >> distancias[i][j];
        }
    }

    file.close();

    vector<int> visita;

    visita.push_back(0);  // la empresa está en 0
    int pos_actual = 0;   // posicion en la que estamos

    int indice_minimo = 1;   // para calcular la siguiente posicion
    int min_dist = distancias[pos_actual][indice_minimo];

    int distancia_solucion = 0;

    while (visita.size() < NUM_NODOS){
        min_dist = 100;
        for (int i = 1; i < NUM_NODOS; ++i){
            int num = distancias[pos_actual][i];

            if((find(visita.begin(), visita.end(), i) == visita.end()) && (num < min_dist) && (i != pos_actual)){
                min_dist = num;
                indice_minimo = i;
            }
        }
        distancia_solucion += min_dist;

        pos_actual = indice_minimo;
        visita.push_back(pos_actual);
    }

    distancia_solucion += distancias[visita.at(0)][visita.at(visita.size()-1)];

    cout << "ORDEN DE VISITA:\t";
    for (auto it = visita.begin(); it != visita.end(); ++it)
        cout << *it << "\t";
    cout << endl;

    cout << distancia_solucion << endl;

    return (0);

}