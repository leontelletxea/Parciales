#include "LinkedList.h"

typedef struct{
    int idPiloto;
    char nombre[51];
}ePiloto;

void harcodearPilotos(LinkedList* listaDeVuelos);

ePiloto* constructorPorDefectoPiloto();

ePiloto* constructorParametrizadoPiloto(int idPiloto, char* nombre);

int pilotoSetNombre(ePiloto* this, char* nombre);

int pilotoSetId(ePiloto* this, int idPiloto);

int pilotoGetNombre(ePiloto* this, char* nombre);

int pilotoGetId(ePiloto* this, int* idPiloto);

