#include <iostream>
#include <cstdlib>
#include "grafo.hpp"
#include "nodo.hpp"

void menu();
grafo grafitoBonito;

using namespace std;
int main()
{
    menu();
    return 0;
}

void menu()
{
    int opc = 1;
    int auxInt, destino, origen;

    while (opc != 0)
    {
        cout << "0) Salir" << endl;
        cout << "1) Insertar vertice" << endl;
        cout << "2) Insertar arsita" << endl;
        cout << "3) Eliminar vertice" << endl;
        cout << "4) Eliminar arista" << endl;
        cout << "5) Buscar dato" << endl;
        cout << "6) Guardar datos" << endl;
        cout << "7) Cargar datos" << endl;
        cout << "8) Eliminar grafo completo" << endl;
        cout << "9) Mostrar lista de conexiones" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingresa vertice: ";
            cin >> auxInt;
            grafitoBonito.insertarVertice(auxInt);
            break;
        case 2:
            cout << "Ingresa peso arista: ";
            cin >> auxInt;
            cout << "Ingresa origen arista: ";
            cin >> origen;
            cout << "Ingresa destino arista: ";
            cin >> destino;
            grafitoBonito.insertarArista(origen, destino, auxInt);
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:
            grafitoBonito.mostrarConexiones();
            break;
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}