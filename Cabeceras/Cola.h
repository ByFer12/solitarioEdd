#ifndef COLA_H
#define COLA_H

#include "Carta.h"

struct NodoCola {
    Carta carta;
    NodoCola* siguiente;
    NodoCola(const Carta& carta) : carta(carta), siguiente(nullptr) {}
};

class Cola {
   public:
    Cola();
    ~Cola();

    void insertarCola(const Carta& carta);
    Carta eliminarElementoCola();
    bool estaVacia() const;
    int tamanio() const;
    string mostrarValores() const;

   private:
    NodoCola* primero;
    NodoCola* ultimo;
};

#endif