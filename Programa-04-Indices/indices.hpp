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

#endif