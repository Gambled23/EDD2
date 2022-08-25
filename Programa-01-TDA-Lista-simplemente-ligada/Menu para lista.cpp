#include <iostream>
#include <cstdlib>
#include "alumno.hpp"
#include "listaSimple.hpp" //!No compila con la lista
using namespace std;

void menu();
listaSimple *lista = new listaSimple();
alumno aluTemp;


int main()
{
    menu();
    return 0;
}

void menu()
{
    int opc = 1, auxInt;
    string auxString;
    while (opc != 0)
    {
        system("cls");
        cout << "\tMenu\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar lista\n";
        cout << "4. Buscar un elemento\n";
        cout << "5. Eliminar elemento\n";
        cout << "6. Vaciar lista\n";
        cout << "7. Mostrar tamano lista\n";
        cout << "0. Salir\n\n";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese el nombre del alumno: ";
            cin>>auxString;
            aluTemp.setNombre(auxString);
            cout<<"El alumno esta activo?\n  1)Si  2)No\n";
            cin>>auxInt;
            if (auxInt == 1)
            {
                aluTemp.setActivo(true);
            }
            else if (auxInt == 2)
            {
                aluTemp.setActivo(false);
            }
            else
            {
                cout<<"Opcion invalida\n";
                break;
            }
            lista->insertaInicio(aluTemp);
            break;
        
        case 2:
            cout << "Ingrese el nombre del alumno: ";
            cin>>auxString;
            aluTemp.setNombre(auxString);
            cout<<"El alumno esta activo?\n  1)Si  2)No\n";
            cin>>auxInt;
            if (auxInt == 1)
            {
                aluTemp.setActivo(true);
            }
            else if (auxInt == 2)
            {
                aluTemp.setActivo(false);
            }
            else
            {
                cout<<"Opcion invalida\n";
                break;
            }
            lista->insertarFinal(aluTemp);
            break;
        case 3:
            lista->mostrarLista();
            break;
        
        case 4:
            cout << "Ingrese el ID del alumno a buscar: ";
            cin >> auxInt;
            lista->buscarElemento(auxInt);
            break;
        
        case 5:
            cout << "Ingrese el ID del alumno a eliminar: ";
            cin >> auxInt;
            lista->eliminarElemento(auxInt);
            break;
        case 6:
            lista->eliminarLista();
            break;
        case 7:
            lista->tamanoLista();
            break;
        case 0:
            cout << "Gracias por su preferencia\n";
            break;
        default:
            cout << ("La opcion solicitada no existe\n");
            break;
        }
        system("PAUSE");
    }
}