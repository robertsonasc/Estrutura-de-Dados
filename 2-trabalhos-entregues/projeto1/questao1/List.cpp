//Robertson Nascimento - 391242
//Clerton Filho - 397271
#include <iostream>
#include "List.h"
#include <climits>
using namespace std;

struct Node{
    Node *anterior;
    int key;
    Node *posterior;
};

List::List(){
    head = new (nothrow) Node;
    head->anterior = nullptr;
    head->posterior = nullptr;
    id_list = cont_list+1;
    cont_list++;
}

List::~List(){
    clear();
    delete head;
}

int List::getId(){
    return id_list;
}

int List::getContList(){
    return cont_list;
}

void List::setContList(int i){
    cont_list = i;
}

void List::push_back(int key){
    Node *novo = new Node;
    novo->key = key;
    if(head->posterior == nullptr){
        head->posterior = novo;
        novo->anterior = head;
        novo->posterior = head;
        head->anterior = novo;
    }else{
        novo->posterior = head;
        novo->anterior = head->anterior;
        head->anterior->posterior = novo;
        head->anterior = novo;
    }
}

int List::pop_back(){
    if(empty()){
        cout << "Lista vazia. Nada para imprimir." << endl;
        return INT_MIN;
    }else{
        int res = 0;
        if(size() == 1){
            res = head->posterior->key;
            delete head->posterior;
            head->anterior = nullptr;
            head->posterior = nullptr;
        }else{
            Node *aux = head->anterior;
            res = aux->key;
            aux->anterior->posterior = head;
            head->anterior = aux->anterior;
            delete aux;
        }
        return res;
    }
} 
void List::insertAfter(int key, int k){
    if(empty())
        cout << "Lista vazia. Impossível realizar operação." << endl;
    else{
        int cont = 1, i = 0;
        for(Node *aux = head->posterior; i < size(); aux = aux->posterior, cont++, i++){
            if(cont == k){
                Node *novo = new Node;
                novo->key = key;
                novo->anterior = aux;
                novo->posterior = aux->posterior;
                aux->posterior = novo;
                novo->posterior->anterior = novo;
                cout << "Inteiro " << key << " inserido após a posição " << k << " com sucesso." << endl;
                return;
            }
        }
        cout << "Erro: Posição informada é inválida." << endl;
    }
}
void List::removeNode(Node *p){
    if(size() == 1){
        delete p;
        head->posterior = nullptr;
        head->anterior = nullptr;
    }else{
        int i = 0;
        for(Node *aux = head->posterior; i < size(); aux = aux->posterior, i++){
            if(aux == p){
                aux->anterior->posterior = aux->posterior;
                aux->posterior->anterior = aux->anterior;
                delete aux;
            }
        }
    }
    
}
void List::remove(int key){
    if(empty()){
        cout << "Lista vazia. Impossível realizar operação." << endl;
        return;
    }
    if(size() == 1 && head->posterior->key == key){
        delete head->posterior;
        cout << "O inteiro " << key << " foi removido da lista com sucesso." << endl;
        head->posterior = nullptr;
        head->anterior = nullptr;
        return;
    }else{
        int i = 0;
        for(Node *aux = head->posterior; i < size(); aux = aux->posterior, i++){
            if(aux->key == key){
                removeNode(aux);
                cout << "O inteiro " << key << " foi removida da lista com sucesso " << endl;
                return;
            }
        }
    }
    cout << "Erro: Remoção não realizada, o inteiro " << key << " não está na lista." << endl;
}
void List::removeAll(int key){
    if(empty()){
        cout << "Lista vazia. Impossível realizar operação." << endl;
        return;
    }
    bool controle = false;
    if(size() == 1 && head->posterior->key == key){
        delete head->posterior;
        head->posterior = nullptr;
        head->anterior = nullptr;
        return;
    }else{
        for(Node *aux = head->posterior; aux->posterior != head; aux = aux->posterior){
            if(aux->key == key){
                controle = true;
                removeNode(aux);
            }
        }
        if(head->anterior->key == key){
            controle = true;
            removeNode(head->anterior);
        }
    }
    if(controle == true) {
        cout << "Remoção(ões) realizada(s) com sucesso." << endl;
    }else{
        cout << "Erro: Remoção não realizada, o inteiro " << key << " não está na lista." << endl;
    }
}
int List::removeNodeAt(int k){
    if(empty()){
        cout << "Lista vazia. Impossível realizar operação." << endl;
        return INT_MAX;
    }
    if(size() == 1 && k == 1){
        int valor = head->posterior->key;
        delete head->posterior;
        head->posterior = nullptr;
        head->anterior = nullptr;
        return valor;
    }
    int i = 0, cont = 1;
    for(Node *aux = head->posterior; i < size(); aux = aux->posterior, i++, cont++){
        if(cont == k){
            int valor = aux->key;
            aux->anterior->posterior = aux->posterior;
            aux->posterior->anterior = aux->anterior;
            delete aux;
            return valor;
        }
    }
    return INT_MIN;
}
void List::print(){
    if(empty()){
        cout << "Lista vazia. Nada para imprimir." << endl;
    }else{
        cout << "[ ";
        for(Node *aux = head->posterior; aux->posterior != head; aux = aux->posterior){
            cout << aux->key << " ";
        }
        cout << head->anterior->key << " ";
        cout << "]" << endl;
    }
}
void List::printReverse(){
    if(empty()){
        cout << "Lista vazia. Nada para imprimir." << endl;
    }else{
        cout << "[ ";
        for(Node *aux = head->anterior; aux->anterior != head; aux = aux->anterior){
            cout << aux->key << " ";
        }
        cout << head->posterior->key << " ";
        cout << "]" << endl;
    }
}
bool List::empty(){
    return (head->posterior == nullptr);
}

int List::size(){
    if(!empty()){
        int cont = 1;
        for(Node *aux = head->posterior; aux->posterior != head; aux = aux->posterior){
            cont++;
        }
        return cont;
    }
    return 0;
}
void List::clear(){
    if(!empty()){
        while(size() > 0){
            removeNodeAt(size());
        }
    }
}
void List::concat(List *lst){
    if(lst->empty()){
        cout << "Nada feito, lista passada para ser contatenada com a principal é vazia." << endl;
    }else{
        int tam_inicial = lst->size();
        for(Node *aux = lst->head->posterior; tam_inicial > 0; aux = aux->posterior, tam_inicial--){
            push_back(lst->removeNodeAt(1));
        }
        cout << "Listas concatenadas com sucesso." << endl;
    }
}
List * List::copy(){
    List *nova = new List();
    if(empty()){
        nova->head->posterior = nullptr;
        nova->head->anterior = nullptr;
        return nova;
    }
    int i = 0;
    for(Node *aux = head->posterior; i < size(); aux = aux->posterior, i++){
        nova->push_back(aux->key);
    }
    return nova;
}
void List::copyArray(int n, int arr[]){
    for(int i=0; i < n; i++){
        push_back(arr[i]);
    }
    cout << "Os elementos do vetor foram adicionados com sucesso na parte final da lista." << endl;
}
bool List::equal(List *lst){
    if(size() == lst->size()){
        bool controle = true;
        int i = 0;
        for(Node *aux = head->posterior, *aux2 = lst->head->posterior; i < size(); aux = aux->posterior, aux2 = aux2->posterior, i++){
            if(aux->key != aux2->key)
                controle = false;
        }
        if(controle == true)
            return true;
    }
    return false;
}
List * List::separate(int n){
    if(empty()){
        cout << "Lista vazia, nada para dividir." << endl;
    }else{
        int i = 0, cont = 1;
        for(Node *aux = head->posterior; i < size(); aux = aux->posterior, i++, cont++){
            if(aux->key == n){
                int vezes = size() - cont;
                List *nova = new List();
                while(vezes > 0){
                    nova->push_back(removeNodeAt(cont+1));
                    vezes--;
                }
                return nova;
            }
        }
    }
    return nullptr;
}
List * List::merge_lists(List *lst){
    List *nova = new List();
    int i = 0;
    if(size() == lst->size()){
        for(Node *aux = head->posterior, *aux2 = lst->head->posterior; i < size(); aux = aux->posterior, aux2 = aux2->posterior, i++){
            nova->push_back(aux->key);
            nova->push_back(aux2->key);
        }
    }else if(size() > lst->size()){
        for(Node *aux = head->posterior, *aux2 = lst->head->posterior; i < size(); aux = aux->posterior, aux2 = aux2->posterior, i++){
            nova->push_back(aux->key);
            if(i < lst->size())
                nova->push_back(aux2->key);
        }
    }else{
        for(Node *aux = head->posterior, *aux2 = lst->head->posterior; i < lst->size(); aux = aux->posterior, aux2 = aux2->posterior, i++){
            if(i < size())
                nova->push_back(aux->key);
            nova->push_back(aux2->key);
        }
    }
    lst->clear();
    return nova;
}
Node * List::ponteiroPos(int pos){
    if(empty()){
        cout << "Lista vazia. Impossível realizar operação." << endl;
    }else{
        int cont = 1, i = 0;
        for(Node *aux = head->posterior; i < size(); aux = aux->posterior, cont++, i++){
            if(cont == pos){
                return aux;
            }
        }
    }
    return nullptr;
}