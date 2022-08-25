#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class alumno
{
public:
    alumno();
    alumno(int, string, bool);
private:
    int id;
    string nombre;
    bool activo;
};

alumno::alumno()
{
    id = 0;
    nombre = "";
    activo = false;
}
alumno::alumno(int idAl, string nombreAl, bool activoAl)
{
    id = idAl;
    nombre = nombreAl;
    activo = activoAl;
}
#endif