//Robertson Nascimento - 391242
#include <iostream>
#include "BinaryTree.h"
//#include <windows.h> Descomentar essa linha caso for compilar em windows.

using namespace std;

int main(){
    //SetConsoleOutputCP(CP_UTF8); Descomentar essa linha caso for compilar em windows.
    Node *n1 = bt_create(4, nullptr, nullptr);
    Node *n2 = bt_create(7, nullptr, nullptr);
    Node *n3 = bt_create(6, n1, n2);
    Node *n4 = bt_create(1, nullptr, nullptr);
    Node *n5 = bt_create(3, n4, n3);

    Node *n6 = bt_create(13, nullptr, nullptr);
    Node *n7 = bt_create(14, n6, nullptr);
    Node *n8 = bt_create(10, nullptr, n7);
    Node *raiz  = bt_create(8, n5, n8);

    Node *backup = bt_copia(raiz);

    cout << "Quantidade de folhas na arvore inicial: " << num_folhas(raiz) << endl;
    
    Node *copia = bt_copia(raiz);
    cout << "Imprimindo a cópia da arvore inicial: " << endl; 
    bt_print(copia); 

    cout << "Quantidade de nós com apenas um filho na arvore inicial: " << bt_um_filho(raiz) << endl;

    cout << "Quantidade de nós na arvore inical: " << bt_numNos_iterativo(raiz) << endl;

    cout << "Apagando as folhas da arvore inicial." << endl; 
    apaga_folhas(raiz);

    cout << "Comparando a arvore inicial (sem folhas), com a arvore copiada anteriormente (com folhas): "; 
    if(bt_identicas(raiz, copia))
        cout << "São iguais." << endl;
    else
        cout << "São diferentes." << endl;

    cout << "Por fim, comparando a arvore cópia, com um backup da arvore inical (feito no começo do programa): ";
    if(bt_identicas(copia, backup))
        cout << "São iguais." << endl;
    else
        cout << "São diferentes." << endl;

    return 0;
}
