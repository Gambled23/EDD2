#include <iostream>
#include "listaSimple.hpp"

using namespace std;

void menu();
listaSimple *lista = new listaSimple(); //?Crea una nueva lista

int main()
{
    menu();
    system("PAUSE");
    return 0;
}

void menu()
{
    int opc = 1;
    string dato;
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
            cout << "Ingrese un dato: ";
            cin >> dato;
            lista->insertaInicio(dato);
            break;
        case 2:
            cout << "Ingrese un dato: ";
            cin >> dato;
            lista->insertarFinal(dato);
            break;
        case 3:
            lista->mostrarLista();
            break;
        case 4:
            cout << "Ingrese el elemento a buscar: ";
            cin >> dato;
            lista->buscarElemento(dato);
            break;
        case 5:
            cout << "Ingrese el elemento a eliminar: ";
            cin >> dato;
            lista->eliminarElemento(dato);
            break;
        case 6:
            lista->eliminarLista(dato);
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