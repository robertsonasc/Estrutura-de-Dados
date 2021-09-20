/**
 * Implementacao de uma Fila usando lista 
 * simplesmente encadeada sem no cabeca
 */
#include <iostream>
#include <climits>
#include "Queue.h"
using namespace std;

// Definicao do struct Node
struct Node {
    int key;       // guarda inteiro (chave)
    Node *next;    // ponteiro para proximo no
};

Queue::Queue() {       // Construtor
    first = last = nullptr;
}/*L\pauseL*/

Queue::~Queue () {     // Destrutor
    while (first != nullptr) {
        Node *aux = first;
        first = first->next;
        cout << "Removendo chave " << aux->key << endl;
        delete aux;
    }
    first = last = nullptr;
}

/** 
 * Devolve 'true' se a lista estiver vazia e 
 * devolve 'false' caso contrario
 */
bool Queue::empty() { /*L\pauseL*/
    return (first == nullptr);
}

/**
 * A funcao 'enqueue' insere um novo elemento na fila
 * Cada novo elemento eh inserido no final da fila
 */
void Queue::enqueue(int key) { /*L\pauseL*/
    Node *novo = new Node;
    novo->key = key;
    novo->next = nullptr;  // novo node passa a ser o ultimo /*L\pauseL*/
    if (last != nullptr) // verifica se fila nao estava vazia
        last->next = novo;
    else    // fila estava vazia
        first = novo;
    last = novo;
}

/**
 * Funcao 'dequeue'. Retorna o ultimo elemento da fila
 * ou retorna INT_MIN se a fila estiver vazia.
 */
int Queue::dequeue() { /*L\pauseL*/
    if (empty()) {
        cout << ">> erro: fila vazia" << endl;
        return INT_MIN;
    } /*L\pauseL*/
    int key = first->key;
    Node *aux = first;
    first = aux->next;
    // verifica se a fila ficou vazia
    if (first == nullptr) 
        last = nullptr;
    delete aux;
    return key;
}

/** 
 * Devolve o valor inteiro do elemento que esta 
 * na cabeca da lista. O primeiro elemento. 
 * Note que esta operacao nao remove o elemento,
 * apenas devolve o seu valor.
 */
int Queue::head() { /*L\pauseL*/
    if (first != nullptr)
        return first->key;
    
    cout << ">> erro: fila vazia" << endl;
    return INT_MIN;
}

/** 
 * Devolve o valor inteiro do elemento que esta 
 * na cauda da lista. O ultimo elemento. 
 * Note que esta operacao nao remove o elemento,
 * apenas devolve o seu valor.
 */
int Queue::tail() { /*L\pauseL*/
    if (last != nullptr)
        return last->key;
    
    cout << ">> erro: fila vazia" << endl;
    return INT_MIN;
}

