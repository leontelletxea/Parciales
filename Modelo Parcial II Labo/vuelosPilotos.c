#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelosPilotos.h"

int cargarDesdeTexto(char* path, LinkedList* listaDeVuelos)
{
    FILE* pData = NULL;

    pData = fopen(path, "r");

    if(listaDeVuelos!=NULL && pData!=NULL)
    {
        leerDesdeTexto(pData, listaDeVuelos);
    }
    return 1;
}

void menuOpciones(LinkedList* listaDeVuelos)
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
            cargarDesdeTexto("Vuelos.csv", listaDeVuelos);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

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
