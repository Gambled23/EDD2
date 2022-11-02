#include <iostream>
#include <cstdlib>
#include "persona.hpp"
#include "indices.hpp"

/*TODO
//Funcion hash
//Archivo de indices
Ver registros
*/
using namespace std;

void menu();

indices indiceAux;

int main()
{
    menu();
    return 0;
}

void menu()
{
    persona personaAux;
    int opc = 1;
    string auxString;
    while (opc != 0)
    {
        system("cls");
        cout << "1) Insertar registro \n";
        cout << "2) Eliminar registro \n";
        cout << "3) Editar registro \n";
        cout << "4) Guardar datos\n";
        cout << "5) Cargar datos\n";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            cout<<"Ingresa el nombre de la persona: ";
            cin>>auxString;
            personaAux.setName(auxString);
            cout<<"Ingresa la edad de la persona: ";
            cin>>auxString;
            personaAux.setAge(auxString);
            cout<<"Ingresa el telefono de la persona (10 digitos): ";
            cin>>auxString;
            personaAux.setPhone(auxString);
            string primaryKey = personaAux.generateKey(personaAux);
            personaAux.setPrimaryKey(primaryKey);
            personaAux.indice = indiceAux.hash(primaryKey, personaAux.getAge());
            //Agregar a archivo de registros
            indiceAux.addRecord(personaAux);
            //Agregar a archivo de indices
            indiceAux.writeIndex(personaAux);
            break;
        }
        case 2:
            cout<<"Ingresa la ID del animal a eliminar: ";
            cin>>auxString;
            break;
        case 3:
            cout<<"Ingresa la ID del animal a editar: ";
            cin>>auxString;
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
        system("pause");
    }
}