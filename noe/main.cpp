#include <iostream>
#include "Grafo.h"
using namespace std;

int main()
{
    Grafo g;
    g.insertarVertice("uno");
    g.insertarVertice("dos");
    g.insertarVertice("tres");
    g.insertarVertice("cuatro");
    g.insertarArista("uno","cuatro",7);
    g.insertarArista("uno","cuatro",6);
    g.insertarArista("dos","uno",2);
    g.mostrarG();
    system("pause");
    return 0;
}
