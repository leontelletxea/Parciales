#include <stdio.h>
#include <stdlib.h>
#include "vuelos.h"
#include "pilotos.h"
#include "vuelosPilotos.h"
#include "LinkedList.h"

int main()
{
    LinkedList* listaDeVuelos = ll_newLinkedList();

    agregarPilotos(listaDeVuelos);

    menuOpciones(listaDeVuelos);


    return 0;
}
