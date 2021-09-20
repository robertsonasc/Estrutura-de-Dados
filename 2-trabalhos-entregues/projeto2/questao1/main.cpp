//Robertson Nascimento - 391242
#include <iostream>
#include <string>
#include "List.h"
//#include <windows.h> Descomentar essa linha caso for compilar em windows.
#include <climits>
using namespace std;

//Retorna o indice da lista referente a posição informada pelo usuário. Retorna o menor inteiro possível se não existir lista na posição informada.
int contem(List *listas[], int posicao){
    for(int i=0; i < List::getContList(); i++){
        if(listas[i]->getId() == posicao)
            return i;
    }
    return INT_MIN;
}
int main(){
    //SetConsoleOutputCP(CP_UTF8); Descomentar essa linha caso for compilar em windows.
    int vetsize = 10; // vetsize é a capacidade de listas que o programa suporta.
    List *banco_de_listas[vetsize];
    int opcao;
    while(opcao != 21){
        string menu;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "Total de listas ativas: " << List::getContList() << endl;
        for(int i=0; i < List::getContList(); i++){
                cout << "Lista "<< i+1 << ": "; 
                banco_de_listas[i]->print();
        }
        menu += "##################### ListasListamenteListadas #####################\n";
        
        menu += "Digite uns dos comandos a seguir para realizar a tarefa desejada: \n\n";
        menu += " 1    |   Para criar uma lista circular duplamente encadeada (ficará salva enquanto o programa está ativo).\n";
        menu += " 2    |   Para deletar uma lista.\n";
        menu += " 3    |   Para inserir um inteiro ao final de uma lista.\n";
        menu += " 4    |   Para remover um inteiro ao final de uma lista e retornar seu valor.\n";
        menu += " 5    |   Para inserir um novo nó (com um inteiro) em uma lista, passando o indice do nó que será o seu anterior.\n";
        menu += " 6    |   Para remover um nó de uma lista passando o ponteiro que aponta para esse nó.\n";
        menu += " 7    |   Para remover o primeiro nó de uma lista que contem um determinado inteiro.\n";
        menu += " 8    |   Para remover da lista todos os nós que contem um determinado inteiro.\n";
        menu += " 9    |   Para remover um nó da lista, passando seu indice.\n";
        menu += " 10   |   Para mostrar na tela uma determinada lista.\n";
        menu += " 11   |   Para mostrar uma lista de trás pra frente.\n";
        menu += " 12   |   Para saber se uma lista está vazia ou não.\n";
        menu += " 13   |   Para saber quantos nós há em uma lista.\n";
        menu += " 14   |   Para excluir todos os nós válidos (deixar apenas o nó cabeça) de uma lista.\n";
        menu += " 15   |   Para juntar uma lista a outra, a lista secundaria ficará vazia.\n";
        menu += " 16   |   Para criar cópia de uma lista.\n";
        menu += " 17   |   Para copiar os inteiros de um vetor em uma lista (devem ser adicionados no final da lista).\n";
        menu += " 18   |   Para saber de uma lista é igual a outra.\n";
        menu += " 19   |   Para dividir uma lista em duas.\n";
        menu += " 20   |   Para misturar duas listas, ao final, a lista secundária ficará vazia.\n";
        menu += " 21   |   Para fechar o programa (todas as listas serão perdidas).\n\n";
        cout << menu;
        cin >> opcao;
        
        switch(opcao){
            case 1:{
                List *nova_lista = new (nothrow) List();
                if(nova_lista != nullptr && nova_lista->getId() <= vetsize){
                    banco_de_listas[nova_lista->getId()-1] = nova_lista;
                    cout << "Lista criada e salva com sucesso." << endl;
                }else{
                    delete nova_lista;
                    List::setContList(List::getContList()-1);
                    cout << "Lista não criada: Excedida a capacidade de listas que podem ser criadas." << endl;
                }
                break;
            }
            case 2:{
                cout << "Informe a colocação da lista que deve ser excluida (se deseja excluir a primeira lista digite 1, se deseja excluir a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    delete banco_de_listas[i];
                    for(int j=i+1; j < List::getContList(); j++)
                        banco_de_listas[j-1] = banco_de_listas[j];
                    cout << "Lista " << pos << " deletada com sucesso." << endl;
                    List::setContList(List::getContList()-1);
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 3:{
                cout << "Em qual lista será feita a operação? (Se for na primeira lista digite 1, se for na segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Infome qual inteiro deseja inserir na lista:" << endl;
                    int n = 0;
                    cin >> n;
                    banco_de_listas[i]->push_back(n);
                    cout << "Inteiro inserido com sucesso." << endl;
                    break;     
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 4:{
                cout << "Em qual lista será feita a operação? (Se for na primeira lista digite 1, se for na segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "O inteiro " << banco_de_listas[i]->pop_back() << " foi retirado do final da lista informada." << endl;
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 5:{
                cout << "Em qual lista será feita a operação? (Se for na primeira lista digite 1, se for na segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Informe respectivamente o inteiro e a posição (>=1) que deseja ser a anterior a dele na lista:" << endl;
                    int n = 0, po = 0;
                    cin >> n >> po;
                    banco_de_listas[i]->insertAfter(n, po);
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 6:{
                cout << "Em qual lista será feita a operação? (Se for na primeira lista digite 1, se for na segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Infome qual a posição (>= 1) do nó que deseja ser deletado:" << endl;
                    int po = 0;
                    cin >> po;
                    Node *aux = banco_de_listas[i]->ponteiroPos(po);
                    if(aux != nullptr) {
                        banco_de_listas[i]->removeNode(aux);
                        cout << "Nó removido com sucesso." << endl;
                        break;
                    }else{
                        cout << "Erro: Remoção não realizada, posição informada é inválida." << endl;
                        break;
                    }
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 7:{
                cout << "Em qual lista será feita a operação? (Se for na primeira lista digite 1, se for na segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Informe um número inteiro que deseja remover da lista sua primera ocorrência:" << endl;
                    int n = 0;
                    cin >> n;
                    banco_de_listas[i]->remove(n);
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 8:{
                cout << "Em qual lista será feita a operação? (Se for na primeira lista digite 1, se for na segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Informe um número inteiro que deseja exterminar (remover todas as ocorrências) da lista:" << endl;
                    int n = 0;
                    cin >> n;
                    banco_de_listas[i]->removeAll(n);
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 9:{
                cout << "Em qual lista será feita a operação? (Se for na primeira lista digite 1, se for na segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Informe a posição (>= 1) do nó na lista que deseja apagá-lo e saber seu valor:" << endl;
                    int po = 0;
                    cin >> po;
                    int valor = banco_de_listas[i]->removeNodeAt(po);
                    if(valor != INT_MIN){
                        cout << "Nó apagado com sucesso." << endl;
                        cout << "O inteiro " << valor << " estava nesse nó." << endl;
                        break;
                    }else if(valor == INT_MAX){
                        break;
                    }else{
                        cout << "Erro: Nó não encontrado na lista, a posição informada não existe." << endl;
                        break;
                    }
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 10:{
                cout << "A qual lista você se refere? (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    banco_de_listas[i]->print();
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 11:{
                cout << "A qual lista você se refere? (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    banco_de_listas[i]->printReverse();
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 12:{
                cout << "A qual lista você se refere? (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    if(banco_de_listas[i]->empty()){
                        cout << "A lista informada está vazia." << endl;
                        break;
                    }else{
                        cout << "A lista informada NÃO está vazia." << endl;
                        break;
                    }
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 13:{
                cout << "A qual lista você se refere? (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "O lista informada tem tamanho: " << banco_de_listas[i]->size() << endl;
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 14:{
                cout << "A qual lista você se refere? (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    banco_de_listas[i]->clear();
                    cout << "A lista foi limpa com sucesso." << endl;
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 15:{
                cout << "Qual será a lista principal nessa operação? (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Informe a lista que deseja ser concatenada com a lista principal (Se for na primeira lista digite 1, se for na segunda lista digite 2...):" << endl;
                    int po = 0;
                    cin >> po;
                    po = contem(banco_de_listas, po);
                    if(po >= 0){
                        banco_de_listas[i]->concat(banco_de_listas[po]);
                        break;
                    }
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 16:{
                cout << "De qual lista você deseja fazer uma cópia? (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    List *nova_lista = banco_de_listas[i]->copy();
                    if(nova_lista != nullptr && nova_lista->getId() <= vetsize){
                        banco_de_listas[nova_lista->getId()-1] = nova_lista;
                        cout << "Cópia da lista criada e salva na ultima colocação das listas." << endl;
                    }else{
                        delete nova_lista;
                        List::setContList(List::getContList()-1);
                        cout << "Erro: Cópia da lista não criada, excedida a capacidade de listas que podem ser criadas." << endl;
                    }
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;
            }
            case 17:{
                cout << "Em qual lista deseja inserir os elementos do vetor? (Se for na primeira lista digite 1, se for na segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Informe o tamanho do vetor:" << endl;
                    int tam = 0;
                    cin >> tam;
                    int vet[tam];
                    cout << "Preencha o vetor:" << endl;
                    for(int i2=0; i2 < tam; i2++)
                        cin >> vet[i2];
                    banco_de_listas[i]->copyArray(tam, vet);
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break;    
            }
            case 18:{
                cout << "Informe uma das lista que deseja comparar (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Informe a outra lista para fazermos a comparação (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                    int po = 0;
                    cin >> po;
                    int l2 = contem(banco_de_listas, po);
                    if(l2 >= 0){
                        if(banco_de_listas[i]->equal(banco_de_listas[l2])){
                            cout << "Listas iguais." << endl;
                            break;
                        }else{
                            cout << "Listas diferentes." << endl;
                            break;
                        }
                    }
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break; 
            }
            case 19:{
                cout << "A qual lista você se refere? (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Informe o número inteiro que está na lista e será o ponto de divisão dessa lista em duas:" << endl; 
                    int div = 0;
                    cin >> div;
                    List *sublist = banco_de_listas[i]->separate(div);
                    if(sublist != nullptr && sublist->getId() <= vetsize){
                        banco_de_listas[sublist->getId()-1] = sublist;
                        cout << "Sublista criada e salva na ultima colocação das listas." << endl;
                        break;
                    }
                    if(sublist == nullptr){
                        cout << "O inteiro " << div << " não está contido na lista." << endl;
                        break;
                    } 
                    if(!sublist->getId() <= vetsize){
                        delete sublist;
                        List::setContList(List::getContList()-1);
                        cout << "Sublista não criada: Excedida a capacidade de listas que podem ser criadas." << endl;
                    }
                    break;
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break; 
            }
            case 20:{
                cout << "A qual lista você se refere? (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                int pos = 0;
                cin >> pos;
                int i = contem(banco_de_listas, pos);
                if(i >= 0){
                    cout << "Qual lista deseja juntar alternadamente com a primeira lista? (Se for a primeira lista digite 1, se for a segunda lista digite 2...):" << endl;
                    int po = 0;
                    cin >> po;
                    int j = contem(banco_de_listas, po);
                    if(j >= 0){
                        List * nova = banco_de_listas[i]->merge_lists(banco_de_listas[j]);
                        banco_de_listas[nova->getId()-1] = nova;
                        cout << "Lista ""merge"" criada com sucesso e salva na última colocação das listas." << endl;
                        break;
                    }
                }
                cout << "Erro: A lista que você informou não existe." << endl;
                break; 
            }
            case 21:{
                for(int i=0; i < List::getContList(); i++){
                    banco_de_listas[i]->clear();
                    delete banco_de_listas[i];
                }
                cout << "Listas apagadas com sucesso. O progroma irá fechar..." << endl;
                break;
            }
            default:
                cout << "Opção inválida." << endl;
                break;
        }
    }
    return 0;
}