#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"

ePost* constructorPorDefectoPost()
{
    ePost* auxPost = (ePost*) malloc(sizeof(ePost));
    return auxPost;
}

ePost* constructorParametrizadoPost(char* ID_MENSAJE, char* ID_USUARIO, char* POPULARIDAD, char* MENSAJE)
{
    ePost* auxPost;
    int auxInt;

    auxPost = constructorPorDefectoPost();

    if(auxPost!=NULL)
    {
        auxInt = atoi(ID_MENSAJE);
        auxPost->ID_MENSAJE = auxInt;
        auxInt = atoi(ID_USUARIO);
        auxPost->ID_USUARIO = auxInt;
        auxInt = atoi(POPULARIDAD);
        auxPost->POPULARIDAD = auxInt;
        strcpy(auxPost->MENSAJE, MENSAJE);
    }
    return auxPost;
}

void leerPost(LinkedList* listaDePosts)
{
    FILE* pFile = fopen("mensajes.csv", "r");
    ePost* auxPost;
    char titulos[100];
    char ID_MENSAJE[51];
    char ID_USUARIO[51];
    char POPULARIDAD[51];
    char MENSAJE[2000];
    int flag = 0;

    if(listaDePosts != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flag==0)
            {
                fscanf(pFile, "%[^\n]\n", titulos);
                flag = 1;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", ID_MENSAJE, ID_USUARIO, POPULARIDAD, MENSAJE);
            auxPost = constructorParametrizadoPost(ID_MENSAJE, ID_USUARIO, POPULARIDAD, MENSAJE);
            ll_add(listaDePosts, auxPost);
        }
    }
    fclose(pFile);
}



