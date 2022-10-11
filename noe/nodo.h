#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;
class NodoVertice;
class NodoArista{
    public:
        int peso;
        NodoVertice * destino;
        NodoArista * sigArista;
        NodoArista():peso{0},destino{nullptr}, sigArista{nullptr}{}
        NodoArista(int peso, NodoVertice*destino, NodoArista*sigArista):peso{peso},
        destino{destino}, sigArista{sigArista}{}
    protected:
    private:

};
class NodoVertice{
    public:
        string nombreVertice;
        NodoArista* h_arista;
        NodoVertice* sigVertice;
        //inicializaci�n.
        NodoVertice():nombreVertice{" "}, h_arista{nullptr}, sigVertice{nullptr}{};
        NodoVertice(string nom, NodoArista*arista, NodoVertice*ver):nombreVertice{nom},h_arista{arista},sigVertice{ver}{}
    protected:

    private:
};

#endif // NODO_H
