//Clerton Filho - 397271
//Robertson Nascimento - 391242

#include <iostream>
#include "Conjunto.h"
 
using namespace std;

struct Elemento{
  int unidadeConj;
};

Conjunto::Conjunto(){
  vetor[tamanho] = nullptr;
}

Conjunto::~Conjunto(){
  for(int i=0; i < tamanho; i++)
    delete vetor[i];
}

bool Conjunto::insere(Elemento x){
  bool b = true;
  for(int i=0; i < tamanho; i++){
    if(x.unidadeConj == (*vetor[i]).unidadeConj){
      b = false;
    }
  }
  if(b == false || tamanho == capacidade-1){
    return false;
  }
  vetor[tamanho] = new Elemento;
  *vetor[tamanho] = x;
  tamanho++;
  return true;
  
}

void Conjunto::uniao(Conjunto *A, Conjunto *B, Conjunto *C){
  A->copia(A, C);
  for(int i=0; i < B->getTamanho(); i++){
    C->insere(B->getElementoVetor(i));
  }
}

void Conjunto::interseccao(Conjunto *A, Conjunto *B, Conjunto *C){
  for(int i=0; i < A->getTamanho(); i++){
    if(membro(A->getElementoVetor(i), B)){
      C->insere(A->getElementoVetor(i));
    }
  }
}

void Conjunto::diferenca(Conjunto *A, Conjunto *B, Conjunto *C){
  for(int i=0; i < A->getTamanho(); i++){
    if(!membro(A->getElementoVetor(i), B))
      C->insere(A->getElementoVetor(i));
  }
}
void Conjunto::diferencaSimetrica(Conjunto *A, Conjunto *B, Conjunto *C){
  diferenca(A, B, C);
  diferenca(B, A, C);
}

bool Conjunto::remove(Elemento x, Conjunto *A){
  if(membro(x, A))
    for(int i=0; i < A->getTamanho(); i++){
      if(x.unidadeConj == A->getElementoVetor(i).unidadeConj){
        delete A->vetor[i];
        for(int j=i+1; j < A->getTamanho(); j++){
          A->vetor[j-1] = A->vetor[j];
        }
        A->tamanho--; 
        return true;
      }
    }
  return false;
}

int Conjunto::max(Conjunto *A){
  int ma = A->getElementoVetor(0).unidadeConj;
  for(int i=1; i < A->getTamanho(); i++){
    if(ma < A->getElementoVetor(i).unidadeConj)
      ma = A->getElementoVetor(i).unidadeConj;
  }
  return ma;
}

int Conjunto::min(Conjunto *A){
  int mi = A->getElementoVetor(0).unidadeConj;
  for(int i=1; i < A->getTamanho(); i++){
    if(mi > A->getElementoVetor(i).unidadeConj)
      mi = A->getElementoVetor(i).unidadeConj;
  }
  return mi;
}

bool Conjunto::iguais(Conjunto *A, Conjunto *B){
  if(A->getTamanho() == B->getTamanho()){
    bool b = true;
    for(int i=0; i < A->getTamanho(); i++){
      if(!membro(A->getElementoVetor(i), B))
        b = false;
    }
    return b;
  }
  return false;
}

bool Conjunto::membro(Elemento y, Conjunto *A){
  bool b = false;
  for(int i=0; i < A->getTamanho(); i++){
    if(y.unidadeConj == A->getElementoVetor(i).unidadeConj)
      b = true;
  }
  return b;
}

void Conjunto::copia(Conjunto *A, Conjunto *B){
  for(int i=0; i < A->getTamanho(); i++){
    B->insere(A->getElementoVetor(i));
  }
}

int Conjunto::getTamanho(){
  return tamanho;
}

Elemento Conjunto::getElementoVetor(int i){
  return *vetor[i];
}

