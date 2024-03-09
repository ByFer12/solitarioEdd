#include "Pila.h"

#include <iostream>
using namespace std;
Pila::Pila() : primero(nullptr) {}

/**
 * Destruye la pila por ser dinamica necesita un destructor
 */
Pila::~Pila() {
    while (primero != nullptr) {
        NodoPila* temp = primero;
        primero = primero->siguiente;
        delete temp;
    }
}
/**
 * Inserta un nuevo nodo con su elemento
 */
void Pila::push(const Carta& carta) {
    NodoPila* nuevo = new NodoPila(carta);
    nuevo->siguiente = primero;
    primero = nuevo;
}
/**
 * Este mtodo para eliminar un nodo de la pila y retorna el elemento eliminado
 */

Carta Pila::pop() {
    if (primero != nullptr) {
        Carta carta = primero->carta;
        NodoPila* temp = primero;
        primero = primero->siguiente;
        delete temp;
        return carta;
    } else {
        cout << "La pila esta vacia..." << endl;
    }
}

bool Pila::estaVacia() const { return primero == nullptr; }
/**
 * Mostrar elementos
 */
string Pila::mostrarDatos() const {
    string datos;
    if (primero != nullptr) {
        NodoPila* nodos = primero;
        while (nodos != nullptr) {
            /* code */
            datos += nodos->carta.obtenerCarta();
            nodos = nodos->siguiente;
        }
    }

    return datos;
}