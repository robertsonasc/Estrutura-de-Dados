//Robertson Nascimento - 391242
#include <iostream>
#include "List.h"
#include <Windows.h> //Comente essa linha se for compilar em windows...

using namespace std;

int main() { 
    SetConsoleOutputCP(CP_UTF8); //Comente essa linha se for compilar em windows...
    List *lista1 = new List();
    cout << "Com quantos elementos sua lista começará?" << endl;
    int tam;
    cin >> tam;
    cout << "Informe os elementos:" << endl;
    for(int i=0; i < tam; i++){
        int n;
        cin >> n; 
        lista1->add(n); 
    }
    int x, pos;
    cout << "Informe um elemento que deseja exterminar da lista:" << endl;
    cin >> x;
    lista1->removeAll(x);

    cout << "Lista atualizada: ";
    lista1->print();
    cout << "Informe a posição (>=1) de um elemento que deseja remover da lista:" << endl;
    cin >> x;
    cout << "O elemento informado foi esse? >> " << lista1->removeNodeAt(x) << ". Se sim, ele foi removido, se não, ele não foi removido." << endl;

    cout << "Lista atualizada: ";
    lista1->print();
    cout << "Informe um elemento a ser inserido e a posição anterior a que deseja ser a dele:" << endl;
    cin >> x >> pos;
    lista1->insertAfter(x, pos);
    
    List *lista2 = lista1->copy();
    cout << "Criamos uma cópia da lista." << endl;
    cout << "Cópia da lista: ";
    lista2->print();
    

    cout << "Informe o tamanho de um vetor que servirá para preencher a lista:" << endl;
    cin >> x;
    int vet[x];
    cout << "Informe os elementos do vetor:" << endl;
    for(int i=0; i < x; i++)
        cin >> vet[i];
    
    lista1->copyArray(vet, x);

    cout << "Estamos testando se a nova list, essa referente ao vetor, é igual a cópia da lista anterior." << endl;
    if(lista1->equal(lista2))
        cout << "Listas iguáis." << endl;
    else
        cout << "Listas diferentes." << endl;
    
    
    lista1->concatenate(lista2);
    cout << "Concatenamos a lista cópia no final da lista atualizada com os valores do vetor." << endl;
    cout << "Lista atualizada: ";
    lista1->print();

    lista1->reverse();
    cout << "Revertemos os valores da lista de trás para frente." << endl;
    cout << "Lista final: ";
    lista1->print();
    delete lista1;
    delete lista2;
    return 0;
}
