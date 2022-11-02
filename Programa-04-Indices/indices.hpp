#ifndef INDICES_H
#define INDICES_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "persona.hpp"

#pragma once

using namespace std;

class indices
{
public:
    indices();
    int hash();
    void addRecord(persona);
    void writeIndex(persona);
    int hash(string, string);

private:
};

indices::indices()
{
}

void indices::addRecord(persona personaAux)
{
    fstream ayudaNoSeQueEstoyHaciendo("dataRecords.txt", ios::app);
    ayudaNoSeQueEstoyHaciendo.close();
    fstream recordFile("dataRecords.txt", ios::out | ios::in);
    if (recordFile.fail())
    {
        cout << "No se pudo abrir el archivo\n";
        system("pause");
        exit(EXIT_FAILURE);
    }
    recordFile.seekg(personaAux.indice, ios::beg);
    recordFile << personaAux.getPrimaryKey() << "|";
    recordFile << personaAux.getName() << "|";
    recordFile << personaAux.getAge() << "|";
    recordFile << personaAux.getPhone() << "*";
    recordFile.close();
}

void indices::writeIndex(persona personaAux)
{
    ofstream indexFile("indexLibrary.txt", ios::app);
    if (!indexFile)
    {
        cout << "No se pudo abrir el archivo\n";
        system("pause");
        exit(EXIT_FAILURE);
    }
    indexFile << personaAux.getPrimaryKey() << "|";
    indexFile << personaAux.indice << "*";
    indexFile.close();
}

int indices::hash(string prmKey, string age)
{
    // Hasheo basado en la sumatoria de el valor ascii de cada caracter * el segundo actual
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    int aux = timePtr->tm_sec;
    int sumatoria = 0;
    for (size_t i = 0; i < prmKey.size(); i++)
    {
        sumatoria = sumatoria + static_cast<int>(prmKey[i]);
    }
    return (sumatoria / stoi(age)) * aux;
}
#endif