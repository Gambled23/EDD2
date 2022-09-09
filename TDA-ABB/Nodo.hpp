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
    Nodo(int);
    Nodo *izq;
    Nodo *der;
    int dato;

};

Nodo::Nodo()
{
    izq = nullptr;
    der = nullptr;
}

Nodo::Nodo(int e)
{
    dato = e;
    izq = nullptr;
    der = nullptr;
}

#endif