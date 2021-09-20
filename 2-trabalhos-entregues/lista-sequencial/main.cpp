#include <iostream>
#include "SeqList.h"
using namespace std;

int main() {
    cout << "Digite a capacidade da lista:" << endl;
    int cap=0;
    cin >> cap;
    SeqList lista(cap);
    for(int i=2; !lista.full(); i+=2){
        lista.add(i);
    }
    cout << "Lista ""aleatória"" criada com sucesso." << endl;

    cout << "Informe um elemento que deseja saber se o mesmo se encontra na lista:" << endl;
    int elem=0;
    cin >> elem;
    cout << "Seu elemento informado é esse: " << lista.at(lista.search(elem)) << ". Se sim, ele pertence a lista, caso contrário ele não se encontra na lista." << endl;

    cout << "Todos os elementos que estão na lista são: ";
    lista.print();
    cout << endl;

    cout << "Essa lista contem um total de " << lista.size() << " elementos." << endl;
    cout << "Informe um elemento que deseja remover da lista:" << endl;
    int rem;
    cin >> rem;
    lista.remove(rem);
    cout << "Se o elemento está contido na lista ele foi removido. Caso não esteja contido, não foi removido" << endl;
    
    cout << "Agora digite um elemento que deseja inserir na lista, seguido do indice de onde deseja colocar esse elemento." << endl;
    int elem1=0, ind=0;
    cin >> elem1 >> ind;
    if(lista.insertAt(elem1, ind)){
        cout << "O elemento " << elem1 << " foi inserido na lista." << " Ele foi inserido no indice: " << ind << endl;
    }else 
        cout << "Elemento não inserido pois a lista está cheia." << endl;

    cout << "Informe um elemento que deseja inserir para substituir um que já está inserido na lista: " << endl;
    int elem2=0;
    cin >> elem2;

    cout << "Agora nos diga qual indice da lista que deseja fazer a substituição:" << endl;
    int ind2=0;
    cin >> ind2;

    if(lista.replaceAt(elem2, ind2))
        cout << "Elemento substituido com sucesso." << endl;

    else{
        cout << "Erro na substuição. Lista inalterada." << endl;
    }

    cout << "Desta vez você vai informar um indice de um elemento que deseja remover da lista:" << endl;
    int ind3=0;
    cin >> ind3;
    lista.removeAt(ind3);
    cout << "Se vc informou um indice condido na lista, o elemento que se encontrava nesse indice foi removido. Caso contrário não houve remoção." << endl;

    cout << "Ufa, ta acabando, só nos informe um elemento que deseja exterminar da lista:" << endl;
    int elem3=0;
    cin >> elem3;

    lista.removeAll(elem3);
    cout << "Se existia algum elemento igual ao que você informou contido na lista, ele disse tchau. Caso contrário, a lista permanece a mesma." << endl;

    cout << "Por último vamos mostrar para você como a lista ficou:" << endl;
    cout << lista.toString() << endl;

    lista.clear();



    return 0;
}