#include <iostream>
#include <string.h>
using namespace std;

void ordena_v_dinam(char **vet, int qtd_strings){
    for(int i=0; i < qtd_strings-1; i++){
        for(int j=i+1; j < qtd_strings; j++){
            if(strcmp(vet[i], vet[j]) > 0){
                char *aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}
int main(){
    int qtd_strings = 0;
    cin >> qtd_strings;
    char **vet = new char*[qtd_strings];
    for(int i=0; i < qtd_strings; i++){
        int tam;
        cin >> tam;
        vet[i] = new char[tam+1];
        cin.ignore();
        cin.getline(vet[i], tam+1);
    }
    
    ordena_v_dinam(vet, qtd_strings);
    for(int i=0; i < qtd_strings; i++){
        cout << vet[i] << endl;
        delete[] vet[i];
    }
    delete[] vet;
    return 0;
}