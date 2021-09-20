#include <iostream>
#include "Ponto2.h"
#include "circulo.h"
using namespace std;

int main() {
    double x = 0, y = 0, raio = 0;
    cout << "X do ponto no centro do circulo:" << endl;
    cin >> x;
    cout << "Y do ponto no centro do circulo:" << endl;
    cin >> y;
    cout << "Raio:" << endl;
    cin >> raio;

    Ponto p = Ponto(x, y);
    Circulo c = Circulo(raio, p);
    cout << "..." << endl << "Seu circulo foi criado com sucesso." << endl;
    cout << "A área do seu circulo: " << c.area() << endl;

    cout << "Agora informe x e y respectivamente de um ponto que você deseja saber se está no circulo:" << endl;
    cin >> x >> y;
    Ponto p2 = Ponto(x, y);
    if(c.interior(p2)){
        cout << "O ponto informado está sim dentro do circulo. =)" << endl;
    }
    else
        cout << "O ponto informado se encontra fora do circulo." << endl;
    
    
    return 0;
}