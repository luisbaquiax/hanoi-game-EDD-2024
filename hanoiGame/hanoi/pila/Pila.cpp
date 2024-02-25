//
// Created by Luis on 23/02/2024.
//

#include <iostream>
#include "Pila.h"

void Pila::push(const std::string &valor) {
    NodoP *nuevo = new NodoP(valor);
    nuevo->siguiente = tope;
    tope = nuevo;
}

NodoP *Pila::pop() {
    if (!esVacia()) {
        NodoP *temp = tope;
        tope = tope->siguiente;
        temp->siguiente = nullptr;
        return temp;
    }
}

bool Pila::esVacia() const {
    return tope == nullptr;
}

NodoP *Pila::getTope() {
    return tope;
}

void Pila::verDatos() {
    NodoP *temp = tope;
    while (temp != nullptr) {
        std::cout << "Valor: " << temp->valor << std::endl;
        temp = temp->siguiente;
    }
}