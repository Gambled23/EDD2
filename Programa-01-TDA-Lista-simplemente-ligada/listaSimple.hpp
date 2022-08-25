#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "nodo.hpp"
#pragma once

using namespace std;

class listaSimple
{
public:
    listaSimple();
    nodo *h; // Puntero que apunta a inicio
    nodo *t; // Puntero que apunta a final
    void inicializa();
    void insertaInicio(string);
    void insertarFinal(string);
    void mostrarLista();
    void tamanoLista();
    void buscarElemento(string);
    void eliminarElemento(string);
    void eliminarLista(string &);

private:
};

listaSimple::listaSimple()
{
    h = nullptr; // Inicia apuntando a null
    t = nullptr; // Apuntador a tail
}

void listaSimple::inicializa()
{
    h = nullptr;
    t = nullptr;
}

/* notinskis
    Nodo = nodo
    dato = elem
    lista = h (apunta al inicio de la lista)
    n = e
    siguiente = sig
*/

//* *OPERACIONES
void listaSimple::insertaInicio(string n)
{
    nodo *nuevo_nodo = new nodo(); // crear nuevo nodo dinamico
    nuevo_nodo->dato = n;          // asignar dato al nuevo nodo
    nodo *aux1 = h;                // Auxiliar para saber el siguiente
    h = nuevo_nodo;                // Apuntar al 1er elemento
    nuevo_nodo->siguiente = aux1;  // Asignar el puntero del nuevo nodo el siguiente nodo
    if (h->siguiente == nullptr)
    {
        t = nuevo_nodo; // Apuntar t al final
    }
}

void listaSimple::insertarFinal(string n)
{
    nodo *nuevo_nodo = new nodo(); // crear nuevo nodo dinamico
    nuevo_nodo->dato = n;          // asignar dato al nuevo nodo
    if (h == nullptr)
    {
        h = nuevo_nodo;
    }
    nodo *aux1 = h; // Auxiliar para saber el siguiente
    nodo *aux2;
    while (aux1 != nullptr)
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    aux2->siguiente = nuevo_nodo;
    nuevo_nodo->siguiente = aux1; // Asignar el puntero del nuevo nodo el siguiente nod
    t = nuevo_nodo;
}

void listaSimple::mostrarLista()
{
    nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
    actual = h;                // Apuntar el nodo actual al inicio, para recorrer desde el 1er elemento

    while (actual != nullptr) // Mientras sigamos apuntando a un dato, y no al NULL, significa que seguimos en la lista
    {
        cout << actual->dato << " - "; // Imprimir el dato en el que nos encontramos
        actual = actual->siguiente;    // Recorrer un nodo
    }
    cout << endl;
}

void listaSimple::tamanoLista()
{
    nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
    actual = h;
    int i = 0;
    while (actual != nullptr) // Mientras sigamos apuntando a un dato, y no al NULL, significa que seguimos en la lista
    {
        i++;
        actual = actual->siguiente; // Recorrer un nodo
    }
    cout<<"La lista tiene "<<i<<" elementos"<<endl;
}

void listaSimple::buscarElemento(string n)
{
    bool bandera = false;
    nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
    actual = h;                // Apuntar el nodo actual al inicio, para recorrer desde el 1er elemento

    while ((actual != nullptr)) // Mientras sigamos apuntando a un dato, y no al NULL, significa que seguimos en la lista
    {
        if (actual->dato == n)
        {
            bandera = true; // Se establece en true si encuentra el elemento n a buscar
        }
        actual = actual->siguiente; // Recorrer un nodo
    }
    if (bandera == true)
    {
        cout << "El elemento " << n << " SI se encuentra en la lista\n";
    }
    else
    {
        cout << "El elemento " << n << " NO se encuentra en la lista\n";
    }
}

void listaSimple::eliminarElemento(string n)
{
    if (h != NULL)
    {   
        nodo *aux_borrar;
        nodo *anterior = NULL;
        aux_borrar = h;
        while ((aux_borrar != NULL) && (aux_borrar->dato != n)) // Recorrer lista
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if (aux_borrar == NULL) // Si el elemento no se encuentra en la lista(no se elimina)
        {
            cout << "El elemento no existe en la lista\n";
        }
        else if (anterior == NULL) // El primer elemento es el que se elimina
        {
            h = h->siguiente;                                      // el inicio de la lista se cambia, pues se elimino el inicio
            cout << "El elemento '" << n << "' ha sido borrado\n"; // Imprimir el elemento a borrar
            delete aux_borrar;
        }
        else // El elemento que se elimina no es el primer elemento
        {
            anterior->siguiente = aux_borrar->siguiente;           // Se apunta el nodo anterior del eliminado al nodo siguiente del eliminado
            cout << "El elemento '" << n << "' ha sido borrado\n"; // Imprimir el elemento a borrar
            delete aux_borrar;
            if (aux_borrar->siguiente == nullptr)
            {
                t = anterior;
            }
        }
    }
}

void listaSimple::eliminarLista(string &n)
{
    while (h != NULL) // Para hacer la eliminacion de cada nodo hasta que este vacia
    {
        nodo *aux = h; // Crear auxiliar que apunte al inicio de la lista
        n = aux->dato; // Guardar el elemento antes de eliminar el nodo
        h = aux->siguiente;
        delete aux;
    }
    cout << "La lista ha sido vaciada\n";
    t = nullptr;
}
#endif