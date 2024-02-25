#include "hanoi/pila/Pila.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <stdlib.h>

const int FILAS = 7;
const int COLUMNAS = 3;
const std::string SIMBOLO = "0";

int numberRandom(int lower, int upper) {

    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void imprimir(std::string matriz[FILAS][COLUMNAS]) {
    printf("\n  ");
    for (int i = 0; i < COLUMNAS; i++) {
        printf("-%d", (i + 1));
    }
    printf("\n");
    for (int i = 0; i < FILAS; i++) {
        printf("%d- ", (i + 1));
        for (int j = 0; j < COLUMNAS; j++) {
            std::cout << matriz[i][j] + " ";
        }
        std::cout << std::endl;
    }
}

void llenarTablero(std::string matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = SIMBOLO;
        }
    }
}

bool containNumber(std::vector<int> array, int number) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == number) {
            return true;
        }
    }
    return false;
}

std::vector<int> numbers(int disks) {
    std::vector<int> nums;
    int i = 0;
    while (i < disks) {

        int random = numberRandom(1, disks);
        while (containNumber(nums, random)) {
            random = numberRandom(1, disks);
        }
        nums.push_back(random);
        i++;
    }
    return nums;
}

void addDiskFirstCol(int numDisk, std::string matriz[FILAS][COLUMNAS], Pila &torre1) {
    std::vector<int> nums = numbers(numDisk);
    int index = FILAS - 1;
    for (int i = 0; i < nums.size(); i++) {
        matriz[index][0] = std::to_string(nums[i]);
        torre1.push(std::to_string(nums[i]));
        index--;
    }
}

void addDisk(int disk, std::string matriz[FILAS][COLUMNAS], std::string value) {
    for (int i = FILAS - 1; i >= 0; i--) {
        if (matriz[i][disk] == SIMBOLO) {
            matriz[i][disk] = value;
            break;
        }
    }
}

void quitDisk(int disk, std::string matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        if (matriz[i][disk] != SIMBOLO) {
            matriz[i][disk] = SIMBOLO;
            break;
        }
    }
}

bool colVacia(int col, std::string matriz[FILAS][COLUMNAS]) {
    int count = 0;
    for (int i = 0; i < FILAS; i++) {
        if (matriz[i][col] == SIMBOLO) {
            count++;
        }
    }
    printf("count: %d\n", count);
    return count == FILAS;
}

void menu(int numdisk,std::string matriz[FILAS][COLUMNAS]) {
    Pila torre1;
    Pila torre2;
    Pila torre3;
    //llenamos la matriz y agregamos discos en la primera torre
    llenarTablero(matriz);
    addDiskFirstCol(numdisk, matriz, torre1);
    imprimir(matriz);

    /*printf("pila datos:\n");
    torre1.verDatos();*/

    int origin = 0;
    int destino = 0;
    bool continuar = true;
    while ((!colVacia(0, matriz) || !colVacia(1, matriz))) {
        do {
            printf("Ingrese el numero de torre origen y destino (ejemplo: '1 2'): ");
            scanf("%d %d", &origin, &destino);
        } while (origin == destino);
        printf("oringin %d destino %d\n", origin, destino);
        if (origin == 1 && destino == 2) {
            if (!torre1.esVacia()) {
                if (!torre2.esVacia()) {
                    NodoP *t1 = torre1.getTope();
                    NodoP *t2 = torre2.getTope();
                    if (std::stoi(t1->valor) > std::stoi(t2->valor)) {
                        printf("No se puede trasladar el disco");
                    } else {
                        NodoP *temp = torre1.pop();
                        quitDisk(0, matriz);
                        addDisk(1, matriz, temp->valor);
                        torre2.push(temp->valor);
                    }
                } else {
                    NodoP *temp = torre1.pop();
                    quitDisk(0, matriz);
                    addDisk(1, matriz, temp->valor);
                    torre2.push(temp->valor);
                }
            } else {
                printf("Ya no existe discos en la torre.");
            }
        } else if (origin == 1 && destino == 3) {
            if (!torre1.esVacia()) {
                if (!torre3.esVacia()) {
                    NodoP *t1 = torre1.getTope();
                    NodoP *t3 = torre3.getTope();
                    if (std::stoi(t1->valor) > std::stoi(t3->valor)) {
                        printf("No se puede trasladar el disco");
                    } else {
                        NodoP *temp = torre1.pop();
                        quitDisk(0, matriz);
                        addDisk(2, matriz, temp->valor);
                        torre3.push(temp->valor);
                    }
                } else {
                    NodoP *temp = torre1.pop();
                    quitDisk(0, matriz);
                    addDisk(2, matriz, temp->valor);
                    torre3.push(temp->valor);
                }
            } else {
                printf("Ya no existe discos en la torre.");
            }
        } else if (origin == 2 && destino == 1) {
            if (!torre2.esVacia()) {
                if (!torre1.esVacia()) {
                    NodoP *t2 = torre2.getTope();
                    NodoP *t1 = torre1.getTope();
                    if (std::stoi(t2->valor) > std::stoi(t1->valor)) {
                        printf("No se puede trasladar el disco");
                    } else {
                        NodoP *temp = torre2.pop();
                        quitDisk(0, matriz);
                        addDisk(1, matriz, temp->valor);
                        torre3.push(temp->valor);
                    }
                } else {
                    NodoP *temp = torre2.pop();
                    quitDisk(1, matriz);
                    addDisk(0, matriz, temp->valor);
                    torre1.push(temp->valor);
                }
            } else {
                printf("Ya no existe discos en la torre.");
            }
        } else if (origin == 2 && destino == 3) {
            if (!torre2.esVacia()) {
                if (!torre3.esVacia()) {
                    NodoP *t2 = torre2.getTope();
                    NodoP *t3 = torre3.getTope();
                    if (std::stoi(t2->valor) > std::stoi(t3->valor)) {
                        printf("No se puede trasladar el disco");
                    } else {
                        NodoP *temp = torre2.pop();
                        quitDisk(1, matriz);
                        addDisk(2, matriz, temp->valor);
                        torre3.push(temp->valor);
                    }
                } else {
                    NodoP *temp = torre2.pop();
                    quitDisk(1, matriz);
                    addDisk(2, matriz, temp->valor);
                    torre3.push(temp->valor);
                }
            } else {
                printf("Ya no existe discos en la torre.");
            }
        } else if (origin == 3 && destino == 1) {
            if (!torre3.esVacia()) {
                if (!torre1.esVacia()) {
                    NodoP *t3 = torre2.getTope();
                    NodoP *t1 = torre1.getTope();
                    if (std::stoi(t3->valor) > std::stoi(t1->valor)) {
                        printf("No se puede trasladar el disco");
                    } else {
                        NodoP *temp = torre3.pop();
                        quitDisk(2, matriz);
                        addDisk(0, matriz, temp->valor);
                        torre1.push(temp->valor);
                    }
                } else {
                    NodoP *temp = torre3.pop();
                    quitDisk(2, matriz);
                    addDisk(0, matriz, temp->valor);
                    torre1.push(temp->valor);
                }
            } else {
                printf("Ya no existe discos en la torre.");
            }
        } else if (origin == 3 && destino == 2) {
            if (!torre3.esVacia()) {
                if (!torre2.esVacia()) {
                    NodoP *t3 = torre3.getTope();
                    NodoP *t2 = torre2.getTope();
                    if (std::stoi(t3->valor) > std::stoi(t2->valor)) {
                        printf("No se puede trasladar el disco");
                    } else {
                        NodoP *temp = torre3.pop();
                        quitDisk(2, matriz);
                        addDisk(1, matriz, temp->valor);
                        torre2.push(temp->valor);
                    }
                } else {
                    NodoP *temp = torre3.pop();
                    quitDisk(2, matriz);
                    addDisk(1, matriz, temp->valor);
                    torre2.push(temp->valor);
                }
            } else {
                printf("Ya no existe discos en la torre.");
            }
        }else{
            printf("Torres origen y destino invalidos");
        }
        imprimir(matriz);
    }
    if (colVacia(0, matriz) && colVacia(1, matriz)) {
        printf("Felicidades, has ganado!!!\n");
    } else {
        printf("Saliendo...");
    }

}

void game(std::string matriz[FILAS][COLUMNAS]) {
    menu(matriz);
}

int main() {
    srand(time(0));
    std::string tablero[FILAS][COLUMNAS];
    game(tablero);
    std::cout << "Pulse Enter para continuar...";
    std::cin.ignore();
    /*Pila p1;
    Pila p2;
    p1.push("1");
    if(!p2.esVacia()){
        if (std::stoi(p2.pop()->valor) > std::stoi(p1.pop()->valor)) {
            printf("dos > uno");
        }
    }*/

    return 0;
}
