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
    string getSemestre();
    void setSemestre(string);

private:
    int calificacion;
    string nombre;
    string semestre;
};

alumno::alumno()
{
    calificacion = 0;
    nombre = "";
    semestre = "";
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
string alumno::getSemestre()
{
    return semestre;
}
void alumno::setSemestre(string semestreAl)
{
    semestre = semestreAl;
}
#endif