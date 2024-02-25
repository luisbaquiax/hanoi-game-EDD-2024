//
// Created by Luis on 23/02/2024.
//

#ifndef HANOIGAME_PILA_H
#define HANOIGAME_PILA_H

#include "NodoP.h"
#include <string>

class Pila {
private:
    NodoP *tope;
public:
    Pila() : tope(nullptr) {};

    void push(const std::string& valor);

    NodoP *pop();

    bool esVacia() const;

    void verDatos();
    NodoP *getTope();
};


#endif //HANOIGAME_PILA_H
