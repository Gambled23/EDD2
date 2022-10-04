#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <cstdlib>
#pragma once
#include "nodo.hpp"

using namespace std;

class grafo
{
public:
    grafo();
    nodoVertice *hVertice;
    void insertarVertice();
    void insertarArista();
    void eliminarVertice();
    void eliminarArista();

private:
};

grafo::grafo()
{
    hVertice = nullptr;
}

void grafo::insertarVertice()
{
}

void grafo::insertarArista()
{
}

void grafo::eliminarVertice()
{
}

void grafo::eliminarArista()
{
}

#endif