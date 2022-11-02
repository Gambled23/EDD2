#ifndef INDICES_H
#define INDICES_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "persona.hpp"
#pragma once

using namespace std;

class indices
{
public:
    indices();
    int hash();
    void addRecord(persona);
    int hash(string, string);
private:
};

indices::indices()
{
}

void indices::addRecord(persona personaAux)
{
    ofstream recordFile("dataRecords.txt", ios::app);
    if (!recordFile)
    {
        cout << "No se pudo abrir el archivo\n";
        exit(EXIT_FAILURE);
    }
    recordFile << personaAux.getPrimaryKey() << "|";
    recordFile << personaAux.getName() << "|";
    recordFile << personaAux.getAge() << "|";
    recordFile << personaAux.getPhone() << "*";
}

int indices::hash(string prmKey, string age)
{
    //Hasheo basado en la sumatoria de el valor ascii de cada caracter
    int sumatoria = 0;
    for (size_t i = 0; i < prmKey.size(); i++)
    {
        sumatoria = sumatoria + static_cast<int>(prmKey[i]);
    }
    return sumatoria * stoi(age);
}
#endif