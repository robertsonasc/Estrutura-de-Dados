/**
 * Definicao da classe SeqList 
 * Essa classe corresponde a uma lista sequencial 
 * implementada como um array, cuja capacidade total 
 * deve ser definida pelo usuario no momento da 
 * criacao de um objeto do tipo SeqList.
 */
#ifndef SEQLIST_H
#define SEQLIST_H
#include <iostream>

class SeqList {
    private:
        int *vec = NULL; // Vetor de inteiros
        int size_vec = 0; // Qtd de elementos no vetor
        int capacity_vec = 0; // Capacidade total do vetor
    public:
        // --- Construtor
        // Recebe como parametro a capacidade total da lista 
        SeqList(int n); 

        // --- Destrutor
        // Libera a memoria alocada para a lista
        ~SeqList();

        // --- size
        // Retorna tamanho da lista
        int size();

        // --- full
        // Retorna 'true' se a lista estiver cheia e 
        // 'false' caso contrario.
        // USEI
        bool full();

        // --- clear 
        // Apos essa operacao, a lista fica vazia, ou seja,
        // a lista fica com 0 elementos.
        void clear();

        // --- print
        // Imprime todos os elementos da lista em uma unica linha.
        void print();

        // --- search
        // Busca o elemento x na lista e retorna o 
        // indice da primeira ocorrencia de x 
        // caso ele esteja presente na lista; ou retorna -1,
        // caso o elemento x nao esteja presente na lista 
        int search(int x); 

        // --- at
        // Retorna o elemento na posicao 'index'
        // Se 'index' estiver fora do intervalo valido, a 
        // operacao retorna o menor inteiro que uma variavel 
        // inteira pode armazenar.
        // Dica 1: o menor inteiro pode ser obtido usando a 
        // constante simbolica INT_MAX que esta definida na 
        // biblioteca <climits>
        int at(int index);

        // --- add
        // Recebe um inteiro x como argumento e
        // adiciona o inteiro x logo apos o ultimo elemento 
        // da lista. Retorna 'true' se for bem sucedido, 
        // ou 'false' caso contrario.
        // (Note que nenhum elemento deve ser adicionado se
        // a lista estiver cheia).
        bool add(int x);

        // --- remove
        // Remove a primeira ocorrencia do elemento x no QX_SeqList 
        void remove(int x);

        // --- insertAt
        // Adiciona o elemento x na posicao 'index' 
        // (somente se 0 <= index <= size_vec && size_vec < max_vec)
        // Ao fazer isso, todos os elementos da posicao 
        // 'index' em diante são deslocados para a direita
        bool insertAt(int x, int index);

        // --- replaceAt
        // Troca o elemento na posicao 'index' pelo elemento x
        // (somente se 0 <= index <= size_vec-1)
        bool replaceAt(int x, int index);

        // --- removeAt
        // Remove o elemento na posicao k da lista
        // Deve-se ter 0 <= k <= size_vex-1; caso contrario,
        // a remocao nao sera realizada
        void removeAt(int k);

        // --- removeAll
        // Remove todas as ocorrencias do elemento x na lista
        void removeAll(int x);

        // --- toString
        // Retorna os elementos da lista no formato de uma std::string
        // Dica: a fim de formar a string que sera retornada, 
        // use a função std::to_string() que recebe
        // um inteiro como argumento e retorna esse inteiro
        // no formato de uma std::string
        std::string toString();
};

#endif