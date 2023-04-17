#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cancion {
    int id;
    int num_reproducciones;
};

// https://code-with-me.global.jetbrains.com/0tD7iDuIjaZfvQhPgYpaNg#p=CL&fp=822925F2AFF0EA271CB3072E68B90D0B71F615661DFCF94436CA541B4EBF8DDF

int main () {
    priority_queue<int, vector<int>, greater<>> mi_cola;

    mi_cola.push(70);
    mi_cola.push(60);
    mi_cola.push(85);

    while (!mi_cola.empty()){
        cout << mi_cola.top() << endl;
        mi_cola.pop();
    }

    return 0;
}