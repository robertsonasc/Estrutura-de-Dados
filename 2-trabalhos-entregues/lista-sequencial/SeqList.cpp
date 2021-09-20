#include <iostream>
#include "SeqList.h"
#include <climits>
#include <string>
using std::cout;
using std::cin;
using std::endl;

// Construtor supõe que n > 0
SeqList::SeqList(int n) {
    size_vec = 0;
    capacity_vec = n;
    vec = new (std::nothrow) int[n];
    if (vec == nullptr) {
        cout << "Memoria insuficiente" << endl;
        exit(1);
    }
}

// Destrutor
SeqList::~SeqList() {
    if(vec != nullptr) {
        delete[] vec;
        cout << "Lista liberada" << endl;
    }
}

// Recebe um inteiro x e o adiciona ao final da lista
bool SeqList::add(int x) {
    if( ! full() ) {
        vec[size_vec] = x;
        size_vec++;
        return true;
    }
    else return false;
}

// Retorna true se lista cheia e false caso contrario
bool SeqList::full() {
    return (size_vec == capacity_vec);
}

// Busca x e retorna indice se x estiver no vetor
// senao, retorna -1
int SeqList::search(int x) {
    for(int i = 0; i < size_vec; i++) {
        if(vec[i] == x)
            return i;
    }
    return -1;
} 

// Remove o primeiro x da lista
void SeqList::remove(int x) {
    int index = search(x);
    if(index > -1) { 
        vec[index] = vec[size_vec-1];
        size_vec--;
    }
} 

// ########################## %% #######################

// Retorna tamanho da lista
int SeqList::size(){
        return size_vec;
}

// Apos essa operacao, a lista fica vazia, ou seja,
// a lista fica com 0 elementos.
void SeqList::clear(){
    delete[] vec;
    size_vec = 0;
}

// Imprime todos os elementos da lista em uma unica linha.
void SeqList::print(){
    for(int i=0; i < size_vec; i++){
        cout << vec[i] << " ";
    }
}

// Retorna o elemento na posicao 'index'
// Se 'index' estiver fora do intervalo valido, a 
// operacao retorna o menor inteiro que uma variavel 
// inteira pode armazenar.
// Dica 1: o menor inteiro pode ser obtido usando a 
// constante simbolica INT_MIN que esta definida na 
// biblioteca <climits>
int SeqList::at(int index){
    if(index >= 0 && index < size_vec) return vec[index];
    else return INT_MIN;
}

// Adiciona o elemento x na posicao 'index' 
// (somente se 0 <= index <= size_vec && size_vec < max_vec)
// Ao fazer isso, todos os elementos da posicao 
// 'index' em diante são deslocados para a direita
bool SeqList::insertAt(int x, int index){
    if(0 <= index && index <= size_vec && size_vec < capacity_vec){
        for(int i=size_vec-1; i >= index; i--){
            vec[i+1] = vec[i]; 
        }
        vec[index] = x;
        size_vec++;
        return true;
    }
    return false;
}

// Troca o elemento na posicao 'index' pelo elemento x
// (somente se 0 <= index <= size_vec-1)
bool SeqList::replaceAt(int x, int index){
    if(0 <= index && index <= size_vec-1){
        vec[index] = x;
        return true;
    }
    return false;
}

// Remove o elemento na posicao k da lista
// Deve-se ter 0 <= k <= size_vec-1; caso contrario,
// a remocao nao sera realizada
void SeqList::removeAt(int k){
    if(0 <= k && k <= size_vec-1){
        for(int i=k; i < size_vec-1; i++){
            vec[i] = vec[i+1];
        }
        size_vec--;
    }
}

// Remove todas as ocorrencias do elemento x na lista
void SeqList::removeAll(int x){
    for(int i=0; i < size_vec; i++){
        if(vec[i] == x){
            removeAt(i);
        }
    }
}

// Retorna os elementos da lista no formato de uma std::string
// Dica: a fim de formar a string que sera retornada, 
// use a função std::to_string() que recebe
// um inteiro como argumento e retorna esse inteiro
// no formato de uma std::string
std::string SeqList:: toString(){
    if(size_vec > 0){
        std::string s = "[";
        s += std::to_string(vec[0]);
        for(int i=1; i < size_vec; i++){
            s += ", ";
            s += std::to_string(vec[i]);
            
        }
        s += "]";
        return s;
    }
    std::string s = "Lista vazia.";
    return s;
}
