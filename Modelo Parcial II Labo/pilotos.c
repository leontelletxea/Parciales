#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilotos.h"

void harcodearPilotos(LinkedList* listaDePilotos)
{
    ePiloto* auxPiloto;

    if(listaDePilotos != NULL)
    {
        auxPiloto = constructorParametrizadoPiloto(1, "Alex Lifeson");
        ll_add(listaDePilotos, auxPiloto);
        auxPiloto = constructorParametrizadoPiloto(2, "Richard Bach");
        ll_add(listaDePilotos, auxPiloto);
        auxPiloto = constructorParametrizadoPiloto(3, "John Kerry");
        ll_add(listaDePilotos, auxPiloto);
        auxPiloto = constructorParametrizadoPiloto(4, "Erwin Rommel");
        ll_add(listaDePilotos, auxPiloto);
        auxPiloto = constructorParametrizadoPiloto(5, "Stephen Coonts");
        ll_add(listaDePilotos, auxPiloto);
    }
}

ePiloto* constructorPorDefectoPiloto()
{
    ePiloto* listaDePilotos = (ePiloto*) malloc(sizeof(ePiloto));
    return listaDePilotos;
}

ePiloto* constructorParametrizadoPiloto(int idPiloto, char* nombre)
{
    ePiloto* listaDePilotos;

    listaDePilotos = constructorPorDefectoPiloto();
    if(listaDePilotos!=NULL)
    {
        pilotoSetNombre(listaDePilotos, nombre);
        pilotoSetId(listaDePilotos, idPiloto);
    }
    return listaDePilotos;
}

int pilotoSetNombre(ePiloto* this, char* nombre)
{
    int ret = 0;
    if(this!=NULL)
    {
        strcpy(this->nombre, nombre);
        ret = 1;
    }
    return ret;
}
int pilotoGetNombre(ePiloto* this, char* nombre)
{
    int ret = 0;
    if(this!=NULL)
    {
        strcpy(nombre, this->nombre);
        ret = 1;
    }
    return ret;
}

int pilotoSetId(ePiloto* this, int idPiloto)
{
    int ret = 0;
    if(this!=NULL && idPiloto > 0)
    {
        this->idPiloto = idPiloto;
        ret = 1;
    }
    return ret;
}
int pilotoGetId(ePiloto* this, int* idPiloto)
{
    int ret = 0;
    if(this!=NULL && idPiloto > 0)
    {
        *idPiloto = this->idPiloto;
        ret = 1;
    }
    return ret;
}
