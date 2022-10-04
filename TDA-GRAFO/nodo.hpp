#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class nodoVertice
{
public:
    nodoVertice();

private:
    int dato;
    nodoVertice *sig;
    nodoArista *hArista;
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

private:
    int peso;
    nodoArista *sig;
    nodoVertice *destino;
};

nodoArista::nodoArista()
{
    peso = 0;
    sig = nullptr;
    destino = nullptr;
}

#endif