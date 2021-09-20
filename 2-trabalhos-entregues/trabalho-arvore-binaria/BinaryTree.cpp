/**Robertson Nascimento - 391242
 * Implementacao de uma arvore binaria
 */
#include <iostream>
#include <stack>
#include "BinaryTree.h"

using std::cout;
using std::endl;
using std::stack;

struct Node { // sem ponteiro para no pai
    int key;
    Node *left; // subarvore esquerda
    Node *right; // subarvore direita
};

Node* bt_emptyTree() {
    return nullptr;
}

Node* bt_create(int key, Node* l, Node* r) {
    Node* novo = new Node{};
    novo->key = key;
    novo->left = l;
    novo->right = r;
    return novo;
}

bool bt_empty(Node* node) {
    return (node == nullptr);
}

void bt_print(Node* node) {
    if ( ! bt_empty(node) ) {
        cout << node->key << endl;
        bt_print(node->left);
        bt_print(node->right);
    }
}

bool bt_contains(Node* node, int key) {
    if (node == nullptr) 
        return false; // Sub-arvore vazia 
    else 
        return node->key == key || 
               bt_contains(node->left, key) || 
               bt_contains(node->right, key);
}

Node* bt_destroy(Node* node) {
    if (node != nullptr) {
        node->left = bt_destroy(node->left);
        node->right = bt_destroy(node->right);
        cout << "Deleting " << node->key << endl;
        delete node;
    }
    return nullptr;
}

int num_folhas(Node * node){
    if(node != nullptr){
        if(bt_empty(node->left) && bt_empty(node->right))
            return 1;
        return num_folhas(node->left) + num_folhas(node->right);
    }else
        return 0;    
}

Node * apaga_folhas(Node * node){
    if(node != nullptr){
        if(bt_empty(node->left) && bt_empty(node->right)){
            delete node;
            return nullptr;
        }else{
           node->left = apaga_folhas(node->left);
           node->right = apaga_folhas(node->right);
           return node;
        }
        
    }
    return nullptr;
}

Node* bt_copia(Node *root){
    if(root != nullptr)
        return bt_create(root->key, bt_copia(root->left), bt_copia(root->right));

    return nullptr;
}

int bt_um_filho(Node *root){
    if(root != nullptr){
        if(bt_empty(root->left) && !bt_empty(root->right))
            return 1 + bt_um_filho(root->right);
        
        if(!bt_empty(root->left) && bt_empty(root->right))
            return 1 + bt_um_filho(root->left);
            
        return bt_um_filho(root->right) + bt_um_filho(root->left);
    }
    return 0;    
}

int bt_numNos_iterativo(Node *no){
    stack<Node*> pilha;
    int cont = 0;
    if(no != nullptr){
        pilha.push(no);
        cont++;
        while(!pilha.empty()){
            no = pilha.top();
            pilha.pop();
            if(no->left != nullptr){
                cont++;
                pilha.push(no->left);
            }
            if(no->right != nullptr){
                cont++;
                pilha.push(no->right);
            }
        }
    }
    return cont;
}

bool bt_identicas(Node *a1, Node *a2){
    stack<Node*> pilha1;
    stack<Node*> pilha2;
    bool iguais = true;
    if(a1 != nullptr && a2 != nullptr){
        pilha1.push(a1);
        pilha2.push(a2);
        while(!pilha1.empty() && !pilha2.empty()){
            a1 = pilha1.top();
            pilha1.pop();
            a2 = pilha2.top();
            pilha2.pop();
            if(a1->key != a2->key)
                return false;
            
            if(a1->left != nullptr){
                pilha1.push(a1->left);
            }
            if(a1->right != nullptr){
                pilha1.push(a1->right);
            }
            if(a2->left != nullptr){
                pilha2.push(a2->left);
            }
            if(a2->right != nullptr){
                pilha2.push(a2->right);
            }
        }
    }
    else if(a1 == nullptr && a2 == nullptr)
        return true;
    return iguais;   
}