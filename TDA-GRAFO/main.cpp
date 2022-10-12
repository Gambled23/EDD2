#include <iostream>
#include <cstdlib>
#include "grafo.hpp"
#include "nodo.hpp"

/*TODO:
Mostrar grafo
Guardar
Cargar
Pasar dato a objeto
Pasar nodo a privado
--buscar vertice
buscar arista
*/

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
        cout << "5) Buscar vertice" << endl;
        cout << "6) Buscar arista" << endl;
        cout << "7) Guardar datos" << endl;
        cout << "8) Cargar datos" << endl;
        cout << "9) Eliminar grafo completo" << endl;
        cout << "10) Mostrar lista de conexiones" << endl;
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
            cout << "Ingresa el vertice a eliminar: ";
            cin >> auxInt;
            grafitoBonito.eliminarVertice(auxInt);
            break;
        case 4:
            cout << "Ingresa origen de arista a eliminar: ";
            cin >> origen;
            cout << "Ingresa destino de arista a eliminar: ";
            cin >> destino;
            grafitoBonito.eliminarArista(origen, destino);
            break;
        case 5:
            cout<<"Ingresa el dato del vertice a buscar: ";
            cin>>auxInt;
            nodoVertice *auxVertice = grafitoBonito.buscarVertice(auxInt);
            if (auxVertice)
            {
                cout<<"Dato: "<<auxVertice->dato<<endl;
            }
            else
            {
                cout<<"Dato no encontrado\n";
            }
            
            break;
        case 6:
            cout<<"Ingresa el origen de la arista a buscar: ";
            cin>>origen;
            cout<<"Ingresa el destino de la arista a buscar: ";
            cin>>destino;
            cout<<"Ingresa el peso de la arista a buscar: ";
            cin>>auxInt;
            nodoArista *auxArista = grafitoBonito.buscarArista(origen,destino,auxInt);
            if (auxArista)
            {
                cout<<"La arista solicitada SI existe en el grafo\n";
            }
            else
            {
                cout<<"La arista solicitada NO existe en el grafo\m";
            }
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