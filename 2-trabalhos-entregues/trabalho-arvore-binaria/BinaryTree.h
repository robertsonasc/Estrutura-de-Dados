//Robertson Nascimento - 391242
#ifndef ARVOREBIN_H
#define ARVOREBIN_H

struct Node; // Cada no eh do tipo Node

Node* bt_emptyTree(); // retorna nulo, indicando arvore vazia

// cria no com chave 'key'
Node* bt_create(int key, Node* l, Node* r); 

// arvore enraizada em no esta vazia?
bool bt_empty(Node* node); 

void bt_print(Node* node); // imprime as chaves da arvore

bool bt_contains(Node* node, int key); // essa chave pertence?

Node* bt_destroy(Node* node); // libera todos os nos alocados

int num_folhas(Node * node); //Retorna o a quantidade de folhas que a arvore com raiz em "node" contem.

Node * apaga_folhas(Node * node); //Apaga todas as folhas de uma arvore.

Node* bt_copia(Node *root); //Retorna uma cópia da arvore com raiz em root.

int bt_um_filho(Node *root); //Retornar a quantidade de nós de uma arvore que possuem apenas um filho.

int bt_numNos_iterativo(Node *no); //Calcula de maneira iterativa o número de nós de uma arvore binária com raiz em "no".

bool bt_identicas(Node *a1, Node *a2); //devolve true se elas forem idênticas; e false, caso contrário.

#endif
