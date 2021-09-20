#include <iostream>
using namespace std;

struct Ponto{
    double x;
    double y;
};
void troca(Ponto *p1, Ponto *p2){
    Ponto aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}
void dobra(Ponto *p1){
    p1->x *= 2;
    p1->y *= 2;
}
int main(){
    Ponto zidane = {5.2, 4.3};
    Ponto materazi = {5.1, 4.2};
    //troca(&zidane, &materazi);
    dobra(&zidane);
    cout << zidane.x << " " << zidane.y << endl;
    //cout << materazi.x << " " << materazi.y  << endl;
    return 0;
}