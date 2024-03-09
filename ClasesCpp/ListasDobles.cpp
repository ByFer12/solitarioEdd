#include "ListasDobles.h"
using namespace std;

NodoLista::NodoLista(const Carta& carta) : carta(carta), siguiente(nullptr), anterior(nullptr) {}

ListaDobleEnlazada::ListaDobleEnlazada() : primero(nullptr), ultimo(nullptr) {}

void ListaDobleEnlazada::insertarAlInicio(const Carta& carta) {
    NodoLista* nuevoNodo = new NodoLista(carta);
    if (primero == nullptr) {
        primero = ultimo = nuevoNodo;
    } else {
        nuevoNodo->siguiente = primero;
        primero->anterior = nuevoNodo;
        primero = nuevoNodo;
    }
}

void ListaDobleEnlazada::eliminarAlInicio() {
    if (primero != nullptr) {
        NodoLista* temp = primero;
        if (primero == ultimo) {
            primero = ultimo = nullptr;
        } else {
            primero = primero->siguiente;
            primero->anterior = nullptr;
        }
        delete temp;
    } else {
        cout << "La lista esta vacia" << endl;
    }
}

string ListaDobleEnlazada::mostrar() const {
    string dato;
    NodoLista* actual = primero;
    while (actual != nullptr) {
        dato += actual->carta.obtenerCarta();
        actual = actual->siguiente;
    }
    return dato;
}