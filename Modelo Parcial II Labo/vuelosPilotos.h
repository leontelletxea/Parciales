#include "LinkedList.h"

void menuOpciones(LinkedList* listaDeVuelosOriginal, LinkedList* listaDePilotos, LinkedList* listaDeVuelosPortugal, LinkedList* listaDeVuelosSinAlexLifeson);

void imprimirVuelos(LinkedList* listaDeVuelos, LinkedList* listaDePilotos);

void asociarIdPiloto(LinkedList* listaDePilotos, int idPiloto, char* auxNombre);

void cantidadDePasajeros(LinkedList* listaDeVuelos);

void cantidadDePasajerosIrlanda(LinkedList* listaDeVuelos);

int filtrarVuelosCortos(char* path, LinkedList* listaDeVuelos, LinkedList* listaDePilotos);

int generarListaVuelosPortugal(LinkedList* listaDeVuelos, LinkedList* listaDeVuelosPortugal);

int generarListaSinAlexLifeson(LinkedList* listaDeVuelos, LinkedList* listaDeVuelosSinAlexLifeson, LinkedList* listaDePilotos);
