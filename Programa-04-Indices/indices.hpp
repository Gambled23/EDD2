#ifndef INDICES_H
#define INDICES_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>
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
    void searchRecord(string);
    void showRecords();
    int searchIndex(string);
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
    sumatoria = (sumatoria / stoi(age)) * aux;
    return sumatoria;
}

int indices::searchIndex(string key)
{
    ifstream indexFile("indexLibrary.txt", ios::in);
    string text, record, field;
    int aux = 1, index; // Index tiene la posicion en donde está el dato
    bool foundKey = false;
    // Buscar indice
    if (indexFile.fail())
    {
        cout << "No se pudo abrir el archivo\n";
        exit(1);
    }
    while (!indexFile.eof()) // Mientras no sea el end of file
    {
        getline(indexFile, text);
    }
    stringstream textStream(text);
    while (getline(textStream, record, '*'))
    {
        aux = 1;
        stringstream recordStream(record);
        while (getline(recordStream, field, '|'))
        {
            switch (aux)
            {
            case 1:
                if (key == field)
                {
                    foundKey = true;
                }
                else
                {
                    foundKey = false;
                }
                break;
            case 2:
                if (foundKey)
                {
                    index = stoi(field);
                }
                break;
            default:
                break;
            }
            aux++;
        }
    }
    indexFile.close();
    return index;
}

void indices::searchRecord(string key)
{
    int index = searchIndex(key); // Buscar la posicion del record en el archivo
    
}

void indices::showRecords()
{
    ifstream indexFile("dataRecords.txt", ios::in);
    string textString, record, field;
    int aux = 1;
    if (indexFile.fail())
    {
        cout << "No se pudo abrir el archivo\n";
        exit(1);
    }
    while (!indexFile.eof()) // Mientras no sea el end of file
    {
        getline(indexFile, textString);
    }
    stringstream textStringStream(textString);
    while (getline(textStringStream, record, '*'))
    {
        aux = 1;
        stringstream recordStream(record);
        while (getline(recordStream, field, '|'))
        {
            switch (aux)
            {
            case 1:
                cout<<"Codigo: "<<field<<endl;
                break;
            case 2: //Nombre
                cout<<"Nombre: "<<field<<endl;
                break;
            case 3: //Edad
                cout<<"Edad: "<<field<<endl;
                break;
            case 4: //Telefono
                cout<<"Telefono: "<<field<<endl<<endl;
                break;
            default:
                break;
            }
            aux++;
        }
    }
    indexFile.close();
}

#endif