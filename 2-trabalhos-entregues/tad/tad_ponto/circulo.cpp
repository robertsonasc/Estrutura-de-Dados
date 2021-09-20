#include <iostream>
#include "circulo.h"
#include "Ponto2.h"
using namespace std;

//Cria o circulo.
Circulo::Circulo(double r, Ponto pc){
    raio = r;
    centro.setX(pc.getX());
    centro.setY(pc.getY());
}
//Atribui um novo valor ao raio do circulo.
void Circulo::setRaio(double r){
    raio = r;
}
//Atribui novo valor à coordenada x
void Circulo::setX(float v){
    centro.setX(v);
}
//Atribui novo valor à coordenada y
void Circulo::setY(float v){
    centro.setY(v);
}
//Obtém o raio.
float Circulo::getRaio(){
    return raio;
} 
//Obtém o centro.
Ponto Circulo::getCentro(){
    return centro;
}
//Calcula a área do círculo.
float Circulo::area(){
    return M_PI * (raio * raio);
}
//Verifica se o Ponto p está dentro do círculo.
bool Circulo::interior(Ponto p){
    double distan = centro.distancia(p);
    if(raio >= distan)
        return true;
    return false;
}
//Libera memória alocada, se for necessário.
Circulo::~Circulo(){
}
