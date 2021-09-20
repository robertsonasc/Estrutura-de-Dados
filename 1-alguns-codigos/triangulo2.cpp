#include <iostream>
using namespace std;

int recur(int **vet, int n, int linha, int coluna){
    if(coluna == 1){
        return vet[linha][0] + vet[linha+1][0];                                                                                                                                         
    }
    vet[linha][coluna] = recur(vet, vet[linha][coluna-1], linha, coluna-1) + 
            recur(vet, vet[linha+1][coluna-1], linha+1, coluna-1);
    
    return vet[linha][coluna];
}
int main(){
    int size;
    cin >> size;
    int **vet = new int*[sizeof(int)];
    for(int i=0; i < size; i++)
        cin >> vet[i][0];

    recur(vet, vet[0][size-1], 0, size-1);

    cout << vet[0][0] << " " << vet[0][1] << " " << vet[0][2] << endl;
    cout << vet[1][0] << " " << vet[1][1] << endl;
    cout << vet[2][0];
    delete[] vet;
    return 0;
}