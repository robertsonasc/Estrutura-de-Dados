//Clerton Filho - 397271
//Robertson Nascimento - 391242
#include <iostream>
#include "Conjunto.h"
//#include <Windows.h> Se for compilar no Windows, descomentar essa linha

using namespace std;

struct Elemento{
  int unidadeConj;
};
//---------------------------------------MENU---------------------------------------
int main(){
  //SetConsoleOutputCP(CP_UTF8); Se for compilar no Windows, descomentar essa linha
  int opcao;
  int contConjuntos = 0;
  int tam = 20;
  Conjunto *bancoConjuntos[tam];
  while(opcao != 13){
    string menu;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Total de Conjuntos ativos: " << contConjuntos << endl;
    for(int i=0; i < contConjuntos; i++){
      cout << "Conjunto " << i+1 << ": ";
      for(int j=0; j < bancoConjuntos[i]->getTamanho(); j++){
        Elemento e = bancoConjuntos[i]->getElementoVetor(j);
        cout << e.unidadeConj << " ";
      }
      cout << endl;  
    }

    menu += "Digite uns dos comandos a seguir para realizar a tarefa desejada: \n\n";
    menu += " 1    |   Para criar um conjunto.\n";
    menu += " 2    |   Para deletar um conjunto.\n";
    menu += " 3    |   Para inserir um elemento em um conjunto.\n"; 
    menu += " 4    |   Para criar um conjunto uniao de dois conjunto existentes e salva-lo no final da nossa lista de conjuntos. C (C = A ∪ B).\n";
    menu += " 5    |   Para criar uma copia de um conjunto e salva-la no final da nossa lista de conjuntos.\n";
    menu += " 6    |   Para criar um conjunto da intersecção de dois conjuntos existentes e salva-lo no final da lista de conjuntos.  (C = A ∩ B).\n";
    menu += " 7    |   Para criar um conjunto da diferença entre dois conjuntos existentes e salva-lo no final da lista de conjuntos.\n";
    menu += " 8    |   Para criar um conjunto da diferença simetrica entre dois conjuntos existentes e salva-lo no final da lista de conjuntos.\n";
    menu += " 9    |   Para remover um elemento de um conjunto existente.\n";
    menu += " 10   |   Para retornar o valor maximo de um conjunto.\n";
    menu += " 11   |   Para retornar o valor minimo de um conjunto.\n";
    menu += " 12   |   Para retornar verdadeiro se um conjuntos for igual a outro, falso caso contrario.\n";
    menu += " 13   |   Para fechar o programa.\n\n";
    cout << menu;
    cin >> opcao;

    switch(opcao){
      case 1:{
        if(contConjuntos < tam){
          bancoConjuntos[contConjuntos] = new Conjunto(); 
          contConjuntos++;
          cout << "Conjunto criado com sucesso." << endl;
        }
        else{
          cout << "Conjunto não criado, capacidade para criar novos conjuntos excedida." << endl;
        }
        break;
      }
      case 2:{
        cout << "Informe qual conjunto você deseja excluir: " << endl;
        int number; 
        cin >> number;

        if(number > 0 && number <= contConjuntos){
          delete bancoConjuntos[number-1];
          for(int i=number-1+1; i < contConjuntos; i++){
            bancoConjuntos[i-1] = bancoConjuntos[i];
          }
          contConjuntos--;
          cout << "Conjunto deletado com sucesso." << endl;
        }
        else{
          cout << "O conjunto informado nao existe." << endl;
        }
        break;
      }
      case 3:{
        cout << "Informe em qual conjunto deseja fazer a insercao do elemento:" << endl;
        int number;
        cin >> number;
        if(number > 0 && number <= contConjuntos){
          cout << "Informe o elemento que deseja inserir no conjunto:" << endl;
          int elem;
          cin >> elem;
          Elemento e;
          e.unidadeConj = elem;
          if(bancoConjuntos[number-1]->insere(e)){
            cout << "Elemento inserido com sucesso." << endl;
            break;
          }
          else{
            cout << "Impossivel realizar insercao, o elemento já esta no conjunto." << endl;
            break;
          }
        }
        else{
          cout << "O conjunto informado nao existe." << endl;
        }
        break;
      }
      case 4:{
        cout << "Informe respectivamente dois conjuntos que deseja realizar a uniao entre eles:" << endl;
        int c1, c2;
        cin >> c1 >> c2;
        if(c1 > 0 && c2 > 0 && c1 <= contConjuntos && c2 <= contConjuntos){
          if(contConjuntos < tam){
            bancoConjuntos[contConjuntos] = new Conjunto();
            contConjuntos++;
            Conjunto::uniao(bancoConjuntos[c1-1], bancoConjuntos[c2-1], bancoConjuntos[contConjuntos-1]);
            cout << "Conjunto da uniao criado e salvo com sucesso." << endl;
          }
          else{
            cout << "Impossivel realizar uniao, capacidade de conjuntos que podem ser criados foi excedida." << endl;
          }          
          break;
        }
        else{
          cout <<"Erro: O Conjunto informado nao existe." << endl;
        }
        break;
      }
      case 5:{
        cout << "Informe qual conjunto deseja copiar:" << endl;
        int c;
        cin >> c;
        if(c > 0 && c <= contConjuntos){
          if(contConjuntos < tam){
            bancoConjuntos[contConjuntos] = new Conjunto();
            contConjuntos++;
            bancoConjuntos[c-1]->copia(bancoConjuntos[c-1], bancoConjuntos[contConjuntos-1]);
            cout << "Copia realizada com sucesso." << endl;
            break;
          }
          else{
            cout << "Impossivel realizar uniao, capacidade de conjuntos que podem ser criados excedida." << endl;
            break;
          }
        }
        else{
          cout << "O conjunto informado nao existe." << endl;
        }
        break;
      }
      case 6:{
        cout << "Informe respectivamente dois conjuntos que deseja criar o conjunto interseccao entre eles:" << endl;
        int c1, c2;
        cin >> c1 >> c2;
        if(c1 > 0 && c2 > 0 && c1 <= contConjuntos && c2 <= contConjuntos){
          if(contConjuntos < tam){
            bancoConjuntos[contConjuntos] = new Conjunto();
            contConjuntos++;
            Conjunto::interseccao(bancoConjuntos[c1-1], bancoConjuntos[c2-1], bancoConjuntos[contConjuntos-1]);
            cout << "Conjunto da interseccao criado e salvo com sucesso." << endl;
          }
          else{
            cout << "Impossivel realizar interseccao, capacidade de conjuntos que podem ser criados foi excedida." << endl;
          }          
          break;
        }
        else{
          cout << "Erro: O conjunto informado nao existe." << endl;
        }
        break;
      }
      case 7:{
        cout << "Informe respectivamente dois conjuntos que deseja criar o conjunto da diferenca entre eles:" << endl;
        int c1, c2;
        cin >> c1 >> c2;
        if(c1 > 0 && c2 > 0 && c1 <= contConjuntos && c2 <= contConjuntos){
          if(contConjuntos < tam){
            bancoConjuntos[contConjuntos] = new Conjunto();
            contConjuntos++;
            Conjunto::diferenca(bancoConjuntos[c1-1], bancoConjuntos[c2-1], bancoConjuntos[contConjuntos-1]);
            cout << "Conjunto da diferenca criado e salvo com sucesso." << endl;
          }
          else{
            cout << "Impossivel realizar diferenca, capacidade de conjuntos que podem ser criados foi excedida." << endl;
          }          
          break;
        }
        else{
          cout << "Erro: O Conjunto informado nao existe." << endl;
        }
        break;
      }
      case 8:{
        cout << "Informe respectivamente os conjuntos que deseja criar o conjunto da diferenca simetrica entre eles:" << endl;
        int c1, c2;
        cin >> c1 >> c2;
        if(c1 > 0 && c2 > 0 && c1 <= contConjuntos && c2 <= contConjuntos){
          if(contConjuntos < tam){
            bancoConjuntos[contConjuntos] = new Conjunto();
            contConjuntos++;
            Conjunto::diferencaSimetrica(bancoConjuntos[c1-1], bancoConjuntos[c2-1], bancoConjuntos[contConjuntos-1]);
            cout << "Conjunto da diferenca simetrica criado e salvo com sucesso." << endl;
          }
          else{
            cout << "Impossivel realizar diferenca simetrica, capacidade de conjuntos que podem ser criados foi excedida." << endl;
          }          
          break;
        }
        else{
          cout << "Erro: O Conjunto informado nao existe." << endl;
        }
        break;
      }
      case 9:{
        cout << "Informe de qual conjunto deseja remover um elemento:" << endl;
        int c;
        cin >> c;
        if(c > 0 && c <= contConjuntos){
          cout << "Informe qual elemento deseja remover do conjunto:" << endl;
          int elem;
          cin >> elem;
          Elemento e;
          e.unidadeConj = elem;
          if(Conjunto::remove(e, bancoConjuntos[c-1]))
            cout << "Elemento removido com sucesso." << endl;
          else
            cout << "Remoçao nao realizada, o elemento informado nao esta no conjunto." << endl;
        }
        else{
          cout << "O conjunto informado nao existe." << endl;
        }
        break;
      }
      case 10:{
        cout << "Informe de qual conjunto deseja obter seu maior elemento:" << endl;
        int c;
        cin >> c;
        if(c > 0 && c <= contConjuntos){
          if(bancoConjuntos[c-1]->getTamanho() > 0){
            cout << "O maior elemento desse conjunto eh: " << Conjunto::max(bancoConjuntos[c-1]) << endl;
          }
          else{
            cout << "Este conjunto esta vazio." << endl;
          }
        }
        else{
          cout << "O conjunto informado nao existe." << endl;
        }
        break;
      }
      case 11:{
        cout << "Informe de qual conjunto deseja obter seu menor elemento:" << endl;
        int c;
        cin >> c;
        if(c > 0 && c <= contConjuntos){
          if(bancoConjuntos[c-1]->getTamanho() > 0){
            cout << "O menor elemento desse conjunto eh: " << Conjunto::min(bancoConjuntos[c-1]) << endl;
          }
          else{
            cout << "Este conjunto esta vazio." << endl;
          }
        }
        else{
          cout << "O conjunto informado nao existe." << endl;
        }
        break;
      }
      case 12:{
        cout << "Informe respectivamente dois conjuntos que deseja saber se são, ou não, iguais entre si:" << endl;
        int c1, c2;
        cin >> c1 >> c2;
        if(c1 > 0 && c2 > 0 && c1 <= contConjuntos && c2 <= contConjuntos){
          if(Conjunto::iguais(bancoConjuntos[c1-1], bancoConjuntos[c2-1]))
            cout << "Conjuntos iguais." << endl;
          else
            cout << "Conjuntos diferentes." << endl;
        }
        else{
          cout << "O conjunto informado não existe." << endl;
        }
        break;
      }
      case 13:{
        for(int i=0; i < contConjuntos; i++){
          delete bancoConjuntos[i];
        }
        cout << "Memorias desalocadas. Programa fechando." << endl;
        break;
      }
      default:
        cout << "Opção invalida" << endl; 
        break;
    } 
  }
  return 0;
}