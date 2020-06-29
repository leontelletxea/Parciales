#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelos.h"
#include "pilotos.h"
#include "vuelosPilotos.h"
#include "parser.h"
#include "validaciones.h"

void imprimirVuelos(LinkedList* listaDeVuelos, LinkedList* listaDePilotos)
{
    eVuelo* auxVuelo;
    char auxNombre[51];
    int idVuelo;
    int idAvion;
    int idPiloto;
    int fecha;
    char destino[51];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int i;

    if(listaDeVuelos != NULL)
    {
        if(!ll_isEmpty(listaDeVuelos))
        {
            printf(" VUELOS:\n Vuelo Nro   Avion Nro Piloto Nro  Fecha  Destino      Pasajeros    Despegue    Arrivo    Piloto De Vuelo\n\n");
            for(i=0; i<ll_len(listaDeVuelos); i++)
            {
                auxVuelo =(eVuelo*) ll_get(listaDeVuelos, i);
                if(auxVuelo != NULL)
                {
                    vueloGetIdVuelo(auxVuelo, &idVuelo);
                    vueloGetIdAvion(auxVuelo, &idAvion);
                    vueloGetIdPiloto(auxVuelo, &idPiloto);
                    vueloGetFecha(auxVuelo, &fecha);
                    vueloGetDestino(auxVuelo, destino);
                    vueloGetCantPasajeros(auxVuelo, &cantPasajeros);
                    vueloGetHoraDespegue(auxVuelo, &horaDespegue);
                    vueloGetHoraLlegada(auxVuelo, &horaLlegada);

                    asociarIdPiloto(listaDePilotos, idPiloto, auxNombre);
                    printf("%6d %10d %10d %10d %10s %10d %10d %10d %20s\n", idVuelo,
                                                                            idAvion,
                                                                            idPiloto,
                                                                            fecha,
                                                                            destino,
                                                                            cantPasajeros,
                                                                            horaDespegue,
                                                                            horaLlegada,
                                                                            auxNombre);
                }
            }
            printf("\n");
        }else if(ll_isEmpty(listaDeVuelos)){
                printf("*No hay Vuelos cargados, ingrese 1 para cargarlos\n\n");
            }
    }
}

void asociarIdPiloto(LinkedList* listaDePilotos, int idPiloto, char* auxNombre)
{
    ePiloto* auxPiloto;
    int auxId;
    int i;

    if(listaDePilotos != NULL)
    {
        for(i=0; i<ll_len(listaDePilotos); i++)
        {
            auxPiloto = ll_get(listaDePilotos, i);
            pilotoGetId(auxPiloto, &auxId);
            if(auxId == idPiloto)
            {
                pilotoGetNombre(auxPiloto, auxNombre);
            }
        }
    }
}

int cantidadDePasajeros(eVuelo* auxVuelo)
{
    int cantPasajeros = 0;

    if(auxVuelo != NULL)
    {
        vueloGetCantPasajeros(auxVuelo, &cantPasajeros);
    }

    return cantPasajeros;
}

int cantidadDePasajerosIrlanda(eVuelo* auxVuelo)
{
    int cantPasajerosIrlanda = 0;

    if(auxVuelo != NULL)
    {
        if(strcmp(auxVuelo->destino, "Irlanda")==0)
        {
            vueloGetCantPasajeros(auxVuelo, &cantPasajerosIrlanda);
        }
    }

    return cantPasajerosIrlanda;
}

int filtrarVuelosCortos(char* path, LinkedList* listaDeVuelos, LinkedList* listaDePilotos)
{
    eVuelo* auxVuelo;
    FILE* pData;
    int idVuelo;
    int idAvion;
    int idPiloto;
    int fecha;
    char destino[51];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int size = 0;
    int i;

    if(listaDeVuelos != NULL)
    {
        size = ll_len(listaDeVuelos);

        if(!ll_isEmpty(listaDeVuelos))
        {
            pData = fopen(path, "w");
            if(pData!=NULL)
            {
                for(i=0; i<size; i++)
                {
                    if(i == 0)
                    {
                        fprintf(pData, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
                    }
                    auxVuelo =(eVuelo*) ll_get(listaDeVuelos, i);
                    if(auxVuelo!=NULL)
                    {
                        vueloGetHoraDespegue(auxVuelo, &horaDespegue);
                        vueloGetHoraLlegada(auxVuelo, &horaLlegada);
                        if(horaDespegue + 1 == horaLlegada || horaDespegue + 2 == horaLlegada)
                        {
                            vueloGetIdVuelo(auxVuelo, &idVuelo);
                            vueloGetIdAvion(auxVuelo, &idAvion);
                            vueloGetIdPiloto(auxVuelo, &idPiloto);
                            vueloGetFecha(auxVuelo, &fecha);
                            vueloGetDestino(auxVuelo, destino);
                            vueloGetCantPasajeros(auxVuelo, &cantPasajeros);

                            fprintf(pData, "%d,%d,%d,%d,%s,%d,%d,%d\n", idVuelo,
                                                                        idAvion,
                                                                        idPiloto,
                                                                        fecha,
                                                                        destino,
                                                                        cantPasajeros,
                                                                        horaDespegue,
                                                                        horaLlegada);
                        }
                    }
                }
                printf("*Se guardo la lista correctamente en el archivo VuelosCortos.csv (Modo Texto)\n\n");
            }else{
            printf("\n*Imposible cargar el archivo");
            }
            fclose(pData);
        }else if(ll_isEmpty(listaDeVuelos)){
                printf("*No hay Vuelos cargados, ingrese 1 para cargarlos\n\n");
            }
    }

    return 1;
}

int generarListaVuelosPortugal(LinkedList* listaDeVuelos, LinkedList* listaDeVuelosPortugal)
{
    eVuelo* auxVuelo;
    char destino[51];
    int i;

    if(listaDeVuelos != NULL && listaDeVuelosPortugal != NULL)
    {
        if(!ll_isEmpty(listaDeVuelos))
        {
            for(i=0; i<ll_len(listaDeVuelos); i++)
            {
                auxVuelo = ll_get(listaDeVuelos, i);
                vueloGetDestino(auxVuelo, destino);
                if(strcmp(destino, "Portugal")==0)
                {
                    ll_add(listaDeVuelosPortugal, auxVuelo);
                }
            }
            printf("*Se cargaron los Vuelos con destino a Portugal a la lista\n\n");
        }
    }

    return 1;
}

int generarListaSinAlexLifeson(LinkedList* listaDeVuelos, LinkedList* listaDeVuelosSinAlexLifeson, LinkedList* listaDePilotos)
{
    eVuelo* auxVuelo;
    char auxNombre[51];
    int asociarId;
    int i;

    if(listaDeVuelos != NULL && listaDeVuelosSinAlexLifeson != NULL)
    {
        if(!ll_isEmpty(listaDeVuelos))
        {
            for(i=0; i<ll_len(listaDeVuelos); i++)
            {
                auxVuelo = ll_get(listaDeVuelos, i);
                vueloGetIdPiloto(auxVuelo, &asociarId);
                asociarIdPiloto(listaDePilotos, asociarId, auxNombre);
                if(strcmp(auxNombre, "Alex Lifeson")!=0)
                {
                    ll_add(listaDeVuelosSinAlexLifeson, auxVuelo);
                }
            }
            printf("*Se cargaron los Vuelos filtrando a Alex Lifeson a la lista\n\n");
        }
    }else{
            printf("*Imposible cargar los Vuelos\n\n");
        }
    return 1;
}

void menuOpciones(LinkedList* listaDeVuelosOriginal, LinkedList* listaDePilotos, LinkedList* listaDeVuelosPortugal, LinkedList* listaDeVuelosSinAlexLifeson)
{
    int opcion;
    int cantPasajeros;
    int cantPasajerosIrlanda;

    do
    {
        printf("*** Menu Aerolineas ***\n");
        printf("1) Cargar archivo\n");
        printf("2) Imprimir vuelos\n");
        printf("3) Cantidad de pasajeros\n");
        printf("4) Cantidad de pasajeros  a Irlanda\n");
        printf("5) Filtrar vuelos cortos\n");
        printf("6) Listar vuelos a Portugal\n");
        printf("7) Filtrar a Alex Lifeson\n");
        printf("8) Salir\n");
        fflush(stdin);
        opcion = getInt("Ingrese una opcion: ","Error, elija una opcion valida: ",1,8);
        system("cls");
        switch(opcion)
        {
        case 1:
            cargarDesdeTexto(listaDeVuelosOriginal);
            break;
        case 2:
            imprimirVuelos(listaDeVuelosOriginal, listaDePilotos);
            break;
        case 3:
            cantPasajeros = ll_count(listaDeVuelosOriginal, cantidadDePasajeros);
            printf("*La cantidad de pasajeros totales es: %d\n\n", cantPasajeros);
            break;
        case 4:
            cantPasajerosIrlanda = ll_count(listaDeVuelosOriginal, cantidadDePasajerosIrlanda);
            printf("*La cantidad de pasajeros con destino a Irlanda es: %d\n\n", cantPasajerosIrlanda);
            break;
        case 5:
            filtrarVuelosCortos("VuelosCortos.csv", listaDeVuelosOriginal, listaDePilotos);
            break;
        case 6:
            generarListaVuelosPortugal(listaDeVuelosOriginal, listaDeVuelosPortugal);
            imprimirVuelos(listaDeVuelosPortugal, listaDePilotos);
            break;
        case 7:
            generarListaSinAlexLifeson(listaDeVuelosOriginal, listaDeVuelosSinAlexLifeson, listaDePilotos);
            imprimirVuelos(listaDeVuelosSinAlexLifeson, listaDePilotos);
            break;
        case 8:
            break;
        }
        }while(opcion!=8);
        printf("Saliendo del Menu...\n");
}
