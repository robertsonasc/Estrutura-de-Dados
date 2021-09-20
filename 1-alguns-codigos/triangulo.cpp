#include <iostream>
using namespace std;

int main(){
    int size = 0;
    cin >> size;
    int *matriz_linhas[size];
    for(int i=0; i < size; i++){
        int vet[size-i];
        if(i == 0)
            for(int j=0; j < size; j++)
                cin >> vet[j];
        else{
            for(int j=0; j < (size-i); j++){
                vet[j] =  matriz_linhas[i-1][j] + matriz_linhas[i-1][j+1];
            }
        }        
        matriz_linhas[i] = vet;
    }
    for(int i=size-1; i >= 0; i--){
        cout << "[";
        for(int j=0; j < size-i; j++){
            if(j == 0)
                cout << matriz_linhas[i][j];
            else{
                cout << ", " << matriz_linhas[i][j];
            }
        }
        cout << "]" << endl;
    }
    
    return 0;
}