#ifndef CARTA_H
#define CARTA_H
#include <string>
using namespace std;

class Carta {
   public:
    Carta(char valor, const string& palo, char color);

    string obtenerCarta();
    char obtenerValor();
    string obtenerPalo();
    char obtenerColor();

   private:
    char valor;
    string palo;
    char color;
};

#endif