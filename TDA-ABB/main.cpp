#include <iostream>
#include <cstdlib>
#include "arbol.hpp"
#include "Nodo.hpp"

using namespace std;

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
    int auxInt;
    while (opc != 0)
    {
        cout << "0) Salir" << endl;
        cout << "1) Insertar elemento" << endl;
        cout << "2) " << endl;
        cout << "3) Mostrar en preorden" << endl;
        cout << "4) Mostrar en orden" << endl;
        cout << "5) Mostrar en postorden" << endl;
        cout << "6) " << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Cual dato quieres ingresar?\n";
            cin >> auxInt;
            Arbolote.insertar(Arbolote.raiz, auxInt);
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
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}