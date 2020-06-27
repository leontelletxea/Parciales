#include "LinkedList.h"
#include "vuelosPilotos.h"

typedef struct{
    int idVuelo;
    int idAvion;
    int idPiloto;
    int fecha;
    char destino[51];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}eVuelo;

eVuelo* constructorPorDefectoVuelo();


eVuelo* constructorParametrizadoVuelo(char* idPiloto, char* idAvion, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada);


int vueloSetIdPiloto(eVuelo* this, int idPiloto);


int vueloSetIdVuelo(eVuelo* this, int idVuelo);


int vueloSetIdAvion(eVuelo* this, int idAvion);


int vueloSetFecha(eVuelo* this, int fecha);


int vueloSetDestino(eVuelo* this,char* destino);


int vueloSetCantPasajeros(eVuelo* this, int cantPasajeros);


int vueloSetHoraDespegue(eVuelo* this, int horaDespegue);


int vueloSetHoraLlegada(eVuelo* this, int horaLlegada);
