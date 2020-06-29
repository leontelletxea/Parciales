#include "LinkedList.h"

void menuOpciones(LinkedList* listaDeVuelosOriginal, LinkedList* listaDePilotos);

void imprimirVuelos(LinkedList* listaDeVuelos, LinkedList* listaDePilotos);

void asociarIdPiloto(LinkedList* listaDePilotos, int idPiloto, char* auxNombre);

int cantidadDePasajeros(eVuelo* auxVuelo);

int cantidadDePasajerosIrlanda(eVuelo* auxVuelo);

int filtrarVuelosCortos(char* path, LinkedList* listaDeVuelos, LinkedList* listaDePilotos);

int generarListaVuelosPortugal(eVuelo* auxVuelo);

int generarListaSinAlexLifeson(eVuelo* auxVuelo);
