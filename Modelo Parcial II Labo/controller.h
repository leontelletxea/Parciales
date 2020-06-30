#include "LinkedList.h"

int Controller_cargarDesdeTextoVuelos(LinkedList* listaDeVuelos);

int Controller_guardarEnTexto(LinkedList* listaDeVuelos);

int Controller_cargarDesdeTextoPilotos(LinkedList* listaDePilotos);

void Controller_listarVuelos(LinkedList* listaDeVuelos, LinkedList* listaDePilotos);

void Controller_buscarIdPiloto(LinkedList* listaDePilotos, int idPiloto, char* auxNombre);

int Controller_cantidadDePasajeros(eVuelo* auxVuelo);

int Controller_cantidadDePasajerosIrlanda(eVuelo* auxVuelo);

int Controller_vuelosCortos(eVuelo* auxVuelo);

int Controller_guardarVuelosCortosEnArchivo(FILE* pFile, LinkedList* listaDeVuelos);

int Controller_generarListaVuelosPortugal(eVuelo* auxVuelo);

int Controller_generarListaSinAlexLifeson(eVuelo* auxVuelo);

int Controller_generarListaPilotos(FILE* pFile, LinkedList* listaDePilotos);

void Controller_menuOpciones(LinkedList* listaDeVuelosOriginal, LinkedList* listaDePilotos);

LinkedList* Controller_listarPilotos(LinkedList* listaDePilotos);

int Controller_filtrarPilotoPorNombre(ePiloto* auxPiloto, char* nombre);

void listarPilotos(LinkedList* listaDePilotos);
