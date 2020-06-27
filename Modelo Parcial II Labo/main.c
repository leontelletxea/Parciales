#include <stdio.h>
#include <stdlib.h>
#include "vuelos.h"
#include "pilotos.h"
#include "vuelosPilotos.h"
#include "LinkedList.h"

int main()
{
    LinkedList* listaDeVuelos = ll_newLinkedList();
    LinkedList* listaDePilotos = ll_newLinkedList();

    cargarPilotos(listaDePilotos);

    menuOpciones(listaDeVuelos, listaDePilotos);


    return 0;
}
