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
    int getCalificacion();
    void setCalificacion(int);
    string getNombre();
    void setNombre(string);
    int getId();
    void setId(int);

private:
    int calificacion;
    string nombre;
    int id;
};

alumno::alumno()
{
    calificacion = 0;
    nombre = "";
    id = 0;
}
int alumno::getCalificacion()
{
    return calificacion;
}
void alumno::setCalificacion(int calAl)
{
    calificacion = calAl;
}
string alumno::getNombre()
{
    return nombre;
}
void alumno::setNombre(string nombreAl)
{
    nombre = nombreAl;
}
int alumno::getId()
{
    return id;
}
void alumno::setId(int idAl)
{
    id = idAl;
}
#endif