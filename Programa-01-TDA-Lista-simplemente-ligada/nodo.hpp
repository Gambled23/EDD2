#ifndef NODO_H
#define NODO_H
#pragma once
#include "alumno.hpp"
using namespace std; 

class nodo
{
public:
    alumno dato;
    nodo *sig;
    nodo();
    nodo(alumno e)
    {
        dato = e;
        sig = nullptr;
    };

private:
};
nodo::nodo()
{
    sig = nullptr;
}
#endif