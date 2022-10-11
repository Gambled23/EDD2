#include "Grafo.h"

void Grafo::insertarVertice(string nomVer)
{
    NodoVertice *aux = new NodoVertice(nomVer, nullptr, nullptr);
    NodoVertice *tmp = h_grafo;
    if (!tmp)
    {
        h_grafo = aux; // primer vertice
    }
    else
    {
        while (tmp->sigVertice)
        {
            tmp = tmp->sigVertice;
        }
        tmp->sigVertice = aux;
    }
}
void Grafo::insertarArista(string origen, string destino, int peso)
{
    NodoVertice *tmpVer = h_grafo;
    NodoArista *tmpArista = nullptr;
    bool bandera = true;
    while (tmpVer and bandera)
    { // asegurando que asista
        if (tmpVer->nombreVertice == origen)
        { // si encontramos el dato cortamos
            bandera = false;
        }
        else
        {
            tmpVer = tmpVer->sigVertice;
        }
    }
    if (tmpVer)
    { // si existe podemos ver el listado de aristas, tenemos origen.
        tmpArista = tmpVer->h_arista;
        if (!tmpArista)
        {
            NodoVertice *dest = buscarVertice(destino);
            if (dest)
            {
                NodoArista *aux = new NodoArista(peso, dest, nullptr);
                tmpVer->h_arista = aux;
            }
            else
            {
                cout << "Destino no encontrado!" << endl;
            }
        }
        else
        {
            NodoVertice *dest = buscarVertice(destino);
            if (dest)
            {
                NodoArista *aux = new NodoArista(peso, dest, nullptr);
                aux->sigArista = tmpVer->h_arista;
                tmpVer->h_arista = aux; // inserccion al principio
            }
            else
            {
                cout << "Destino no encontrado!" << endl;
            }
        }
    }
    else
    {
        cout << "Origen no encontrado" << endl;
    }
}
NodoVertice *Grafo::buscarVertice(string nom)
{
    NodoVertice *tmp = h_grafo;
    while (tmp)
    { // aqui andaria la bandera
        if (tmp->nombreVertice == nom)
        {
            return tmp; // sustituir por bandera
        }
        else
        {
            tmp = tmp->sigVertice;
        }
    }
    return nullptr;
}
void Grafo::mostrarG()
{
    NodoVertice *tmpVer = h_grafo;
    NodoArista *tmpArista = nullptr;
    while (tmpVer)
    {
        tmpArista = tmpVer->h_arista;
        cout << "---- Origen ----" << tmpVer->nombreVertice << "----";
        while (tmpArista)
        {
            cout << " ** " << tmpArista->destino->nombreVertice << "";
            tmpArista = tmpArista->sigArista;
        }
        cout << endl;
        tmpVer = tmpVer->sigVertice;
    }
}
