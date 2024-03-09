
#ifndef PILA_H
#define PILA_H
#include "Carta.h"

struct NodoPila {
    Carta carta;
    NodoPila* siguiente;
    NodoPila(const Carta& carta) : carta(carta), siguiente(nullptr) {}
};

class Pila {
   public:
    Pila();   // constructr
    ~Pila();  // destructor

    void push(const Carta& carta);
    Carta pop();
    bool estaVacia() const;
    string mostrarDatos() const;

   private:
    NodoPila* primero;
};

#endif