#include <chrono>
#include <iostream>
#include <random>
#include <string>

#include "Carta.h"
#include "Cola.h"
#include "ListasDobles.h"
#include "Pila.h"

using namespace std;
string palos[] = {"<3", "E3", "!!", "<>"};
char valores[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
char color;
Cola cola1;
Cola cola2;
ListaDobleEnlazada lista1;
ListaDobleEnlazada lista2;
ListaDobleEnlazada lista3;
ListaDobleEnlazada lista4;
ListaDobleEnlazada lista5;
ListaDobleEnlazada lista6;
ListaDobleEnlazada lista7;
Pila mazo;
Pila pila1;
Pila pila2;
Pila pila3;
Pila pila4;
string nombre;

const int FILAS = 24;
const int COLUMNAS = 3;
string tablero[FILAS][COLUMNAS];

void insertarMazo();
void barajarCartas(Pila&);
void insertarEnCola(Pila&, int);
string obtenerCartasOcultas();
void moverCola1ACols2();
void devolverCartas();
void tableroJuego();
void llenarListas();
void moverCartas();
void menu();
int main() {
    cout << "Escribe tu nombre: ";
    cin >> nombre;
    insertarMazo();
    llenarListas();
    tableroJuego();
    menu();
    return 0;
}

void menu() {
    char opcion, op2;

    char decir = 's';
    while (decir == 's' || decir == 'S') {
        cout << "Jugador:" << nombre << endl;
        cout << "Escribe a donde quiere moverse: ";
        cin >> opcion >> op2;
        if (opcion == 'A' && op2 == 'B') {
            moverCola1ACols2();
            tableroJuego();
        } else if (opcion == 'B' && op2 == 'C') {
            Carta carta = cola2.eliminarElementoCola();
            if (pila1.estaVacia()) {
                if (carta.obtenerPalo() == "<3" && carta.obtenerValor() == 'A') {
                    pila1.push(carta);
                } else {
                    cout << "No es su palo o no es As" << endl;
                }
            } else {
                if (carta.obtenerPalo() == "<3" && carta.obtenerValor() >= '2') {
                    pila1.push(carta);
                } else {
                    cout << "No es su palo o no es mayor a 2" << endl;
                }
            }
                }

        if (cola1.estaVacia()) {
            devolverCartas();
            tableroJuego();
        }
        cout << "Desea seguir moviendo?(s/n): ";
        cin >> decir;
    }
}

void insertarMazo() {
    for (char valor : valores) {
        for (string palo : palos) {
            if (palo == "<3" || palo == "<>") {
                color = 'R';
            } else {
                color = 'N';
            }
            Carta carta(valor, palo, color);
            mazo.push(carta);
        }
    }

    cout << "Barajando" << endl;
    barajarCartas(mazo);
}

void barajarCartas(Pila& mazo) {
    // Obtener todas las cartas de la pila y almacenarlas en un vector
    vector<Carta> cartas;
    while (!mazo.estaVacia()) {
        cartas.push_back(mazo.pop());
    }

    // Para el generador de números aleatorios
    std::srand(std::time(nullptr));

    // Barajar las cartas en el vector intercambiando posiciones de forma aleatoria
    int n = cartas.size();
    for (int i = 0; i < n; ++i) {
        // Generar un índice aleatorio entre 0 y n-1
        int j = std::rand() % n;

        // Intercambiar la carta en la posición i con la carta en la posición j
        std::swap(cartas[i], cartas[j]);
    }

    // Insertar las cartas barajadas de vuelta en la pila
    for (const auto& carta : cartas) {
        mazo.push(carta);
    }
    cout << "Cartas barajados..." << endl;
    insertarEnCola(mazo, 24);
}

/**
 * Inserta la pila mazo a la cola principal
 */
void insertarEnCola(Pila& mazo, int cantidad) {
    // Transferir cartas de la pila "mazo" a la cola1
    for (int i = 0; i < cantidad; ++i) {
        if (!mazo.estaVacia()) {
            Carta carta = mazo.pop();
            cola1.insertarCola(carta);
        } else {
            break;  // La pila "mazo" está vacía
        }
    }
}
string obtenerCartasOcultas() {
    string datos;
    int tm = 0;
    while (tm < cola1.tamanio()) {
        datos += "[##] ";
        tm++;
    }
    return datos;
}
/**
 * Imprime el juego visual
 */
void tableroJuego() {
    string cartasOcultas = obtenerCartasOcultas();
    string colados = cola2.mostrarValores();
    string list1 = lista1.mostrar();
    string list2 = lista2.mostrar();
    string list3 = lista3.mostrar();
    string list4 = lista4.mostrar();
    string list5 = lista5.mostrar();
    string list6 = lista6.mostrar();
    string list7 = lista7.mostrar();
    string pil1 = pila1.mostrarDatos();
    string pil2 = pila2.mostrarDatos();
    string pil3 = pila3.mostrarDatos();
    string pil4 = pila4.mostrarDatos();
    cout << "A  " << cartasOcultas << endl;
    cout << "B  " << colados << endl;  // Obtener las cartas ocultas una sola vez
    cout << endl;
    cout << "M  " << list1 << endl;
    cout << "N  " << list2 << endl;
    cout << "E  " << list3 << endl;
    cout << "F  " << list4 << endl;
    cout << "G  " << list5 << endl;
    cout << "H  " << list6 << endl;
    cout << "I  " << list7 << endl;
    cout << endl;
    cout << "C  " << pil1 << endl;
    cout << "T  " << pil2 << endl;
    cout << "E  " << pil3 << endl;
    cout << "D  " << pil4 << endl;
    cout << endl;
}

/**
 *
 */
void moverCartas() {}
/**
 * Metodo para llenar las pilas
 */
void llenarListas() {
    for (int i = 0; i < 1; i++) {
        if (!mazo.estaVacia()) {
            Carta caarta = mazo.pop();
            lista1.insertarAlInicio(caarta);
        } else {
            break;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (!mazo.estaVacia()) {
            Carta caarta = mazo.pop();
            lista2.insertarAlInicio(caarta);
        } else {
            break;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (!mazo.estaVacia()) {
            Carta caarta = mazo.pop();
            lista3.insertarAlInicio(caarta);
        } else {
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!mazo.estaVacia()) {
            Carta caarta = mazo.pop();
            lista4.insertarAlInicio(caarta);
        } else {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (!mazo.estaVacia()) {
            Carta caarta = mazo.pop();
            lista5.insertarAlInicio(caarta);
        } else {
            break;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (!mazo.estaVacia()) {
            Carta caarta = mazo.pop();
            lista6.insertarAlInicio(caarta);
        } else {
            break;
        }
    }
    for (int i = 0; i < 7; i++) {
        if (!mazo.estaVacia()) {
            Carta caarta = mazo.pop();
            lista7.insertarAlInicio(caarta);
        } else {
            break;
        }
    }
}

/**
 * Mueve las cartas de la columna A a la B
 */
void moverCola1ACols2() {
    if (!cola1.estaVacia()) {
        Carta carta = cola1.eliminarElementoCola();
        cola2.insertarCola(carta);
    } else {
        cout << "La cola esta vacia: ";
    }
}

/**
 * Este metodo vuelve a llenar las cartas ocultas
 */
void devolverCartas() {
    // Devolver todas las cartas de la cola2 a la columna1
    while (!cola2.estaVacia()) {
        Carta carta = cola2.eliminarElementoCola();
        cola1.insertarCola(carta);
    }
}