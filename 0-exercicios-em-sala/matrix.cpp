#include <iostream>
using namespace std;//sdsd

void receber(int **matrix, int nlinhas, int ncolunas){
    for(int i=0; i < nlinhas; i++){
        for(int j=0; j < ncolunas; j++){
            cin >> matrix[i][j];
        }
    }
}
void imprimir(int **matrix, int nlinhas, int ncolunas){
    for(int i=0; i < nlinhas; i++){
        for(int j=0; j < ncolunas; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int nlinhas = 2, ncolunas = 3;
    int **matrix = new (nothrow) int*[nlinhas];
    for(int i=0; i < 2; i++){
        matrix[i] = new (nothrow) int[ncolunas];
    }
    receber(matrix, nlinhas, ncolunas);
    imprimir(matrix, nlinhas, ncolunas);
    for(int i=0; i < ncolunas; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}