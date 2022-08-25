#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "nodo.hpp"
#include "alumno.hpp"
#pragma once

using namespace std;

class listaSimple
{
public:
    listaSimple();
    nodo *h; // Puntero que apunta a inicio
    nodo *t; // Puntero que apunta a final
    void inicializa();
    void insertaInicio(alumno);
    void insertarFinal(alumno);
    void mostrarLista();
    void tamanoLista();
    void buscarElemento(int);
    void eliminarElemento(int);
    void eliminarLista();

private:
};
int ID = 0;

listaSimple::listaSimple()
{
    h = nullptr;
    t = nullptr;
}

void listaSimple::inicializa()
{
    h = nullptr;
    t = nullptr;
}

//* *OPERACIONES
void listaSimple::insertaInicio(alumno n)
{
    nodo *nuevo_nodo = new nodo(); // crear nuevo nodo dinamico
    nuevo_nodo->dato = n;          // asignar dato al nuevo nodo
    nodo *aux1 = h;                // Auxiliar para saber el siguiente
    h = nuevo_nodo;                // Apuntar al 1er elemento
    nuevo_nodo->sig = aux1;        // Asignar el puntero del nuevo nodo el siguiente nodo
    if (h->sig == nullptr)
    {
        t = nuevo_nodo; // Apuntar t al final
    }
    ID++;
    h->dato.setId(ID);
}
void listaSimple::insertarFinal(alumno n)
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
        aux1 = aux1->sig;
    }
    aux2->sig = nuevo_nodo;
    nuevo_nodo->sig = aux1; // Asignar el puntero del nuevo nodo el siguiente nod
    t = nuevo_nodo;
    ID++;
    nuevo_nodo->dato.setId(ID);
}

void listaSimple::mostrarLista()
{
    nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
    actual = h;                // Apuntar el nodo actual al inicio, para recorrer desde el 1er elemento

    cout << "Nombre\t\tID\t\tEstado" << endl;
    while (actual != nullptr) // Mientras sigamos apuntando a un dato, y no al NULL, significa que seguimos en la lista
    {
        cout << actual->dato.getNombre() << "\t\t" << actual->dato.getId() << "\t\t";
        if (actual->dato.getActivo())
        {
            cout << "Activo" << endl;
        }
        else
        {
            cout << "No activo" << endl;
        }
        actual = actual->sig;
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
        actual = actual->sig; // Recorrer un nodo
    }
    cout << "La lista tiene " << i << " elementos" << endl;
}

void listaSimple::buscarElemento(int n)
{
    bool bandera = false;
    nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
    actual = h;                // Apuntar el nodo actual al inicio, para recorrer desde el 1er elemento

    while ((actual != nullptr)) // Mientras sigamos apuntando a un dato, y no al NULL, significa que seguimos en la lista
    {
        if (actual->dato.getId() == n)
        {
            bandera = true;
            cout << "Nombre\t\tID\t\tEstado" << endl;
            cout << actual->dato.getNombre() << "\t\t" << actual->dato.getId() << "\t\t";
            if (actual->dato.getActivo())
            {
                cout << "Activo" << endl;
            }
            else
            {
                cout << "No activo" << endl;
            }
        }
        actual = actual->sig;
    }
    if (!bandera)
    {
        cout << "El alumno con la ID '" << n << "' NO se encuentra en la lista\n";
    }
}

void listaSimple::eliminarElemento(int n)
{
    if (h != NULL)
    {
        nodo *aux_borrar;
        nodo *anterior = NULL;
        aux_borrar = h;
        while ((aux_borrar != NULL) && (aux_borrar->dato.getId() != n)) // Recorrer lista
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->sig;
        }
        if (aux_borrar == NULL) // Si el elemento no se encuentra en la lista(no se elimina)
        {
            cout << "El alumno con ID '" << n << "' no existe en la lista\n";
        }
        else if (anterior == NULL) // El primer elemento es el que se elimina
        {
            h = h->sig;                                                 // el inicio de la lista se cambia, pues se elimino el inicio
            cout << "El alumno con ID '" << n << "' ha sido borrado\n"; // Imprimir el elemento a borrar
            delete aux_borrar;
        }
        else // El elemento que se elimina no es el primer elemento
        {
            anterior->sig = aux_borrar->sig;                            // Se apunta el nodo anterior del eliminado al nodo siguiente del eliminado
            cout << "El alumno con ID '" << n << "' ha sido borrado\n"; // Imprimir el elemento a borrar
            delete aux_borrar;
            if (aux_borrar->sig == nullptr)
            {
                t = anterior;
            }
        }
    }
}

void listaSimple::eliminarLista()
{
    while (h != NULL) // Para hacer la eliminacion de cada nodo hasta que este vacia
    {
        nodo *aux = h; // Crear auxiliar que apunte al inicio de la lista
        h = aux->sig;
        delete aux;
    }
    cout << "La lista ha sido vaciada\n";
    t = nullptr;
    h = nullptr;
}

#endif