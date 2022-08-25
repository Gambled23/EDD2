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
    int getId();
    void setId(int);
    string getNombre();
    void setNombre(string);
    bool getActivo();
    void setActivo(bool);

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
int alumno::getId()
{
    return id;
}
void alumno::setId(int idAl)
{
    id = idAl;
}
string alumno::getNombre()
{
    return nombre;
}
void alumno::setNombre(string nombreAl)
{
    nombre = nombreAl;
}
bool alumno::getActivo()
{
    return activo;
}
void alumno::setActivo(bool activoAl)
{
    activo = activoAl;
}
#endif