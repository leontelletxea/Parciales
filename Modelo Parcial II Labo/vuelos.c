#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelos.h"

eVuelo* constructorPorDefectoVuelo()
{
    eVuelo* listaDeVuelos = (eVuelo*) malloc(sizeof(eVuelo));
    return listaDeVuelos;
}

eVuelo* constructorParametrizadoVuelo(char* idPiloto, char* idAvion, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada)
{
    eVuelo* listaDeVuelos;
    int auxInt;

    listaDeVuelos = constructorPorDefectoVuelo();
    if(listaDeVuelos!=NULL)
    {
        auxInt = atoi(idPiloto);
        vueloSetIdPiloto(listaDeVuelos, auxInt);
        auxInt = atoi(idAvion);
        vueloSetIdAvion(listaDeVuelos, auxInt);
        auxInt = atoi(fecha);
        vueloSetFecha(listaDeVuelos, auxInt);
        vueloSetDestino(listaDeVuelos, destino);
        auxInt = atoi(cantPasajeros);
        vueloSetCantPasajeros(listaDeVuelos, auxInt);
        auxInt = atoi(horaDespegue);
        vueloSetHoraDespegue(listaDeVuelos, auxInt);
        auxInt = atoi(horaLlegada);
        vueloSetHoraLlegada(listaDeVuelos, auxInt);

    }
    return listaDeVuelos;
}

int vueloSetIdPiloto(eVuelo* this, int idPiloto)
{
    int ret = 0;
    if(this!=NULL)
    {
        this->idPiloto = idPiloto;
        ret = 1;
    }
    return ret;
}

int vueloSetIdVuelo(eVuelo* this, int idVuelo)
{
    int ret = 0;
    if(this!=NULL)
    {
        this->idVuelo = idVuelo;
        ret = 1;
    }
    return ret;
}

int vueloSetIdAvion(eVuelo* this, int idAvion)
{
    int ret = 0;
    if(this!=NULL && idAvion > 0)
    {
        this->idAvion = idAvion;
        ret = 1;
    }
    return ret;
}

int vueloSetFecha(eVuelo* this, int fecha)
{
    int ret = 0;
    if(this!=NULL && fecha > 0)
    {
        this->fecha = fecha;
        ret = 1;
    }
    return ret;
}

int vueloSetDestino(eVuelo* this,char* destino)
{
    int ret = 0;
    if(this!=NULL)
    {
        strcpy(this->destino, destino);
        ret = 1;
    }
    return ret;
}

int vueloSetCantPasajeros(eVuelo* this, int cantPasajeros)
{
    int ret = 0;
    if(this!=NULL && cantPasajeros > 0)
    {
        this->cantPasajeros = cantPasajeros;
        ret = 1;
    }
    return ret;
}

int vueloSetHoraDespegue(eVuelo* this, int horaDespegue)
{
    int ret = 0;
    if(this!=NULL && horaDespegue > 0)
    {
        this->horaDespegue = horaDespegue;
        ret = 1;
    }
    return ret;
}

int vueloSetHoraLlegada(eVuelo* this, int horaLlegada)
{
    int ret = 0;
    if(this!=NULL && horaLlegada > 0)
    {
        this->horaLlegada = horaLlegada;
        ret = 1;
    }
    return ret;
}
