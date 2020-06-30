#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilotos.h"
#include "vuelos.h"
#include "controller.h"
#include "parser.h"
#include "validaciones.h"

int Parser_generarListaVuelos(FILE* pFile, LinkedList* listaDeVuelos)
{
    eVuelo* auxVuelo;
    char titulos[100];
    char idVuelo[51];
    char idAvion[51];
    char idPiloto[51];
    char fecha[51];
    char destino[51];
    char cantPasajeros[51];
    char horaDespegue[51];
    char horaLlegada[51];
    int flag = 0;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flag == 0)
            {
                fscanf(pFile, "%[^\n]\n", titulos);
                flag = 1;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            auxVuelo = constructorParametrizadoVuelo(idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            ll_add(listaDeVuelos, auxVuelo);
        }
        printf("*Se cargaron los Vuelos desde el archivo .csv\n\n");
        fclose(pFile);
    }else{
        printf("*Imposible cargar los Vuelos\n\n");
    }
    return 1;
}

int Parser_guardarVuelosCortosEnArchivo(FILE* pFile, LinkedList* listaDeVuelos)
{
    LinkedList* listaDeVuelosCortos = ll_filter(listaDeVuelos, Controller_vuelosCortos);
    eVuelo* auxVuelo;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[51];
    char destino[51];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int i;

    if(listaDeVuelosCortos != NULL)
    {
        if(!ll_isEmpty(listaDeVuelosCortos))
        {
            if(pFile!=NULL)
            {
                for(i=0; i<ll_len(listaDeVuelosCortos); i++)
                {
                    if(i == 0)
                    {
                        fprintf(pFile, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
                    }
                    auxVuelo =(eVuelo*) ll_get(listaDeVuelosCortos, i);
                    if(auxVuelo!=NULL)
                    {
                        vueloGetHoraDespegue(auxVuelo, &horaDespegue);
                        vueloGetHoraLlegada(auxVuelo, &horaLlegada);
                        vueloGetIdVuelo(auxVuelo, &idVuelo);
                        vueloGetIdAvion(auxVuelo, &idAvion);
                        vueloGetIdPiloto(auxVuelo, &idPiloto);
                        vueloGetFecha(auxVuelo, fecha);
                        vueloGetDestino(auxVuelo, destino);
                        vueloGetCantPasajeros(auxVuelo, &cantPasajeros);

                        fprintf(pFile, "%d,%d,%d,%s,%s,%d,%d,%d\n", idVuelo,
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
        fclose(pFile);
    }else if(ll_isEmpty(listaDeVuelos)){
            printf("*No hay Vuelos cargados, ingrese 1 para cargarlos\n\n");
        }

    return 1;
}

int Parser_generarListaPilotos(FILE* pFile, LinkedList* listaDePilotos)
{
    ePiloto* auxPiloto;
    char idPiloto[51];
    char nombre[51];

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^\n]\n", idPiloto, nombre);
            auxPiloto = constructorParametrizadoPiloto(idPiloto, nombre);
            ll_add(listaDePilotos, auxPiloto);
        }
        fclose(pFile);
    }else{
        printf("*Imposible cargar los Pilotos\n\n");
    }
    return 1;
}
