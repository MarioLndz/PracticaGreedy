#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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