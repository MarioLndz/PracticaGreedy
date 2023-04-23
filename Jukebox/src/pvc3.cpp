//
// Created by mp on 23/04/23.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// algoritmo de inserción
// eficiencia n²log2(n), n³

int main(int argc, char * argv[]){

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

    // en primer lugar buscamos el nodo más cercanos de 0

    int minimo=100;
    int p1;

    for(int i=0;i<NUM_NODOS;i++){
        if(distancias[0][i]<minimo){
            minimo=distancias[0][i];
            p1=i;
        }

    }

    visita.at(0)=0;                    // metemos 0 al principio salimos de la empresa
    visita.at(NUM_NODOS-1)=p1;          // metemos p1 al final que es el

    // ya sabemos que la minima distancia es minimo y que se produce entre los puntos p1 y 0
    // vamos a coger el nodo k que tenga menor cantidad dist(p1,k) + dist(0,k) - dist(p1,0)

    int contador=1, indice=0;
    int distancia_solucion = 0;

    while(visita.size()<NUM_NODOS-2){
        int suma_minima=100;
        for (int i = 1; i < NUM_NODOS; ++i){
            int num = distancias[p1][i] + distancias[0][i] - minimo;
            if((num < suma_minima) && (i != p1)){
                suma_minima=num;
                indice=i;
            }
        }
        visita.at(NUM_NODOS-contador-1)=indice;  // lo metemos en la última posición no ocupada
        p1=indice;
        distancia_solucion += suma_minima;
        contador++;
    }

    cout << "ORDEN DE VISITA:\t";
    for (auto it = visita.begin(); it != visita.end(); ++it)
        cout << *it << "\t";
    cout << endl;

    distancia_solucion += distancias[visita.at(0)][visita.at(visita.size()-1)];
    cout << distancia_solucion << endl;
}