#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "arrayList.h"

int main()
{
    LinkedList* listaDePosts = ll_newLinkedList();
    LinkedList* listaDeUsuarios = ll_newLinkedList();

    cargarDesdePost(listaDePosts);
    cargarDesdeUsuarios(listaDeUsuarios);
    cargarFeed(listaDePosts, listaDeUsuarios);

    cargarDesdeFeed();

    /*printf("   POSTS:\n");
    for(int i=0; i<ll_len(listaDePosts); i++)
    {
       ePost* auxPost = (ePost*) ll_get(listaDePosts, i);
       printf("%4d %10d %10d\n", auxPost->ID_USUARIO, auxPost->ID_USUARIO, auxPost->POPULARIDAD);
    }

    printf("\n   USUARIOS:\n");
    for(int j=0; j<ll_len(listaDeUsuarios); j++)
    {
       eUsuario* auxUsuario = (eUsuario*) ll_get(listaDeUsuarios, j);
       printf("%4d %10s %10d\n", auxUsuario->ID_USUARIO, auxUsuario->NICK, auxUsuario->POPULARIDAD);
    }*/

    return 0;
}
