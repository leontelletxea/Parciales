#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelos.h"
#include "pilotos.h"
#include "controller.h"
#include "parser.h"
#include "validaciones.h"

int Controller_Tellechea_cargarDesdeTextoVuelos(LinkedList* listaDeVuelos)
{
    FILE* pData = NULL;
    int auxReturn;
    char path[51];

    do
    {
        auxReturn = getWord(path, "*Ingrese el nombre del archivo desde el cual desea cargar los datos: ");
    }while(auxReturn == -1);
    system("cls");

    pData = fopen(path, "r");

    if(listaDeVuelos!=NULL && pData!=NULL)
    {
        Parser_generarListaVuelos(pData, listaDeVuelos);
    }
    return 1;
}

int Controller_Tellechea_guardarEnTexto(LinkedList* listaDeVuelos)
{
    FILE* pData = NULL;

    pData = fopen("VuelosCortos.csv", "r");

    if(listaDeVuelos!=NULL && pData!=NULL)
    {
        Parser_guardarVuelosCortosEnArchivo(pData, listaDeVuelos);
    }
    return 1;
}

int Controller_Tellechea_cargarDesdeTextoPilotos(LinkedList* listaDePilotos)
{
    FILE* pData = NULL;

    pData = fopen("Pilotos.csv", "r");

    if(listaDePilotos!=NULL && pData!=NULL)
    {
        Parser_generarListaPilotos(pData, listaDePilotos);
    }
    return 1;
}

void Controller_Tellechea_listarVuelos(LinkedList* listaDeVuelos, LinkedList* listaDePilotos)
{
    eVuelo* auxVuelo;
    char auxNombre[51];
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[51];
    char destino[51];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int i;

    if(listaDeVuelos != NULL)
    {
        if(!ll_isEmpty(listaDeVuelos))
        {
            printf(" VUELOS:\n Vuelo Nro   Avion Nro Piloto Nro    Fecha      Destino      Pasajeros  Despegue    Arrivo    Piloto De Vuelo\n\n");
            for(i=0; i<ll_len(listaDeVuelos); i++)
            {
                auxVuelo =(eVuelo*) ll_get(listaDeVuelos, i);
                if(auxVuelo != NULL)
                {
                    vueloGetIdVuelo(auxVuelo, &idVuelo);
                    vueloGetIdAvion(auxVuelo, &idAvion);
                    vueloGetIdPiloto(auxVuelo, &idPiloto);
                    vueloGetFecha(auxVuelo, fecha);
                    vueloGetDestino(auxVuelo, destino);
                    vueloGetCantPasajeros(auxVuelo, &cantPasajeros);
                    vueloGetHoraDespegue(auxVuelo, &horaDespegue);
                    vueloGetHoraLlegada(auxVuelo, &horaLlegada);

                    Controller_Tellechea_buscarIdPiloto(listaDePilotos, idPiloto, auxNombre);
                    printf("%6d %10d %10d %15s %10s %10d %10d %10d %20s\n", idVuelo,
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

void Controller_Tellechea_buscarIdPiloto(LinkedList* listaDePilotos, int idPiloto, char* auxNombre)
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

int Controller_Tellechea_cantidadDePasajeros(eVuelo* auxVuelo)
{
    int cantPasajeros = 0;

    if(auxVuelo != NULL)
    {
        vueloGetCantPasajeros(auxVuelo, &cantPasajeros);
    }

    return cantPasajeros;
}

int Controller_Tellechea_cantidadDePasajerosIrlanda(eVuelo* auxVuelo)
{
    char destino[51];
    int cantPasajerosIrlanda = 0;

    if(auxVuelo != NULL)
    {
        vueloGetDestino(auxVuelo, destino);
        if(strcmp(destino, "Irlanda")==0)
        {
            vueloGetCantPasajeros(auxVuelo, &cantPasajerosIrlanda);
        }
    }

    return cantPasajerosIrlanda;
}

int Controller_Tellechea_vuelosCortos(eVuelo* auxVuelo)
{
    int returnAux = 0;
    int horaDespegue;
    int horaLlegada;
    int duracion;

    if(auxVuelo != NULL)
    {
        vueloGetHoraDespegue(auxVuelo, &horaDespegue);
        vueloGetHoraLlegada(auxVuelo, &horaLlegada);

        duracion = horaLlegada - horaDespegue;
        if(duracion < 3)
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

int Controller_Tellechea_criterioListaVuelosPortugal(eVuelo* auxVuelo, char* destino)
{
    int auxReturn = 0;
    char auxDestino[51];

    if(auxVuelo != NULL)
    {
        vueloGetDestino(auxVuelo, auxDestino);
        if(strcmp(auxDestino, destino)==0)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

LinkedList* Controller_Tellechea_listaDeVuelosPortugal(LinkedList* listaDeVuelos)
{
    char destino[51]= "Portugal";
    LinkedList* auxList = ll_filter_parametro(listaDeVuelos, Controller_Tellechea_criterioListaVuelosPortugal, destino);

    return auxList;
}

int Controller_Tellechea_generarListaSinAlexLifeson(eVuelo* auxVuelo)
{
    int auxReturn = 0;
    int idPiloto = 0;

    if(auxVuelo != NULL)
    {
        vueloGetIdPiloto(auxVuelo, &idPiloto);
        if(idPiloto != 1)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

LinkedList* Controller_Tellechea_pedirNombre(LinkedList* listaDePilotos)
{
    LinkedList* auxList;
    char auxNombre[51];

    if(listaDePilotos != NULL)
    {
        printf("Lista de pilotos Completa:\n");
        Controller_Tellechea_listarPilotos(listaDePilotos);

        getWord(auxNombre, "Ingrese el nombre de usuario que desea filtrar: ");
        auxList = ll_filter_parametro(listaDePilotos, Controller_Tellechea_filtrarPilotoPorNombre, auxNombre);
        system("cls");

        printf("Lista de pilotos Filtrada:\n");
        Controller_Tellechea_listarPilotos(auxList);
        printf("\n");
    }

    return auxList;
}

void Controller_Tellechea_listarPilotos(LinkedList* listaDePilotos)
{
    ePiloto* auxPiloto;
    char nombre[51];
    int idPiloto;
    int i;

    for(i=0; i<ll_len(listaDePilotos); i++)
    {
        auxPiloto = ll_get(listaDePilotos, i);
        pilotoGetNombre(auxPiloto, nombre);
        pilotoGetId(auxPiloto, &idPiloto);
        printf("%d  %10s\n", idPiloto, nombre);
    }
}

int Controller_Tellechea_filtrarPilotoPorNombre(ePiloto* auxPiloto, char* nombre)
{
    int auxReturn = 0;
    char auxNombre[51];

    if(auxPiloto != NULL)
    {
        pilotoGetNombre(auxPiloto, auxNombre);
        if(strcmp(auxNombre, nombre)!=0)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

void Controller_Tellechea_menuOpciones(LinkedList* listaDeVuelosOriginal, LinkedList* listaDePilotos)
{
    LinkedList* listaDeVuelosAux;
    int opcion;
    int cantPasajeros;

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
        printf("8) Filtrar vuelos por Nombre\n");
        printf("9) Salir\n");
        fflush(stdin);
        opcion = getInt("Ingrese una opcion: ","Error, elija una opcion valida: ",1,9);
        system("cls");
        switch(opcion)
        {
        case 1:
            Controller_Tellechea_cargarDesdeTextoVuelos(listaDeVuelosOriginal);
            break;
        case 2:
            Controller_Tellechea_listarVuelos(listaDeVuelosOriginal, listaDePilotos);
            break;
        case 3:
            cantPasajeros = ll_count(listaDeVuelosOriginal, Controller_Tellechea_cantidadDePasajeros);
            printf("*La cantidad de pasajeros totales es: %d\n\n", cantPasajeros);
            break;
        case 4:
            cantPasajeros = ll_count(listaDeVuelosOriginal, Controller_Tellechea_cantidadDePasajerosIrlanda);
            printf("*La cantidad de pasajeros con destino a Irlanda es: %d\n\n", cantPasajeros);
            break;
        case 5:
            Controller_Tellechea_guardarEnTexto(listaDeVuelosOriginal);
            break;
        case 6:
            listaDeVuelosAux = Controller_Tellechea_listaDeVuelosPortugal(listaDeVuelosOriginal);
            Controller_Tellechea_listarVuelos(listaDeVuelosAux, listaDePilotos);
            break;
        case 7:
            listaDeVuelosAux = ll_filter(listaDeVuelosOriginal, Controller_Tellechea_generarListaSinAlexLifeson);
            Controller_Tellechea_listarVuelos(listaDeVuelosAux, listaDePilotos);
            break;
        case 8:
            Controller_Tellechea_pedirNombre(listaDePilotos);
            break;
        }
        }while(opcion!=9);
        printf("Saliendo del Menu...\n");
}
