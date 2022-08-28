#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include "nodo.hpp"
#include "alumno.hpp"
#pragma once

using namespace std;

int ID = 1;

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
    void guardarDatos();
    void cargarDatos();
    void eliminarDatos();

private:
};

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
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->dato = n;
    nodo *aux1 = h;
    h = nuevo_nodo;
    nuevo_nodo->sig = aux1;
    if (h->sig == nullptr)
    {
        t = nuevo_nodo;
    }
}
void listaSimple::insertarFinal(alumno n)
{
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->dato = n;
    if (h == nullptr)
    {
        h = nuevo_nodo;
    }
    nodo *aux1 = h;
    nodo *aux2;
    while (aux1 != nullptr)
    {
        aux2 = aux1;
        aux1 = aux1->sig;
    }
    aux2->sig = nuevo_nodo;
    nuevo_nodo->sig = aux1;
    t = nuevo_nodo;
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

void listaSimple::guardarDatos()
{
    nodo *actual = new nodo();
    actual = h;
    ofstream archivoLista;
    archivoLista.open("file01.txt", ios::out);
    if (archivoLista.fail()) // True/false, si hubo error se da mensaje
    {
        cout << "No se pudo abrir el archivo";
        exit(1); // Salir del programa
    }
    while (actual != nullptr)
    {
        archivoLista << actual->dato.getNombre() << "|";
        archivoLista << actual->dato.getId() << "|";
        archivoLista << actual->dato.getActivo() << "*";
        actual = actual->sig;
    }
    archivoLista.close();
    cout << "Los datos han sido guardados exitosamente" << endl;
}

void listaSimple::cargarDatos()
{
    int opc;
    if (h)
    {
        cout << "Ya hay datos en la lista, para evitar datos duplicados es necesario borrar los datos actuales\n";
        cout << "Quieres continuar?\n  1)Si 2)No\n";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Borrando datos...\n";
            eliminarLista();
            cout << "Cargando datos...\n";
            cargarDatos();
            break;
        case 2:
            cout << "Volviendo al menu principal...\n";
            break;
        default:
            cout << "Opcion incorrecta\n";
            break;
        }
    }
    else
    {
        string cadena, registro, campo;
        int aux = 1;
        alumno aluAux;
        ifstream archivoLista;
        archivoLista.open("file01.txt", ios::in);
        if (archivoLista.fail())
        {
            cout << "No se pudo abrir el archivo\n";
            exit(1);
        }
        while (!archivoLista.eof()) // Mientras no sea el end of file
        {
            getline(archivoLista, cadena);
        }
        stringstream cadenaStream(cadena);
        while (getline(cadenaStream, registro, '*'))
        {
            aux = 1;
            stringstream registroStream(registro);
            while (getline(registroStream, campo, '|'))
            {
                switch (aux)
                {
                case 1:
                    aluAux.setNombre(campo);
                    break;
                case 2:
                    if (ID < stoi(campo))
                    {
                        ID = stoi(campo) + 1;
                    }
                    aluAux.setId(stoi(campo));
                    break;
                case 3:
                    aluAux.setActivo(stoi(campo));
                    break;
                default:
                    break;
                }
                aux++;
            }
            insertarFinal(aluAux);
        }
        cout << "Los datos han sido cargados exitosamente" << endl;
        archivoLista.close();
    }
}

void listaSimple::eliminarDatos()
{
    int opc = 2;
    cout << "Esta accion es irreversible y borrara todos los datos de respaldo, seguro que quieres continuar?\n";
    cout << "   1)Si  2)No\n";
    cin >> opc;
    if (opc == 1)
    {
        ofstream archivoLista;
        archivoLista.open("file01.txt", std::ofstream::out | std::ofstream::trunc);
        cout << "Los datos guardados han sido eliminados" << endl;
        archivoLista.close();
    }
    else
    {
        cout<<"Regresando al menu principal...\n";
    }
}
#endif