//
// Created by Luis on 23/02/2024.
//

#ifndef HANOIGAME_COLA_H
#define HANOIGAME_COLA_H

#include "NodoC.h"
#include <string>

class Cola {
private:
    NodoC *first;
    NodoC *end;
public:
    Cola() : first(nullptr), end(nullptr) {};

    void push(const std::string value);

    NodoC *pop();

    bool isEmpity() const;

    void printData();
};


#endif //HANOIGAME_COLA_H
