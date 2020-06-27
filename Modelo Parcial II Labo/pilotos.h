#include "LinkedList.h"
#include "vuelosPilotos.h"

typedef struct{
    int idPiloto;
    char nombre[51];
}ePiloto;

void agregarPilotos(LinkedList* listaDeVuelos);

ePiloto* constructorPorDefectoPiloto();

ePiloto* constructorParametrizadoPiloto(int idPiloto, char* nombre);

int pilotoSetNombre(ePiloto* this, char* nombre);

int pilotoSetId(ePiloto* this, int idPiloto);


