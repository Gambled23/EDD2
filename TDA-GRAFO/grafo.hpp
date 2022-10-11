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
    nodoVertice *hGrafo;
    void insertarVertice(int);
    void insertarArista(int, int, int);
    nodoVertice *buscarVertice(int);
    void eliminarVertice();
    void eliminarArista();
    void mostrarConexiones();

private:
};

grafo::grafo()
{
    hGrafo = nullptr;
}

void grafo::insertarVertice(int e)
{
    nodoVertice *aux = new nodoVertice(e, nullptr, nullptr);
    nodoVertice *tmp = hGrafo;
    if (!tmp) // Lista de vtc vacia
    {
        hGrafo = aux;
    }
    else
    {
        while (tmp->sig) // Recorrer lista vtc
        {
            tmp = tmp->sig;
        }
        tmp->sig = aux; // Insertar al final de lista vtc
    }
}

void grafo::insertarArista(int orig, int desti, int e)
{
    nodoVertice *tmpVertice = hGrafo;
    nodoArista *tmpArista = nullptr;
    bool bandera = true;
    while (tmpVertice and bandera)
    {
        if (tmpVertice->dato == orig) // Si encuentra el dato
        {
            bandera = false;
        }
        else
        {
            tmpVertice = tmpVertice->sig; // Recorrer lista vtc para encontrar origen
        }
    }
    if (tmpVertice) // Si existe el origen
    {
        // Lista de aristas
        tmpArista = tmpVertice->hArista;
        if (!tmpArista)
        {
            nodoVertice *dest = buscarVertice(desti); // Busca el destino
            if (dest) //Si encontro el destino
            {
                //Insertar al inicio
                nodoArista *aux = new nodoArista(e, dest, nullptr);
                aux->sigArista = tmpVertice->hArista;
                tmpVertice->hArista = aux;
            }
            else
            {
                cout<<"No se encontro el destino\n";
            }
        }
    }
    else
    {
        cout << "Origen no encontrado\n";
    }
}
nodoVertice *grafo::buscarVertice(int e)
{
    nodoVertice *tmp = hGrafo;
    bool bandera = true;
    while (bandera) // Recorrer lista de vtc
    {
        if (tmp->dato == e)
        {
            bandera = false;
        }
        else
        {
            tmp = tmp->sig;
        }
    }
    if (tmp)
    {
        return tmp;
    }
    return nullptr;
}

void grafo::eliminarVertice()
{
}

void grafo::eliminarArista()
{
}

void grafo::mostrarConexiones()
{
    nodoVertice *tmpVertice = hGrafo;
    nodoArista *tmpArista = nullptr;
    while (tmpVertice)
    {
        tmpArista = tmpVertice->hArista; //Posicionarnos en 1er arista
        cout<<"Vertice origen: " <<tmpVertice->dato<<"  ";
        while (tmpArista) //Recorrer lista de aristas del vertice actual
        {
            cout<<" "<<tmpArista->destino->dato;
            tmpArista = tmpArista->sigArista;
        }
        cout<<endl;
        tmpVertice = tmpVertice->sig; //Recorrer lista de vertices
    } 
}
#endif