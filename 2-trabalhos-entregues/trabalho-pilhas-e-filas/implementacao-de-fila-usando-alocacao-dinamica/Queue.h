#ifndef QUEUE_H
#define QUEUE_H

struct Node;

class Queue {
private:
    Node* first; // ponteiro para o primeiro no
    Node* last;  // ponteiro para o ultimo no
public:
    Queue(); // Construtor
    ~Queue(); // Destrutor
    bool empty(); // Lista esta vazia?
    void enqueue(int key); // Insere key ao final
    int dequeue(); // Remove primeiro elemento
    int head(); // Devolve primeiro elemento da fila.
    int tail(); // Devolve ultimo elemento da fila.
};

#endif
