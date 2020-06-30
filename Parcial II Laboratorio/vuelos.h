#include "LinkedList.h"

typedef struct{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[51];
    char destino[51];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}eVuelo;

eVuelo* constructorPorDefectoVuelo();

eVuelo* constructorParametrizadoVuelo(char* idVuelo,
                                      char* idAvion,
                                      char* idPiloto,
                                      char* fecha,
                                      char* destino,
                                      char* cantPasajeros,
                                      char* horaDespegue,
                                      char* horaLlegada);

int vueloSetIdPiloto(eVuelo* this, int idPiloto);
int vueloGetIdPiloto(eVuelo* this, int* idPiloto);

int vueloSetIdVuelo(eVuelo* this, int idVuelo);
int vueloGetIdVuelo(eVuelo* this, int* idVuelo);

int vueloSetIdAvion(eVuelo* this, int idAvion);
int vueloGetIdAvion(eVuelo* this, int* idAvion);

int vueloSetFecha(eVuelo* this, char* fecha);
int vueloGetFecha(eVuelo* this, char* fecha);

int vueloSetDestino(eVuelo* this, char* destino);
int vueloGetDestino(eVuelo* this, char* destino);

int vueloSetCantPasajeros(eVuelo* this, int cantPasajeros);
int vueloGetCantPasajeros(eVuelo* this, int* cantPasajeros);

int vueloSetHoraDespegue(eVuelo* this, int horaDespegue);
int vueloGetHoraDespegue(eVuelo* this, int* horaDespegue);

int vueloSetHoraLlegada(eVuelo* this, int horaLlegada);
int vueloGetHoraLlegada(eVuelo* this, int* horaLlegada);
