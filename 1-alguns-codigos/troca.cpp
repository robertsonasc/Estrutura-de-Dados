#include <iostream>
using namespace std;

void troca(int* n1, int* n2){
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}
int main(){
    int n1, n2;
    cin >> n1 >> n2;
    
    troca(&n1, &n2);
    cout << n1 << " " << n2;
    return 0;
}