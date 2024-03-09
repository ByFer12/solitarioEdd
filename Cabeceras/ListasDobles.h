
#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <iostream>

#include "Carta.h"
struct NodoLista {
    Carta carta;
    NodoLista* siguiente;
    NodoLista* anterior;
    NodoLista(const Carta& carta);
};

class ListaDobleEnlazada {
   public:
    ListaDobleEnlazada();

    void insertarAlInicio(const Carta& carta);
    void eliminarAlInicio();
    string mostrar() const;

   private:
    NodoLista* primero;
    NodoLista* ultimo;
};

#endif