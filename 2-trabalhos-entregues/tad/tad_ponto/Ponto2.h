#ifndef PONTO_H
#define PONTO_H
#include <iostream>
#include <cmath>

class Ponto {
    private:
        double x;
        double y;
    public:
        //Construtor padrão.
        Ponto(){
            x = 0;
            y = 0;
        };
        // Construtor
        Ponto(double X, double Y) {
            x = X;
            y = Y;
        }

        // Destrutor
        ~Ponto() {
            //std::cout << "Ponto destruido" << std::endl; 
        }

        // Getters
        double getX() { return x; }
        double getY() { return y; } 

        // Setters
        void setX(double X) { x = X; }
        void setY(double Y) { y = Y; }

        double distancia(Ponto p) {
            double dx = x - p.x;
            double dy = y - p.y;
            return sqrt(dx*dx + dy*dy);
        }
};

#endif