#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilotos.h"

ePiloto* constructorPorDefectoPiloto()
{
    ePiloto* listaDePilotos = (ePiloto*) malloc(sizeof(ePiloto));
    return listaDePilotos;
}

ePiloto* constructorParametrizadoPiloto(char* idPiloto, char* nombre)
{
    ePiloto* listaDePilotos;
    int auxInt;

    listaDePilotos = constructorPorDefectoPiloto();
    if(listaDePilotos!=NULL)
    {
        pilotoSetNombre(listaDePilotos, nombre);
        auxInt = atoi(idPiloto);
        pilotoSetId(listaDePilotos, auxInt);
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
