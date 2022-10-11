#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;
class nodoArista;
class nodoVertice
{
public:
    nodoVertice();
    int dato;
    nodoVertice *sig;
    nodoArista *hArista;
    nodoVertice(int e, nodoArista *arista, nodoVertice *vertice)
    {
        dato = e;
        sig = vertice;
        hArista = arista;
    }
};

nodoVertice::nodoVertice()
{
    dato = 0;
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