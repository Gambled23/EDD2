#include <iostream>
#include <cstdlib>

using namespace std;

void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int opc = 1;
    while (opc != 0)
    {
        system("cls");
        cout<<"1) Insertar registro \n";
        cout<<"2) Eliminar registro \n";
        cout<<"3) Editar registro \n";
        cout<<"4) Guardar datos\n";
        cout<<"5) Cargar datos\n";
        cout<<"6) ";
        cin>>opc;
    }
    
}