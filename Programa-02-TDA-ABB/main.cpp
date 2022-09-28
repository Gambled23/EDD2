#include <iostream>
#include <cstdlib>
#include "arbol.hpp"
#include "Nodo.hpp"
#include "alumno.hpp"

using namespace std;

/*
TODO
//Eliminar raiz
//Eliminar todo el arbol
//Guardar
//Cargar
*/

arbol Arbolote;

void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int opc = 1;
    alumno auxAlu;
    int auxInt;
    string auxString;
    while (opc != 0)
    {
        cout << "0) Salir" << endl;
        cout << "1) Insertar elemento" << endl;
        cout << "2) Eliminar" << endl;
        cout << "3) Mostrar en preorden" << endl;
        cout << "4) Mostrar en orden" << endl;
        cout << "5) Mostrar en postorden" << endl;
        cout << "6) Guardar datos" << endl;
        cout << "7) Cargar datos" << endl;
        cout << "8) Eliminar arbol completo" << endl;
        cout << "9) Buscar" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese nombre del alumno\n";
            cin >> auxString;
            auxAlu.setNombre(auxString);
            cout << "Ingrese calificacion del alumno\n";
            cin >> auxInt;
            auxAlu.setCalificacion(auxInt);
            cout << "Ingrese semestre del alumno\n";
            cin >> auxString;
            auxAlu.setSemestre(auxString);
            Arbolote.insertar(Arbolote.raiz, auxAlu, nullptr);
            break;
        case 2:
            cout << "Cual es la calificacion que quieres eliminar?\n";
            cin >> auxInt;
            auxAlu.setCalificacion(auxInt);
            Arbolote.eliminar(Arbolote.raiz, auxAlu);
            break;
        case 3:
            Arbolote.preorden(Arbolote.raiz);
            break;
        case 4:
            Arbolote.orden(Arbolote.raiz);
            break;
        case 5:
            Arbolote.postorden(Arbolote.raiz);
            break;
        case 6:
            Arbolote.guardar();
            break;
        case 7:
            Arbolote.cargar();
            break;
        case 8:
            Arbolote.eliminarArbol();
            break;
        case 9:
            cout << "Cual calificacion quieres buscar?\n";
            cin >> auxInt;
            Arbolote.buscar(Arbolote.raiz, auxInt);
            break;
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}