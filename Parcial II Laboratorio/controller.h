#include "LinkedList.h"

int Controller_Tellechea_cargarDesdeTextoVuelos(LinkedList* listaDeVuelos);

int Controller_Tellechea_guardarEnTexto(LinkedList* listaDeVuelos);

int Controller_Tellechea_cargarDesdeTextoPilotos(LinkedList* listaDePilotos);

void Controller_Tellechea_listarVuelos(LinkedList* listaDeVuelos, LinkedList* listaDePilotos);

void Controller_Tellechea_buscarIdPiloto(LinkedList* listaDePilotos, int idPiloto, char* auxNombre);

int Controller_Tellechea_cantidadDePasajeros(eVuelo* auxVuelo);

int Controller_Tellechea_cantidadDePasajerosIrlanda(eVuelo* auxVuelo);

int Controller_Tellechea_vuelosCortos(eVuelo* auxVuelo);

int Controller_Tellechea_guardarVuelosCortosEnArchivo(FILE* pFile, LinkedList* listaDeVuelos);

int Controller_Tellechea_criterioListaVuelosPortugal(eVuelo* auxVuelo, char* destino);

int Controller_Tellechea_generarListaSinAlexLifeson(eVuelo* auxVuelo);

int Controller_Tellechea_generarListaPilotos(FILE* pFile, LinkedList* listaDePilotos);

void Controller_Tellechea_menuOpciones(LinkedList* listaDeVuelosOriginal, LinkedList* listaDePilotos);

LinkedList* Controller_Tellechea_pedirNombre(LinkedList* listaDePilotos);

int Controller_Tellechea_filtrarPilotoPorNombre(ePiloto* auxPiloto, char* nombre);

void Controller_Tellechea_listarPilotos(LinkedList* listaDePilotos);

LinkedList* Controller_Tellechea_listaDeVuelosPortugal(LinkedList* listaDeVuelos);
