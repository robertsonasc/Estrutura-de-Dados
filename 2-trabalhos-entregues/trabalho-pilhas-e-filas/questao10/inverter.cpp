//Robertson Nascimento - 391242
#include <iostream>
#include <string>
using namespace std;

//inverte uma string que sempre irá conter apenas uma palavra.
string inverte(string aux){
    if(aux.length() < 1) return " ";

    string aux2;
    for(int i=aux.length()-1; i >= 0; i--){
        aux2 += aux.at(i);
    }
    aux2 += " ";
    return aux2;
}
int main(){
    string s;
    getline(cin, s);
    string result;
    string aux;
    for(int i=0; i < s.length(); i++){
        if(s.at(i) != ' '){
            aux += s.at(i);
        }else{
            result += inverte(aux);
            aux.clear();
        }
    }
    result += inverte(aux);
    cout << result;
    return 0;
}