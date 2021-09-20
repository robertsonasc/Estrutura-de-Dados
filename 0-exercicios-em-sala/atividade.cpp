#include <iostream>
using namespace std;

void preencheArray(int *ponteiro_dinamico, int size){
    for(int i=0; i < size; i++){
        cin >> *(ponteiro_dinamico+i);
    }
}
void imprimeArray(int *ponteiro_dinamico, int size){
    for(int i=0; i < size; i++)
        cout << ponteiro_dinamico[i] << " ";
}
int main(){
    int size = 0;
    cin >> size;
    int *ponteiro_dinamico = new int[size];
    preencheArray(ponteiro_dinamico, size);
    imprimeArray(ponteiro_dinamico, size);
    
    delete[] ponteiro_dinamico;
    ponteiro_dinamico = NULL;
    
    cout << endl;
    return 0;
}