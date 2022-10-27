#include <iostream>
#include <cstdlib>
#include "animal.hpp"

using namespace std;

void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    animal aniAux;
    int opc = 1, auxInt;
    string auxString;
    while (opc != 0)
    {
        system("cls");
        cout << "1) Insertar registro \n";
        cout << "2) Eliminar registro \n";
        cout << "3) Editar registro \n";
        cout << "4) Guardar datos\n";
        cout << "5) Cargar datos\n";
        cout << "6) ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout<<"Ingresa el nombre del animal: ";
            cin>>auxString;
            aniAux.setName(auxString);
            cout<<"Ingresa la edad del animal: ";
            cin>>auxInt;
            aniAux.setAge(auxInt);
            break;
        case 2:
            cout<<"Ingresa la ID del animal a eliminar: ";
            cin>>auxInt;
            break;
        case 3:
            cout<<"Ingresa la ID del animal a editar: ";
            cin>>auxInt;
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        default:
            break;
        }
    }
}