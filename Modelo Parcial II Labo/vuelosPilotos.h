#include "LinkedList.h"

void menuOpciones(LinkedList* listaDeVuelosOriginal, LinkedList* listaDePilotos);

void listarVuelos(LinkedList* listaDeVuelos, LinkedList* listaDePilotos);

void buscarIdPiloto(LinkedList* listaDePilotos, int idPiloto, char* auxNombre);

int cantidadDePasajeros(eVuelo* auxVuelo);

int cantidadDePasajerosIrlanda(eVuelo* auxVuelo);

int vuelosCortos(eVuelo* auxVuelo);

int guardarVuelosCortosEnArchivo(char* path, LinkedList* listaDeVuelos);

int generarListaVuelosPortugal(eVuelo* auxVuelo);

int generarListaSinAlexLifeson(eVuelo* auxVuelo);
