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
    void insertarVertice(alumno);
    void insertarArista(int, int, int);
    nodoVertice *buscarVertice(int);
    nodoArista *buscarArista(int, int);
    void eliminarVertice(int);
    void eliminarArista(int, int);
    void mostrarConexiones();

private:
};

grafo::grafo()
{
    hGrafo = nullptr;
}

void grafo::insertarVertice(alumno e)
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
    nodoVertice *orgVtc = buscarVertice(orig);
    nodoVertice *destVtc = buscarVertice(desti); // Busca el destino
    bool bandera = true;
    if (orgVtc) // Si existe el origen
    {
        if (destVtc) // Si existe el destino
        {
            nodoArista *aristaInsertar = new nodoArista(e, destVtc, nullptr); // Crear nodo arista
            if (!orgVtc->hArista)                                             // Si no hay aristas
            {
                orgVtc->hArista = aristaInsertar;
            }
            else // Si ya hay aristas insertar al inicio
            {
                aristaInsertar->sigArista = orgVtc->hArista;
                orgVtc->hArista = aristaInsertar;
            }
        }
        else
        {
            cout << "Destino no encontrado\n";
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
    while (bandera and tmp) // Recorrer lista de vtc
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

nodoArista *grafo::buscarArista(int org, int dst)
{
    nodoVertice *origen = buscarVertice(org);
    nodoArista *auxArista = nullptr;
    bool bandera = true;
    if (origen) // Encontro el origen
    {
        auxArista = origen->hArista;
        if (auxArista)
        {
            while (auxArista->sigArista and bandera)
            {
                if (auxArista->destino->dato == dst) // Encontro el destino
                {
                    bandera = false;
                }
                else
                {
                    auxArista = auxArista->sigArista;
                }
            }
            if (auxArista)
            {
                return auxArista;
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        return nullptr;
    }
}
void grafo::eliminarVertice(int e)
{
    nodoVertice *tmpVertice = buscarVertice(e); // Busca vertice
    nodoVertice *antVertice = hGrafo;
    nodoArista *tmpArista = tmpVertice->hArista;
    if (tmpVertice)
    {
        if (tmpVertice->hArista) // Borrar todas las aristas
        {
            // Borrar primer elemento de lista aristas
            tmpArista = tmpVertice->hArista;
            tmpVertice->hArista = tmpVertice->hArista->sigArista;
            delete tmpArista;
        }
        if (hGrafo == tmpVertice) // Si el vertice a eliminar es el 1er elemento
        {
            hGrafo = tmpVertice->sig;
            delete tmpVertice;
        }
        else // Si es otro elemento
        {
            while (antVertice->sig != tmpVertice)
            {
                antVertice = antVertice->sig;
            }
            antVertice->sig = tmpVertice->sig; // Aislar nodo a eliminar
            delete tmpVertice;
        }
    }
    else
    {
        cout << "Vertice no encontrado\n";
    }
}

void grafo::eliminarArista(int org, int dst)
{
    nodoVertice *tmpVertice = buscarVertice(org); // Busca origen
    bool bandera = true;
    if (tmpVertice)
    {
        nodoArista *tmpArista = tmpVertice->hArista;
        nodoArista *antArista = tmpArista;
        while (bandera and tmpArista)
        {
            if (tmpArista->destino->dato == dst) // Encontro el destino
            {
                bandera = false;
            }
            antArista = tmpArista;
            tmpArista = tmpArista->sigArista; // Recorrer lista de aristas
        }
        // Eliminar arista
        if (tmpArista)
        {
            if (tmpArista == tmpVertice->hArista) // Si es el 1er dato
            {
                tmpVertice->hArista = tmpVertice->hArista->sigArista;
            }
            else // Si es otro dato
            {
                antArista->sigArista = tmpArista->sigArista; // Aislar dato a eliminar
            }
            delete tmpArista;
            cout << "La arista ha sido eliminada\n";
        }
        else
        {
            cout << "No se encontro el destino\n";
        }
    }
    else
    {
        cout << "No se encontro el origen\n";
    }
}

void grafo::mostrarConexiones()
{
    nodoVertice *tmpVertice = hGrafo;
    nodoArista *tmpArista = nullptr;
    while (tmpVertice)
    {
        tmpArista = tmpVertice->hArista;
        cout << "--------------------\n";
        cout << "Vertice: " << tmpVertice->dato << endl;
        cout << "Aristas: ";
        while (tmpArista)
        {
            cout << tmpArista->destino->dato << " (" << tmpArista->peso << "), ";
            tmpArista = tmpArista->sigArista;
        }
        cout << "\n--------------------\n\n";
        tmpVertice = tmpVertice->sig;
    }
}

#endif