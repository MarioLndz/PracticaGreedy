//
// Created by mario on 21/04/23.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

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
    int min_distancia=100;
    int p1, p2;

    for (int i = 1; i < num_nodos; ++i){
        for (int j = 0; j < num_nodos; ++j){
            if(distancias[i][j] < min_distancia){
                p1=i;
                p2=j;
                min_distancia=distancias[i][j];
            }
        }
    }
    orden.insert(p1);
    orden.insert(p2);


    return (0);

}