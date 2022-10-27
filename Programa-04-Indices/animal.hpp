#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class animal
{
public:
    animal();
    animal(string, int, int);
    void setName(string name){ this->name = name;}
    void setAge(int age){this->age = age;}
    void setPrimaryKey(int primaryKey){this->primaryKey = primaryKey;}
    string getName(){return name;}
    int getAge(){return age;}
    int getPrimaryKey(){return primaryKey;}

private:
    string name;
    int age;
    int primaryKey;

};

animal::animal()
{

}

animal::animal(string name, int age, int primaryKey)
{
    this->name = name;
    this->age = age;
    this->primaryKey = primaryKey;
}
#endif