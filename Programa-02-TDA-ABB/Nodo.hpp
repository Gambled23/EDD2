#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <cstdlib>
#include "alumno.hpp"
#pragma once

using namespace std;

class Nodo
{
public:
    Nodo();
    Nodo(alumno, Nodo*);
    Nodo *padre;
    Nodo *izq;
    Nodo *der;
    alumno dato;
};

Nodo::Nodo()
{
    izq = nullptr;
    der = nullptr;
    padre = nullptr;
}

Nodo::Nodo(alumno e, Nodo* pdre)
{
    dato = e;
    padre = pdre;
    izq = nullptr;
    der = nullptr;
}

#endif