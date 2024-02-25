//
// Created by Luis on 23/02/2024.
//

#ifndef HANOIGAME_NODOC_H
#define HANOIGAME_NODOC_H

#include <string>

class NodoC {
public:
    std::string value;
    NodoC *siguiente;

    NodoC(const std::string &value) : value(value), siguiente(nullptr) {}
};


#endif //HANOIGAME_NODOC_H
