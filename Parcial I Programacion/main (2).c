#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 5

typedef struct
{
    int idLocalidad;
    int dni;
    char nombre[51];
}Persona;;

typedef struct
{
    int id;
    char descripcion[51];
    int codigoPostal;
}Localidad;;

void listarPersonas(Persona listaDePersonas[], Localidad listaDeLocalidades[], int size);
void ordenarPorDobleCriterio(Persona listaDePersonas[], Localidad listaDeLocalidades[], int size);
int criterioDeOrdenamiento(Localidad listaDeLocalidades[], int size, int elemento, int elemento2);

int main()
{
    Localidad listaDeLocalidades[T] = {{1, "Campana", 1243},
                                       {2, "Pilar", 2321},
                                       {3, "Avellaneda", 4312},
                                       {4, "Quilmes", 2321},
                                       {5, "Buenos", 4432}};;

    Persona listaDePersonas[T] = {{1, 42180279, "Pedro"},
                                  {2, 42180274, "Angel"},
                                  {3, 42180275, "Angel"},
                                  {4, 42180276, "German"},
                                  {5, 42180278, "Octavio"}};;

    printf("*Lista de Personas por defecto:\n");
    listarPersonas(listaDePersonas, listaDeLocalidades, T);
    printf("\n");
    system("pause");
    system("cls");
    ordenarPorDobleCriterio(listaDePersonas, listaDeLocalidades, T);
    printf("*Lista de Personas ordenada por doble criterio:\n");
    listarPersonas(listaDePersonas, listaDeLocalidades, T);

    return 0;
}

void listarPersonas(Persona listaDePersonas[], Localidad listaDeLocalidades[], int size)
{
    int i, j;

    printf("\n   D.N.I            Nombre           Descripcion             Codigo Postal\n");
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(listaDePersonas[i].idLocalidad == listaDeLocalidades[j].id)
            {
                printf("%10d %15s %20s %20d\n", listaDePersonas[i].dni,
                                                listaDePersonas[i].nombre,
                                                listaDeLocalidades[j].descripcion,
                                                listaDeLocalidades[j].codigoPostal);
            }
        }
    }
}

void ordenarPorDobleCriterio(Persona listaDePersonas[], Localidad listaDeLocalidades[], int size)
{
    Persona auxPersona;
    int i, j;

    for(i=0; i<size-1; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(strcmp(listaDePersonas[i].nombre, listaDePersonas[j].nombre)>0)
            {
                auxPersona = listaDePersonas[i];
                listaDePersonas[i] = listaDePersonas[j];
                listaDePersonas[j] = auxPersona;
            }else if(strcmp(listaDePersonas[i].nombre, listaDePersonas[j].nombre)==0)
            {
                if(criterioDeOrdenamiento(listaDeLocalidades, size, listaDePersonas[i].idLocalidad, listaDePersonas[j].idLocalidad)==1)
                {
                    auxPersona = listaDePersonas[i];
                    listaDePersonas[i] = listaDePersonas[j];
                    listaDePersonas[j] = auxPersona;
                }
            }
        }
    }
}

int criterioDeOrdenamiento(Localidad listaDeLocalidades[], int size, int elemento, int elemento2)
{
    int auxReturn = 0;
    int i, j;

    for(i=0; i<size; i++)
    {
        if(listaDeLocalidades[i].id == elemento)
        {
            for(j=0; j<size; j++)
            {
                if(listaDeLocalidades[j].id == elemento2)
                {
                    if(strcmp(listaDeLocalidades[i].descripcion, listaDeLocalidades[j].descripcion)>0)
                    {
                       auxReturn = 1;
                    }
                }
            }
        }
    }

    return auxReturn;
}

/** Las funciones, son tecnicas empleadas por el programador, las cuales permiten encapsular problemas grandes en unos mas acotados, para esto se utiliza,
    en varios casos la recursividad, esto permite llamar a una o varias funciones dentro de otras, generando asi la solucion al problema en secuencias
    de funciones, todas estas son almacenadas en la pila o stack, la cual es una estructura o lista ordenada que permite almacenar datos.
    En ella se pueden almacenar tanto los parámetros formales que son aquellos especificados en la cabecera de la función y que sólo son validas dentro
    de la misma y los parámetros actuales que son las variables pasadas como parametro en las llamadas a las funciones. */
