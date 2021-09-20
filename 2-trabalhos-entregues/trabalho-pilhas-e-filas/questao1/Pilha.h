//Robertson Nascimento - 391242
#ifndef PILHA_H
#define PILHA_H
#include <iostream>

class Pilha{
//Lembrando que me refiro a cima ou baixo no vetor, de acordo com a figura apresentada na questão.
//Outra coisa importante é que essa classe foi projetada para conter apenas DUAS pilhas por vêz dentro de um vetor,
//não mais do que isso.
            

    int top_cima; //Tamanho da pilha que está em cima no vetor.
    int top_baixo; //Tamanho da pilha que está em baixo no vetor.
    
    private:
        int *vet = nullptr;//vet irá apontar para um vetor que é alocado dinamicamente na main.
        bool posicao; // nos diz se a pilha é a de cima (true) ou a de baixo (false) no vetor.
    
    public:
        Pilha(int *vec, bool cima); // construtor da pilha vazia, recebe o vetor alocado dinamicamente na main, 
        //e cima (true se a pilha ficará em cima, false se a pilha ficará em baixo).
        
        void empilhar(int n);// insere n no topo da pilha.
        void desempilhar(); //remove o elemento do topo da pilha.
        int consultarTopo(); //retorna o elemento do topo da pilha.
        ~Pilha(); //Destrutor, desaloca tudo que foi alocado dinamicamente.
};
#endif