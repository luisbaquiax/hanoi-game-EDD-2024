//
// Created by Luis on 23/02/2024.
//
#include <iostream>
#include "Cola.h"

void Cola::push(const std::string value) {
    NodoC *nuevo = new NodoC(value);
    if (first == nullptr) {
        first = nuevo;
        end = nuevo;
    } else {
        end->siguiente = nuevo;
        end = nuevo;
    }
}

NodoC *Cola::pop() {
    if (!isEmpity()) {
        NodoC *temp = first;
        first = temp->siguiente;
        return temp;
    }
}

void Cola::printData() {
    NodoC *temp = first;
    while (temp!= nullptr) {
        std::cout << "Valor: " << temp->value << std::endl;
        temp = temp->siguiente;
    }
}

bool Cola::isEmpity() const {
    return first == nullptr;
}