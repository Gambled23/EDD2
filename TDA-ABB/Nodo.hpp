#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class Nodo
{
public:
    Nodo();
    Nodo(int, Nodo*);
    Nodo *padre;
    Nodo *izq;
    Nodo *der;
    int dato;

};

Nodo::Nodo()
{
    izq = nullptr;
    der = nullptr;
    padre = nullptr;
}

Nodo::Nodo(int e, Nodo* pdre)
{
    dato = e;
    padre = pdre;
    izq = nullptr;
    der = nullptr;
}

#endif