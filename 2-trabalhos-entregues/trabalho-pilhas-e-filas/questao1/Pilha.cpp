//Robertson Nascimento - 391242
#include <iostream>
#include "Pilha.h"
using namespace std;

// construtor da pilha vazia
Pilha::Pilha(int *vec, bool cima){ //se cima = true, a pilha sera a de "cima do vetor", se for false, será a de baixo.
    if(cima == true){    
        posicao = true;
    }else {
        posicao = false;
    }
    top_cima = 0;
    top_baixo = 79;
    vet = vec;
}
Pilha::~Pilha(){
    delete vet;
}

// insere n no topo da pilha.
void Pilha::empilhar(int n){
    if((top_baixo - top_cima) > 1){
        if(posicao == true){
            vet[top_cima] = n;
            top_cima++;
        }else{
            vet[top_baixo] = n;
            top_baixo--;
        }
    }
}
//remove o elemento do topo da pilha.
//supondo que as pilhas já estejam preenchidas.
void Pilha::desempilhar(){
    if(posicao = true){
        top_cima--;
    }else{
        top_baixo++;
    }
}
//retorna o elemento do topo da pilha.
//supondo que as pilhas já estejam preenchidas.
int Pilha::consultarTopo(){
    if(posicao == true){
        return vet[top_cima-1];
    }else{
        return vet[top_baixo+1];
    }
} 
