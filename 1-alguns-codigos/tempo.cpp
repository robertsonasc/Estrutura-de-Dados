#include <iostream>
using namespace std;

void converte_tempo(int* horas, int* minutos, int* segundos){
    *minutos = (*segundos)/60;
    *segundos %= 60;

    *horas = *minutos/60;
    *minutos %= 60;
}
int main(){
    int segundos = 0, horas = 0, minutos = 0;
    cin >> segundos;

    converte_tempo(&horas, &minutos, &segundos);
    cout << horas << ":" << minutos << ":" << segundos;
    return 0;
};