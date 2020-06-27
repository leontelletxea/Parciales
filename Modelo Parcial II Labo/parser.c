#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int leerDesdeTexto(FILE* pFile, LinkedList* listaDeVuelos)
{
    eVuelo* auxVuelo;
    char titulos[100];
    char idVuelo[51];
    char idAvion[51];
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
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            auxVuelo = constructorParametrizadoVuelo(idVuelo, idAvion, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            ll_add(listaDeVuelos, auxVuelo);
        }
        printf("*Se cargaron los datos desde el archivo vuelos.csv (Modo Texto)\n\n");
        fclose(pFile);
    }else{
        printf("*Imposible cargar los datos\n\n");
    }
    return 1;
}
