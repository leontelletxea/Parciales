#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "vuelos.h"
#include "validaciones.h"

int cargarDesdeTexto(LinkedList* listaDeVuelos)
{
    FILE* pData = NULL;
    int ret;
    char path[51];

do
    {
        ret = getWord(path, "*Ingrese el nombre del archivo desde el cual desea cargar los datos: ");
    }while(ret == -1);
    system("cls");

    pData = fopen(path, "r");

    if(listaDeVuelos!=NULL && pData!=NULL)
    {
        generarListaVuelos(pData, listaDeVuelos);
    }
    return 1;
}

int generarListaVuelos(FILE* pFile, LinkedList* listaDeVuelos)
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
        printf("*Se cargaron los Vuelos desde el archivo vuelos.csv\n\n");
        fclose(pFile);
    }else{
        printf("*Imposible cargar los Vuelos\n\n");
    }
    return 1;
}
