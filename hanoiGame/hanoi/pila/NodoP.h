//
// Created by Luis on 23/02/2024.
//

#ifndef HANOIGAME_NODOP_H
#define HANOIGAME_NODOP_H

#include <string>


class NodoP {
public:
    std::string valor;
    NodoP *siguiente;

    NodoP(const std::string &valor) : valor(valor), siguiente(nullptr) {}
};


#endif //HANOIGAME_NODOP_H
