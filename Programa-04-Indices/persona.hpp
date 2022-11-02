#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class persona
{
public:
    persona();
    persona(string, string, string);
    string generateKey(persona);
    string getPrimaryKey() { return primaryKey; }
    string getName() { return name; }
    string getAge() { return age; }
    string getPhone() { return phone; }
    void setPrimaryKey(string pk) { primaryKey = pk; }
    void setName(string nm) { name = nm; }
    void setAge(string ag) { age = ag; }
    void setPhone(string ph) { phone = ph; }
    int indice;
private:
    string primaryKey;
    string name;
    string age;
    string phone;
};

persona::persona()
{
}
persona::persona(string nm, string ag, string ph)
{
    name = nm;
    age = ag;
    phone = ph;
}

string persona::generateKey(persona personaAux)
{
    // Obtiene una clave con las primeras 2 letras del nombre, los ultimos 2 digitos de telefono, y la edad
    char auxChar = personaAux.name.at(0);
    string key(1, auxChar);
    auxChar = personaAux.name.at(1);
    string keyAux(1, auxChar);
    key = key + keyAux;
    auxChar = personaAux.phone.at(8);
    string keyAux2(1, auxChar);
    key = key + keyAux2;
    auxChar = personaAux.phone.at(9);
    string keyAux3(1, auxChar);
    key = key + keyAux3;
    key = key + personaAux.age;
    return key;
}
#endif