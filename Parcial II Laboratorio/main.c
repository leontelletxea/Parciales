#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "arrayList.h"

int main()
{
    LinkedList* listaDePosts = ll_newLinkedList();

    leerPost(listaDePosts);

    for(int i=0; i<ll_len(listaDePosts); i++)
    {
       ePost* auxPost = (ePost*) ll_get(listaDePosts, i);
       printf("%4d %10d %10d\n", auxPost->ID_MENSAJE, auxPost->ID_USUARIO, auxPost->POPULARIDAD);
    }
    return 0;
}
