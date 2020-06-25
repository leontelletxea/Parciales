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


eUsuario* constructorPorDefectoUsuario()
{
    eUsuario* auxPost = (eUsuario*) malloc(sizeof(eUsuario));
    return auxPost;
}

eUsuario* constructorParametrizadoUsuario(char* ID_USUARIO, char* NICK, char* POPULARIDAD)
{
    eUsuario* auxUsuario;
    int auxInt;

    auxUsuario = constructorPorDefectoUsuario();

    if(auxUsuario!=NULL)
    {
        auxInt = atoi(ID_USUARIO);
        auxUsuario->ID_USUARIO = auxInt;
        strcpy(auxUsuario->NICK, NICK);
        auxInt = atoi(POPULARIDAD);
        auxUsuario->POPULARIDAD = auxInt;
    }

    return auxUsuario;
}


void cargarDesdePost(LinkedList* listaDePosts)
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

void cargarDesdeUsuarios(LinkedList* listaDeUsuarios)
{
    FILE* pFile = fopen("usuarios.csv", "r");
    eUsuario* auxUsuario;
    char titulos[100];
    char ID_USUARIO[51];
    char NICK[51];
    char POPULARIDAD[51];
    int flag = 0;

    if(listaDeUsuarios != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flag==0)
            {
                fscanf(pFile, "%[^\n]\n", titulos);
                flag = 1;
            }
            fscanf(pFile, "%[^,],%[^,],%[^\n]\n", ID_USUARIO, NICK, POPULARIDAD);
            auxUsuario = constructorParametrizadoUsuario(ID_USUARIO, NICK, POPULARIDAD);
            ll_add(listaDeUsuarios, auxUsuario);
        }
    }
    fclose(pFile);
}

void cargarFeed(LinkedList* listaDePosts, LinkedList* listaDeUsuarios)
{
    FILE* pFile = fopen("feed.csv", "w");
    ePost* auxPost;
    eUsuario* auxUsuario;
    int i, j;

    if(listaDePosts != NULL && listaDeUsuarios != NULL && pFile != NULL)
    {
        for(i=0; i<ll_len(listaDePosts); i++)
        {
            auxPost = ll_get(listaDePosts, i);

            for(j=0; j<ll_len(listaDeUsuarios); j++)
            {
                auxUsuario = ll_get(listaDeUsuarios, j);

                if(auxPost->ID_USUARIO == auxUsuario->ID_USUARIO)
                {
                    fprintf(pFile, "%d|%s|%d|%d|%s|%d\n", auxPost->ID_MENSAJE,
                                                          auxPost->MENSAJE,
                                                          auxPost->POPULARIDAD,
                                                          auxUsuario->ID_USUARIO,
                                                          auxUsuario->NICK,
                                                          auxUsuario->POPULARIDAD);
                }
            }
        }
    }
    fclose(pFile);
}

void cargarDesdeFeed()
{
    FILE* pFile = fopen("feed.csv", "r");
    char ID_MENSAJE[51];
    char POPULARIDAD_MENSAJE[51];
    char MENSAJE[2000];
    char ID_USUARIO[51];
    char NICK[51];
    char POPULARIDAD_USUARIO[51];

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", ID_MENSAJE,
                                                                    MENSAJE,
                                                                    POPULARIDAD_MENSAJE,
                                                                    ID_USUARIO,
                                                                    NICK,
                                                                    POPULARIDAD_USUARIO);

            printf("Id Mensaje: %s\n\nMensaje: %s\n\nLikes: %s\n\nId Usuario: %s\n\nNickname: %s\n\nFollowers: %s\n\n", ID_MENSAJE,
                                                                                                                        MENSAJE,
                                                                                                                        POPULARIDAD_MENSAJE,
                                                                                                                        ID_USUARIO,
                                                                                                                        NICK,
                                                                                                                        POPULARIDAD_USUARIO);
            printf("************************************************************************************************************************\n");
            printf("************************************************************************************************************************\n");
        }
    }
    fclose(pFile);
}

