#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Nodo.hpp"
#pragma once

using namespace std;

class arbol
{
public:
    arbol();
    Nodo *raiz;
    void insertar(Nodo*&, int);
    void preorden(Nodo*);
    void orden(Nodo*);
    void postorden(Nodo*);

private:

};

arbol::arbol()
{
    raiz = nullptr;
}

void arbol::insertar(Nodo *&raiz, int e)
{
    if (!raiz)
    {
        Nodo *nuevo_nodo = new Nodo(e);
        raiz = nuevo_nodo;
    }
    else{
        if (e < raiz->dato)
        {
            insertar(raiz->izq, e);
        }
        else
        {
            insertar(raiz->der, e);
        }
    }
}


void arbol::preorden(Nodo* raiz)
{
    if (raiz)
    {
        cout << raiz->dato << " - ";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void arbol::orden(Nodo* raiz)
{
    if (raiz)
    {
        orden(raiz->izq);
        cout << raiz->dato << " - ";
        orden(raiz->der);
    }
}

void arbol::postorden(Nodo* raiz)
{
    if (raiz)
    {
        postorden(raiz->izq);
        postorden(raiz->der);
        cout << raiz->dato << " - ";
    }   
}


#endif