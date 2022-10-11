#ifndef GRAFO_H
#define GRAFO_H
#include "nodo.h"

class Grafo
{
    public:
        NodoVertice *h_grafo;
        Grafo():h_grafo{nullptr}{};
        Grafo(NodoVertice * ptr):h_grafo{ptr}{}
        void insertarVertice(string nom);
        void insertarArista(string origen, string destino, int peso);
        NodoVertice* buscarVertice(string nom);
        void mostrarG();
    protected:

    private:
};

#endif // GRAFO_H
