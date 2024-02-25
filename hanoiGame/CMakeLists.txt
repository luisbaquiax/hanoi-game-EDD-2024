cmake_minimum_required(VERSION 3.27)
project(hanoiGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(hanoiGame main.cpp
        hanoi/Hanoi.cpp
        hanoi/Hanoi.h
        hanoi/pila/NodoP.cpp
        hanoi/pila/NodoP.h
        hanoi/cola/NodoC.cpp
        hanoi/cola/NodoC.h
        hanoi/pila/Pila.cpp
        hanoi/pila/Pila.h
        hanoi/cola/Cola.cpp
        hanoi/cola/Cola.h)
