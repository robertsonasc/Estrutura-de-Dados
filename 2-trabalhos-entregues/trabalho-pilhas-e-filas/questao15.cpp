#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    stack<char> pilha;
    
    int cont=0;
    for(int i=0; s.at(i) == 'A' || s.at(i) == 'B'; i++){
        pilha.push(s.at(i));
        cont++;
    }
    cout << cont << endl;
    bool pertence = true;
    char vet[cont];
    for(int i=0; i < cont; i++, pilha.pop())
        vet[i] = pilha.top();

    for(int i=s.length()-1, j=0; cont > 0;cont--, i--, j++){
        if(s.at(i) != vet[j])
            pertence = false;
    }
    if(pertence == true){
        cout << "A frase informada EH DO TIPO xCy." << endl;
    }else{
        cout << "A frase informada NAO EH DO TIPO xCy." << endl;
    }

    return 0;
}