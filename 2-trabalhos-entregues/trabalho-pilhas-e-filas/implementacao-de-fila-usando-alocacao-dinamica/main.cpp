#include <iostream>
#include "Queue.h"  // inclui biblioteca
using namespace std;

int main() {
    Queue *fila; // Ponteiro para Queue
    
    fila = new Queue(); // Cria fila do tipo Queue

    for(int i = 1; i <=9; i++)
        fila->enqueue(i);  // enfileira alguns elementos

    while( !fila->empty() )
        cout << fila->dequeue() << endl; // desenfileira

    delete fila; // libera memoria alocada para a fila

    return 0;
}
