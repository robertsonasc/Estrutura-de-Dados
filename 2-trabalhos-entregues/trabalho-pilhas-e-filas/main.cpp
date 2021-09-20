#include <iostream>
#include "Pilha.h"
using namespace std;

int main(){
    int *vet = new int[15];
    Pilha A = Pilha(vet, true);
    Pilha B = Pilha(vet, false);
    for(int i=1; i <= 5; i += 2){
        A.empilhar(i);
    }
    for(int i=0; i <=4; i += 2){
        B.empilhar(i);
    }  
    A.imprimirVetor();
    delete vet;
    return 0;
}