#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <cstdlib>
#include "alumno.hpp"
#pragma once

using namespace std;
class nodoArista;
class nodoVertice
{
public:
    nodoVertice();
    alumno dato;
    nodoVertice *sig;
    nodoArista *hArista;
    nodoVertice(alumno e, nodoArista *arista, nodoVertice *vertice)
    {
        dato = e;
        sig = vertice;
        hArista = arista;
    }
};

nodoVertice::nodoVertice()
{
    sig = nullptr;
    hArista = nullptr;
}

class nodoArista
{
public:
    nodoArista();
    int peso;
    nodoArista *sigArista;
    nodoVertice *destino;
    nodoArista(int e, nodoVertice *dest, nodoArista *sig)
    {
        peso = e;
        sigArista = sig;
        destino = dest;
    }
};

nodoArista::nodoArista()
{
    peso = 0;
    sigArista = nullptr;
    destino = nullptr;
}

#endif