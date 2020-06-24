#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList *)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna el tamaño del LinkedList. Verificando que el puntero this sea distinto de NULL. Si la
           verificación falla la función retorna (-1) y si tiene éxito retorna la longitud del array.
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int len = -1;

    if(this != NULL)
    {
        len = this->size;

        if(len<0)
        {
            len = -1;
        }
    }
    return len;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if(this != NULL  && nodeIndex <ll_len(this) && nodeIndex >= 0)
    {
        pNode = this->pFirstNode;

        for(i=0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node *newNode = NULL;
    Node *prevNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex<=ll_len(this))
    {
        newNode = (Node*) malloc (sizeof(Node));

        if(nodeIndex == 0 && ll_len(this)==0)
        {
            //newNode->pNextNode = this->pFirstNode;
            newNode->pElement = pElement;
            this->pFirstNode = newNode;
            this->size++;
            returnAux = 0;

        }else if(nodeIndex>0 && ll_len(this)>0)
        {
            prevNode = getNode(this,nodeIndex-1);
            //newNode->pNextNode = prevNode->pNextNode;
            prevNode->pNextNode = newNode;
            newNode->pElement = pElement;
            this->size++;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
        len = ll_len(this);
        addNode(this, len, pElement);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
           puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
           verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* pElement = NULL;
    Node* pNode = NULL;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
        pNode = getNode(this, index);

        if(pNode != NULL)
        {
            pElement = pNode->pElement;
        }
    }

    return pElement;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node *pNode = NULL;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
        pNode = getNode(this, index);

        if(pNode != NULL)
        {
            pNode->pElement = pElement;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
    int returnAux = -1;
    Node* pNode = NULL;
    Node* prevNode = NULL;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
        if(index == 0)
        {
            pNode = getNode(this, index);
            this->pFirstNode = pNode->pNextNode;
            this->size--;
            returnAux = 0;

        }else{
            prevNode = getNode(this, index-1);
            pNode = getNode(this, index);
            prevNode->pNextNode = pNode->pNextNode;
            this->size--;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;

    if(this != NULL)
    {
        len = ll_len(this);

        for(i=0; i<len; i++)
        {
            ll_remove(this, i);
        }

        this->pFirstNode = NULL;
        this->size=0;

        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;

    if(this != NULL)
    {
        len = ll_len(this);

        for(i=0; i<len; i++)
        {
            ll_remove(this, i);
        }

        this->pFirstNode = NULL;
        this->size=0;

        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    void* auxElement = NULL;
    int returnAux = -1;
    int len;
    int i;

    if(this != NULL)
    {
        len = ll_len(this);

        for(i=0; i<len; i++)
        {
            auxElement = ll_get(this, i);
            if(auxElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
        returnAux = 1;
        len = ll_len(this);

        if(len > 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index>=0 && index<=ll_len(this))
    {
        returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index)
{
    void* auxElement = NULL;

    if(this != NULL && index>=0 && index<ll_len(this))
    {
        auxElement = ll_get(this, index);
        ll_remove(this, index);
    }

    return auxElement;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    void* auxElement = NULL;
    int returnAux = -1;
    int len;
    int i;

    if(this != NULL)
    {
        returnAux = 0;
        len = ll_len(this);

        for(i=0; i<len; i++)
        {
            auxElement = ll_get(this, i);
            if(pElement == auxElement)
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    void* pElement = NULL;
    int returnAux = -1;
    int counter = 0;
    int retContains;
    int len2;
    int i;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 0;
        len2 = ll_len(this2);

        for(i=0; i<len2; i++)
        {
            pElement = ll_get(this2, i);
            retContains = ll_contains(this, pElement);

            if(retContains == 1)
            {
                counter++;
            }
        }

        if(counter == len2)
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* auxList = NULL;
    void* pElement = NULL;
    int i;

    if(this != NULL && from >= 0 && from <=ll_len(this) && to>from && to<=ll_len(this))
    {
        auxList = ll_newLinkedList();

        for(i=from; i<to; i++)
        {
            pElement = ll_get(this, i);
            ll_add(auxList, pElement);
        }
    }

    return auxList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* auxList = NULL;
    int from = 0;
    int len;

    if(this != NULL)
    {
        len = ll_len(this);
        auxList = ll_subList(this, from, len);
    }

    return auxList;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*, void*), int order)
{
    void* elementI = NULL;
    void* elementJ = NULL;
    void* auxElement = NULL;
    int returnAux =-1;
    int len;
    int i, j;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        len = ll_len(this);

        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                elementI = ll_get(this, i);
                elementJ = ll_get(this, j);

                if(pFunc(elementI, elementJ)==1 && order == 1)
                {
                    auxElement = elementI;
                    ll_set(this, i, elementJ);
                    ll_set(this, j, auxElement);

                }else if(pFunc(elementI, elementJ)==-1 && order == 0)
                {
                    auxElement = elementI;
                    ll_set(this, i, elementJ);
                    ll_set(this, j, auxElement);
                }
            }
        }
        returnAux = 0;
    }

    return returnAux;
}
