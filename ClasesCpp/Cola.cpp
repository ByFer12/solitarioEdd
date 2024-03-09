#include "Cola.h"

#include <iostream>
using namespace std;
Cola::Cola() : primero(nullptr), ultimo(nullptr) {}
Cola::~Cola() {
    while (primero != nullptr) {
        eliminarElementoCola();
    }
}
void Cola::insertarCola(const Carta &carta) {
    NodoCola *nuevoNodo = new NodoCola(carta);
    if (primero == nullptr) {
        primero = ultimo = nuevoNodo;
    } else {
        ultimo->siguiente = nuevoNodo;
        ultimo = nuevoNodo;
    }
}

bool Cola::estaVacia() const { return primero == nullptr; }

Carta Cola::eliminarElementoCola() {
    if (primero != nullptr) {
        Carta carta = primero->carta;
        NodoCola *temp = primero;
        primero = primero->siguiente;
        if (primero == nullptr) {
            ultimo = nullptr;
        }
        delete temp;
        return carta;
    } else {
        throw std::runtime_error("La cola está vacía");
    }
}

int Cola::tamanio() const {
    int tam = 0;
    NodoCola *actual = primero;
    while (actual != nullptr) {
        tam++;
        actual = actual->siguiente;
    }

    return tam;
}

string Cola::mostrarValores() const {
    string dato;
    if (primero == nullptr) {
    } else {
        NodoCola *actual = primero;
        while (actual != nullptr) {
            dato += actual->carta.obtenerCarta();
            actual = actual->siguiente;
        }
    }
    return dato;
}