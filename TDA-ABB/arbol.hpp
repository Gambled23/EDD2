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
    void insertar(Nodo *&, int, Nodo *);
    void eliminar(Nodo *, int);
    void eliminarNodo(Nodo *);
    Nodo *minimo(Nodo*);
    void reemplazar(Nodo*, Nodo*);
    void destruirNodo(Nodo*);
    void preorden(Nodo *);
    void orden(Nodo *);
    void postorden(Nodo *);

private:
};

arbol::arbol()
{
    raiz = nullptr;
}

void arbol::insertar(Nodo *&raiz, int e, Nodo *padre)
{
    if (!raiz)
    {
        Nodo *nuevo_nodo = new Nodo(e, padre);
        raiz = nuevo_nodo;
    }
    else
    {
        if (e < raiz->dato)
        {
            insertar(raiz->izq, e, raiz);
        }
        else
        {
            insertar(raiz->der, e, raiz);
        }
    }
}

void arbol::preorden(Nodo *raiz)
{
    if (raiz)
    {
        cout << raiz->dato << " - ";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void arbol::orden(Nodo *raiz)
{
    if (raiz)
    {
        orden(raiz->izq);
        cout << raiz->dato << " - ";
        orden(raiz->der);
    }
}

void arbol::postorden(Nodo *raiz)
{
    if (raiz)
    {
        postorden(raiz->izq);
        postorden(raiz->der);
        cout << raiz->dato << " - ";
    }
}

void arbol::eliminar(Nodo *raiz, int e)
{
    if (raiz)
    {
        if (e < raiz->dato)
        {
            eliminar(raiz->izq, e);
        }
        else if (e > raiz->dato)
        {
            eliminar(raiz->der, e);
        }
        else //Encontró el nodo
        {
            eliminarNodo(raiz);
        }
    }
}

void arbol::eliminarNodo(Nodo *nodoEliminar)
{
    if (nodoEliminar->izq and nodoEliminar->der) //Dos hijos
    {
        Nodo *menor = minimo(nodoEliminar->der); //Mayor de los menores
        nodoEliminar->dato = menor->dato; //Reemplazar el nodo a eliminar
        eliminarNodo(menor);
    }
    else if (nodoEliminar->izq) //Un hijo izq
    {
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if (nodoEliminar->der) //Un hijo der
    {
        reemplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else //Sin hijos
    {
        reemplazar(nodoEliminar, nullptr);
        destruirNodo(nodoEliminar);
    }
}

Nodo *arbol::minimo(Nodo *raiz)
{
    if (raiz)
    {
        if (raiz->izq)
        {
            return minimo(raiz->izq);
        }else
        {
            return raiz;
        }
        
    }
}


void arbol::reemplazar(Nodo* raiz, Nodo* nuevoNodo)
{
    if (raiz->padre) //Asignar nuevo padre
    {
        if (raiz->dato == raiz->padre->izq->dato)
        {
            raiz->padre->izq = nuevoNodo;
        }
        else if (raiz->dato == raiz->padre->der->dato)
        {
            raiz->padre->der = nuevoNodo;
        }
    }
    if (nuevoNodo) //Asignar nuevo hijo
    {
        nuevoNodo->padre = raiz->padre;
    }
    
}

void arbol::destruirNodo(Nodo* nodoDestruir)
{
    nodoDestruir->izq = nullptr;
    nodoDestruir->der = nullptr;
    delete nodoDestruir;
}
#endif