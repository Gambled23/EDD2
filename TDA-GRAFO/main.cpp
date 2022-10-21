#include <iostream>
#include <cstdlib>
#include "grafo.hpp"
#include "nodo.hpp"
#include "alumno.hpp"

/*TODO:
--Mostrar grafo
--Guardar
--Cargar
--Pasar dato a objeto
--Pasar nodo a privado
--buscar vertice
--buscar arista
Borrar grafo
*/

void menu();
grafo grafitoBonito;
alumno aluAux;
int ID = 1;

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
    string auxString;
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
        cout << "9) Eliminar datos guardados" << endl;
        cout << "10) Mostrar lista de conexiones" << endl;
        cout << "11) Eliminar datos locales"<<endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingresa nombre alumno: ";
            cin >> auxString;
            aluAux.setNombre(auxString);
            cout << "Ingresa calificacion alumno: ";
            cin >> auxInt;
            aluAux.setCalificacion(auxInt);
            aluAux.setId(ID);
            grafitoBonito.insertarVertice(aluAux);
            cout << "Se agregó con la ID " << ID << endl;
            ID++;
            break;
        case 2:
            cout << "Ingresa peso arista: ";
            cin >> auxInt;
            cout << "Ingresa ID origen arista: ";
            cin >> origen;
            cout << "Ingresa ID destino arista: ";
            cin >> destino;
            grafitoBonito.insertarArista(origen, destino, auxInt);
            break;
        case 3:
            cout << "Ingresa la ID del vertice a eliminar: ";
            cin >> auxInt;
            grafitoBonito.eliminarVertice(auxInt);
            break;
        case 4:
            cout << "Ingresa ID origen de arista a eliminar: ";
            cin >> origen;
            cout << "Ingresa ID destino de arista a eliminar: ";
            cin >> destino;
            grafitoBonito.eliminarArista(origen, destino);
            break;
        case 5:
        {
            cout << "Ingresa el ID de la vertice a buscar: ";
            cin >> auxInt;
            nodoVertice *auxVertice = grafitoBonito.buscarVertice(auxInt);
            if (auxVertice)
            {
                cout << "ID: " << auxVertice->dato.getId() << endl;
                cout << "Nombre: " << auxVertice->dato.getNombre() << endl;
                cout << "Calificacion: " << auxVertice->dato.getCalificacion() << endl;
            }
            else
            {
                cout << "Dato no encontrado\n";
            }
        }
        break;
        case 6:
        {
            cout << "Ingresa el ID origen de la arista a buscar: ";
            cin >> origen;
            cout << "Ingresa el ID destino de la arista a buscar: ";
            cin >> destino;
            nodoArista *auxArista = grafitoBonito.buscarArista(origen, destino);
            if (auxArista)
            {
                cout << "La arista solicitada tiene un peso de: " << auxArista->peso << endl;
            }
            else
            {
                cout << "La arista solicitada NO existe en el grafo\n";
            }
        }
        break;
        case 7:
            grafitoBonito.guardarDatos();
            break;
        case 8:
            ID = grafitoBonito.cargarDatos();
            break;
        case 9:
            grafitoBonito.eliminarDatos();
            break;
        case 10:
            grafitoBonito.mostrarConexiones();
            break;
        case 11:
            grafitoBonito.eliminarLocal();
            ID = 1;
            break;
        case 0:
            cout << "Gracias por su preferencia\n";
            break;
        case 69:
            aluAux.setId(1);
            aluAux.setNombre("pablo");
            aluAux.setCalificacion(98);
            grafitoBonito.insertarVertice(aluAux);
            aluAux.setId(2);
            aluAux.setNombre("cesar");
            aluAux.setCalificacion(96);
            grafitoBonito.insertarVertice(aluAux);
            aluAux.setId(3);
            aluAux.setNombre("alan");
            aluAux.setCalificacion(89);
            grafitoBonito.insertarVertice(aluAux);
            aluAux.setId(4);
            aluAux.setNombre("elias");
            aluAux.setCalificacion(74);
            grafitoBonito.insertarVertice(aluAux);
            aluAux.setId(5);
            aluAux.setNombre("massimo");
            aluAux.setCalificacion(82);
            grafitoBonito.insertarVertice(aluAux);
            grafitoBonito.insertarArista(1,2,51);
            grafitoBonito.insertarArista(1,3,51);
            grafitoBonito.insertarArista(1,4,51);
            grafitoBonito.insertarArista(3,5,51);
            grafitoBonito.insertarArista(5,3,51);
            grafitoBonito.insertarArista(2,1,51);
            break;
        default:
            cout << "Opcion invalida\n";
            break;
        }
        system("pause");
        system("cls");
    }
}