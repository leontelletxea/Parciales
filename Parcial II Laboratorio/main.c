#include <stdio.h>
#include <stdlib.h>
#include "vuelos.h"
#include "pilotos.h"
#include "controller.h"
#include "parser.h"
#include "LinkedList.h"

int main()
{
    LinkedList* listaDeVuelosOriginal = ll_newLinkedList();
    LinkedList* listaDePilotos = ll_newLinkedList();

    Controller_cargarDesdeTextoPilotos(listaDePilotos);

    Controller_menuOpciones(listaDeVuelosOriginal, listaDePilotos);

    return 0;
}
