//
// Created by mario on 18/04/23.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

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

    int num_nodos=0;
    file >> num_nodos;

    int distancias[num_nodos][num_nodos];

    for (int i = 0; i < num_nodos; ++i)
        for (int j = 0; j < num_nodos; ++j)
            file >> distancias[i][j];

    unordered_set<int> orden;
    bool done = false;

    orden.insert(0);  // la empresa está en 0
    int pos_actual=0;   // posicion en la que estamos
    int min_dist=100;
    int indice_minimo=0;   // para calcular la siguiente posicion

    int distancia_solucion = 0;

    while (orden.size() < num_nodos){
        min_dist = 100;
        for (int i = 1; i < num_nodos; ++i){
            if((orden.find(i) == nullptr) && (distancias[pos_actual][i] < min_dist) && (i != pos_actual)){
                min_dist=distancias[pos_actual][i];
                indice_minimo = i;
            }
        }
        distancia_solucion += min_dist;

        pos_actual = indice_minimo;
        orden.insert(pos_actual);
    }

    /*
    for (int i = 0; i < num_nodos; ++i){
        for (int j = 0; j < num_nodos; ++j){
            cout << distancias[i][j] << "\t";
        }
        cout << endl;
    }
    */
    

    for(auto it=orden.begin();it!=orden.end();++it)
        cout << *it << "\t";
    cout << endl;

    cout << distancia_solucion << endl;


    return (0);

}