#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Nodo.hpp"
#pragma once

using namespace std;

string cadenaGuardar = "";
class arbol
{
public:
    arbol();
    Nodo *raiz;
    void insertar(Nodo *&, alumno, Nodo *);
    void eliminar(Nodo *, alumno);
    void eliminarNodo(Nodo *);
    Nodo *minimo(Nodo *);
    void reemplazar(Nodo *, Nodo *);
    void destruirNodo(Nodo *);
    void preorden(Nodo *);
    void orden(Nodo *);
    void postorden(Nodo *);
    void guardar();
    void preordenGuardar(Nodo *);
    void cargar();
    void buscar(Nodo *, int);
    void eliminarArbol();

private:
};

arbol::arbol()
{
    raiz = nullptr;
}

void arbol::insertar(Nodo *&raiz, alumno e, Nodo *padre)
{
    if (!raiz)
    {
        Nodo *nuevo_nodo = new Nodo(e, padre);
        raiz = nuevo_nodo;
    }
    else
    {
        if (e.getCalificacion() < raiz->dato.getCalificacion())
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
        cout << "-----------------------------------\n";
        cout << "Nombre: " << raiz->dato.getNombre() << "\n";
        cout << "Calificacion: " << raiz->dato.getCalificacion() << "\n";
        cout << "Semestre: " << raiz->dato.getSemestre() << "\n";
        cout << "-----------------------------------\n";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void arbol::orden(Nodo *raiz)
{
    if (raiz)
    {
        orden(raiz->izq);
        cout << "-----------------------------------\n";
        cout << "Nombre: " << raiz->dato.getNombre() << "\n";
        cout << "Calificacion: " << raiz->dato.getCalificacion() << "\n";
        cout << "Semestre: " << raiz->dato.getSemestre() << "\n";
        cout << "-----------------------------------\n";
        orden(raiz->der);
    }
}

void arbol::postorden(Nodo *raiz)
{
    if (raiz)
    {
        postorden(raiz->izq);
        postorden(raiz->der);
        cout << "-----------------------------------\n";
        cout << "Nombre: " << raiz->dato.getNombre() << "\n";
        cout << "Calificacion: " << raiz->dato.getCalificacion() << "\n";
        cout << "Semestre: " << raiz->dato.getSemestre() << "\n";
        cout << "-----------------------------------\n";
    }
}

void arbol::eliminar(Nodo *raiz, alumno e)
{
    if (raiz)
    {
        if (e.getCalificacion() < raiz->dato.getCalificacion())
        {
            eliminar(raiz->izq, e);
        }
        else if (e.getCalificacion() > raiz->dato.getCalificacion())
        {
            eliminar(raiz->der, e);
        }
        else // Encontró el nodo
        {
            eliminarNodo(raiz);
        }
        if (e.getCalificacion() == raiz->dato.getCalificacion())
        {
            Nodo *menor = minimo(raiz->der); // Mayor de los menores
            raiz->dato = menor->dato;        // Reemplazar el nodo a eliminar
            eliminarNodo(menor);
        }
    }
}

void arbol::eliminarNodo(Nodo *nodoEliminar)
{
    if (nodoEliminar->izq and nodoEliminar->der) // Dos hijos
    {
        Nodo *menor = minimo(nodoEliminar->der); // menor de mayores
        nodoEliminar->dato = menor->dato;        // Reemplazar el nodo a eliminar
        eliminarNodo(menor);
    }
    else if (nodoEliminar->izq) // Un hijo izq
    {
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if (nodoEliminar->der) // Un hijo der
    {
        reemplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else // Sin hijos
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
        }
        else
        {
            return raiz;
        }
    }
}

void arbol::reemplazar(Nodo *raiz, Nodo *nuevoNodo)
{
    if (raiz->padre) // Asignar nuevo padre
    {
        if (raiz->dato.getCalificacion() == raiz->padre->izq->dato.getCalificacion())
        {
            raiz->padre->izq = nuevoNodo;
        }
        else if (raiz->dato.getCalificacion() == raiz->padre->der->dato.getCalificacion())
        {
            raiz->padre->der = nuevoNodo;
        }
    }
    if (nuevoNodo) // Asignar nuevo hijo
    {
        nuevoNodo->padre = raiz->padre;
    }
}

void arbol::destruirNodo(Nodo *nodoDestruir)
{
    nodoDestruir->izq = nullptr;
    nodoDestruir->der = nullptr;
    delete nodoDestruir;
}

void arbol::guardar()
{
    if (!raiz)
    {
        cout << "No es posible guardar un arbol vacio\n";
        return;
    }
    preordenGuardar(raiz);

    ofstream archivoArbol;
    archivoArbol.open("file01.txt", ios::out);
    if (archivoArbol.fail()) // True/false, si hubo error se da mensaje
    {
        cout << "No se pudo abrir el archivo";
        exit(1); // Salir del programa
    }
    archivoArbol << cadenaGuardar;
    archivoArbol.close();
    cout << "Los datos han sido guardados\n";
}

void arbol::preordenGuardar(Nodo *raiz)
{
    if (raiz)
    {
        string calificacion = to_string(raiz->dato.getCalificacion());
        cadenaGuardar.append(calificacion);
        cadenaGuardar.append("|");
        cadenaGuardar.append(raiz->dato.getNombre());
        cadenaGuardar.append("|");
        cadenaGuardar.append(raiz->dato.getSemestre());
        cadenaGuardar.append("*");
        preordenGuardar(raiz->izq);
        preordenGuardar(raiz->der);
    }
}
void arbol::cargar()
{
    int opc;
    if (raiz)
    {
        cout << "Ya hay datos en la lista, para evitar datos duplicados es necesario borrar los datos actuales\n";
        cout << "Quieres continuar?\n  1)Si 2)No\n";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Borrando datos...\n";
            // eliminarLista();
            cout << "Cargando datos...\n";
            cargar();
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
        ifstream archivoArbol;
        archivoArbol.open("file01.txt", ios::in);
        if (archivoArbol.fail())
        {
            cout << "No se pudo abrir el archivo\n";
            exit(1);
        }
        while (!archivoArbol.eof()) // Mientras no sea el end of file
        {
            getline(archivoArbol, cadena);
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
                    aluAux.setCalificacion(stoi(campo));
                    break;
                case 2:
                    aluAux.setNombre(campo);
                    break;
                case 3:
                    aluAux.setSemestre(campo);
                    break;
                default:
                    break;
                }
                aux++;
            }
            insertar(raiz, aluAux, nullptr);
        }
        cout << "Los datos han sido cargados exitosamente" << endl;
        archivoArbol.close();
    }
}
void arbol::eliminarArbol()
{
    while (raiz->der)
    {
        eliminar(raiz, raiz->dato);
    }
    while (raiz->izq)
    {
        eliminar(raiz, raiz->izq->dato);
    }
    delete (raiz);
    raiz = nullptr;
}
void arbol::buscar(Nodo *raiz, int num)
{
    if (raiz)
    {
        if (raiz->dato.getCalificacion() == num) // Lo encontro
        {
            cout << "-----------------------------------\n";
            cout << "Nombre: " << raiz->dato.getNombre() << "\n";
            cout << "Calificacion: " << raiz->dato.getCalificacion() << "\n";
            cout << "Semestre: " << raiz->dato.getSemestre() << "\n";
            cout << "-----------------------------------\n";
        }
        if (num < raiz->dato.getCalificacion()) // Es menor
        {
            buscar(raiz->izq, num);
        }
        else // Es mayor
        {
            buscar(raiz->der, num);
        }
    }
}
#endif