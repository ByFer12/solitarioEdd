#include "Carta.h"

#include <string>

using namespace std;

Carta::Carta(char valor, const string& palo, char color) : valor(valor), palo(palo), color(color) {}

string Carta::obtenerCarta() { return valor + palo + color + " "; }

char Carta::obtenerValor() { return valor; }

string Carta::obtenerPalo() { return palo; }

char Carta::obtenerColor() { return color; }