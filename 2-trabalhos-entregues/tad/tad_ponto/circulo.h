#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>
#include <cmath>
#include "Ponto2.h"

class Circulo {
    private:
        Ponto centro;
        double raio;
    
    public:
        //Cria o circulo.
        Circulo(double r, Ponto pc);

        //Atribui um novo valor ao raio do circulo.
        void setRaio(double r);

        //Atribui novo valor à coordenada x
        void setX(float v);

        //Atribui novo valor à coordenada y
        void setY(float v);

        //Obtém o raio.
        float getRaio();

        //Obtém o centro.
        Ponto getCentro();

        //Calcula a área do círculo.
        float area();

        //Verifica se o Ponto p está dentro do círculo.
        bool interior(Ponto p);

        //Libera memória alocada, se for necessário.
        ~Circulo();
};
#endif