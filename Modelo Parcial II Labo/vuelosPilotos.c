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
            printf(" Vuelo Nro   Avion Nro   Fecha  Destino     Pasajeros   Despegue   Arrivo    Piloto De Vuelo\n\n");
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
                    printf("%6d %10d %10d %10s %10d %10d %10d %20s\n", idVuelo, idAvion, fecha, destino, cantPasajeros, horaDespegue, horaLlegada, auxNombre);
                }
            }
            printf("\n");
        }
    }
}

void asociarIdPiloto(LinkedList* listaDePilotos, int idPiloto, char* auxNombre)
{
    ePiloto* auxPiloto;
    int auxId;
    int i;

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

void cantidadDePasajeros(LinkedList* listaDeVuelos)
{
    eVuelo* auxVuelo;
    int auxPasajeros;
    int cantPasajeros = 0;
    int i;

    if(listaDeVuelos != NULL)
    {
        if(!ll_isEmpty(listaDeVuelos))
        {
            for(i=0; i<ll_len(listaDeVuelos); i++)
            {
                auxVuelo = ll_get(listaDeVuelos, i);
                vueloGetCantPasajeros(auxVuelo, &auxPasajeros);
                cantPasajeros += auxPasajeros;
            }
            printf("*El Nro de pasajeros totales es: %d\n\n", cantPasajeros);
        }
    }

}

void cantidadDePasajerosIrlanda(LinkedList* listaDeVuelos)
{
    eVuelo* auxVuelo;
    char destino[51];
    int auxPasajeros;
    int cantPasajerosIrlanda = 0;
    int i;

    if(listaDeVuelos != NULL)
    {
        if(!ll_isEmpty(listaDeVuelos))
        {
            for(i=0; i<ll_len(listaDeVuelos); i++)
            {
                auxVuelo = ll_get(listaDeVuelos, i);
                vueloGetCantPasajeros(auxVuelo, &auxPasajeros);
                vueloGetDestino(auxVuelo, destino);
                if(strcmp(destino, "Irlanda")==0)
                {
                    cantPasajerosIrlanda += auxPasajeros;
                }
            }
            printf("*El Nro de pasajeros con destino a Irlanda es: %d\n\n", cantPasajerosIrlanda);
        }
    }

}

void menuOpciones(LinkedList* listaDeVuelos, LinkedList* listaDePilotos)
{
    int option;

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
        option = getInt("Ingrese una opcion: ","Error, elija una opcion valida: ",1,8);
        system("cls");
        switch(option)
        {
        case 1:
            cargarDesdeTexto(listaDeVuelos);
            break;
        case 2:
            imprimirVuelos(listaDeVuelos, listaDePilotos);
            break;
        case 3:
            cantidadDePasajeros(listaDeVuelos);
            break;
        case 4:
            cantidadDePasajerosIrlanda(listaDeVuelos);
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        }
        }while(option!=8);
        printf("Saliendo del Menu...\n");
}
