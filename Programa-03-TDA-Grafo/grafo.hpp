#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
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
    void guardarDatos();
    int cargarDatos();
    void eliminarDatos();
    void eliminarLocal();
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
        if (tmp->dato.getId() == e)
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
                if (auxArista->destino->dato.getId() == dst) // Encontro el destino
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
            if (tmpArista->destino->dato.getId() == dst) // Encontro el destino
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
        cout << "Vertice id: " << tmpVertice->dato.getId() << endl;
        cout << "Nombre: " << tmpVertice->dato.getNombre() << endl;
        cout << "Calificacion: " << tmpVertice->dato.getCalificacion() << endl;
        cout << "Lista de aristas\n";
        while (tmpArista)
        {
            cout << "ID destino: " << tmpArista->destino->dato.getId() << "\tPeso: " << tmpArista->peso << "\n";
            tmpArista = tmpArista->sigArista;
        }
        cout << "\n--------------------\n\n";
        tmpVertice = tmpVertice->sig;
    }
}

void grafo::guardarDatos()
{
    nodoVertice *vtcAux = hGrafo;
    nodoArista *astAux;
    if (vtcAux)
    {
        string cadena, registro, campo;
        alumno aluAux;
        ofstream archivoGrafo;
        archivoGrafo.open("file01.txt", ios::out);
        ofstream archivoAristas;
        archivoAristas.open("file02.txt", ios::out);
        if (archivoGrafo.fail() or archivoAristas.fail())
        {
            cout << "No se pudo abrir el archivo";
            exit(1);
        }
        while (vtcAux)
        {
            archivoGrafo << vtcAux->dato.getId() << "|";
            archivoGrafo << vtcAux->dato.getNombre() << "|";
            archivoGrafo << vtcAux->dato.getCalificacion() << "*";
            astAux = vtcAux->hArista;
            while (astAux) // Guardar aristas
            {
                archivoAristas << vtcAux->dato.getId() << "|";
                archivoAristas << astAux->destino->dato.getId() << "|";
                archivoAristas << astAux->peso << "*";
                astAux = astAux->sigArista;
            }
            vtcAux = vtcAux->sig;
        }
        archivoGrafo.close();
        archivoAristas.close();
        cout << "Los datos han sido guardados\n";
    }
    else
    {
        cout << "No se puede guardar un grafo vacio\n";
    }
}

int grafo::cargarDatos()
{
    string cadena, registro, campo;
    int aux = 1, idTemp;
    alumno aluAux;
    ifstream archivoGrafo;

    // Cargar vertices
    archivoGrafo.open("file01.txt", ios::in);
    if (archivoGrafo.fail())
    {
        cout << "No se pudo abrir el archivo\n";
        exit(1);
    }
    while (!archivoGrafo.eof()) // Mientras no sea el end of file
    {
        getline(archivoGrafo, cadena);
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
                aluAux.setId(stoi(campo));
                idTemp = aluAux.getId() + 1;
                break;
            case 2:
                aluAux.setNombre(campo);
                break;
            case 3:
                aluAux.setCalificacion(stoi(campo));
                break;
            }
            aux++;
        }
        insertarVertice(aluAux);
    }
    archivoGrafo.close();
    // Cargar aristas
    int origen, destino, peso;
    archivoGrafo.open("file02.txt", ios::in);
    if (archivoGrafo.fail())
    {
        cout << "No se pudo abrir el archivo\n";
        exit(1);
    }
    while (!archivoGrafo.eof()) // Mientras no sea el end of file
    {
        getline(archivoGrafo, cadena);
    }
    stringstream cadenaStream2(cadena);
    while (getline(cadenaStream2, registro, '*'))
    {
        aux = 1;
        stringstream registroStream2(registro);
        while (getline(registroStream2, campo, '|'))
        {
            switch (aux)
            {
            case 1:
                origen = stoi(campo);
                break;
            case 2:
                destino = stoi(campo);
                break;
            case 3:
                peso = (stoi(campo));
                break;
            }
            aux++;
        }
        insertarArista(origen, destino, peso);
    }
    archivoGrafo.close();
    cout << "Los datos han sido cargados exitosamente" << endl;
    return idTemp;
}

void grafo::eliminarDatos()
{
    int opc = 2;
    cout << "Esta accion es irreversible y borrara todos los datos de respaldo, seguro que quieres continuar?\n";
    cout << "   1)Si  2)No\n";
    cin >> opc;
    if (opc == 1)
    {
        ofstream archivoGrafo;
        archivoGrafo.open("file01.txt", std::ofstream::out | std::ofstream::trunc);
        archivoGrafo.close();
        archivoGrafo.open("file02.txt", std::ofstream::out | std::ofstream::trunc);
        archivoGrafo.close();
        cout << "Los datos guardados han sido eliminados" << endl;
    }
    else
    {
        cout << "Regresando al menu principal...\n";
    }
}

void grafo::eliminarLocal()
{
    nodoVertice *vtcAux = hGrafo;
    nodoArista *astAux;
    if (hGrafo)
    {
        while (hGrafo)
        {
            vtcAux = hGrafo;
            while (vtcAux->hArista) //Borrar todas las aristas
            {
                astAux = vtcAux->hArista;
                vtcAux->hArista = vtcAux->hArista->sigArista;
                delete astAux;
            }
            hGrafo = hGrafo->sig;
            delete vtcAux;
        }
    }
    cout<<"Datos borrados\n";
}
#endif