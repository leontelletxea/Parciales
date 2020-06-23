#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 5
#define OCUPADO 1
#define VACIO 0

typedef struct
{
    int id;
    char nombre[51];
    char curso;
    int estado;
}Alumno;;

float CalcularSueldoNeto(float sueldoBruto, int porcentajeObraSocial, int porcentajeJubilacion);
void ordenarPorDobleCriterio(Alumno listaDeAlumnos[], int size);
void listarAlumnos(Alumno listaDeAlumnos[], int size);

int main()
{
    float sueldo;
    int obraSocial;
    int jubilacion;
    float nuevoSueldo;

    Alumno listaDeAlumnos[T] = {{1, "Leon", 'a', OCUPADO},
                               {2, "Angel", 'c', OCUPADO},
                               {3, "Angel", 'b', OCUPADO},
                               {4, "German", 'd', OCUPADO},
                               {5, "Predro", 'e', OCUPADO}};;

    printf("Ingrese el sueldo: $");
    scanf("%f", &sueldo);
    printf("\nIngrese el porcentaje de obra social: %%");
    scanf("%d", &obraSocial);
    printf("\nIngrese el porcentaje de jubilacion: %%");
    scanf("%d", &jubilacion);

    nuevoSueldo = CalcularSueldoNeto(sueldo, obraSocial, jubilacion);
    printf("\n  Sueldo         Obra Social      Jubilacion       Sueldo Con Descuentos\n");
    printf("\n $%.1f            %%%d             %%%d                  $%.1f\n", sueldo, obraSocial, jubilacion, nuevoSueldo);
    printf("\n************************************************************************\n");
    printf("************************************************************************\n\n");

    printf("\n*Lista de Alumnos por defecto:\n");
    listarAlumnos(listaDeAlumnos, T);
    ordenarPorDobleCriterio(listaDeAlumnos, T);
    printf("\n*Lista de Alumnos ordenada por doble criterio:\n");
    listarAlumnos(listaDeAlumnos, T);

    return 0;
}

float CalcularSueldoNeto(float sueldoBruto, int porcentajeObraSocial, int porcentajeJubilacion)
{
    float nuevoSueldo;
    float descuentoObrasocial;
    float descuentoJubilacion;

    descuentoObrasocial = (sueldoBruto*porcentajeObraSocial)/100;

    descuentoJubilacion = (sueldoBruto*porcentajeJubilacion)/100;

    nuevoSueldo = sueldoBruto-descuentoObrasocial;

    nuevoSueldo = nuevoSueldo-descuentoJubilacion;

    return nuevoSueldo;
}

void ordenarPorDobleCriterio(Alumno listaDeAlumnos[], int size)
{
    Alumno auxAlumno;
    int i, j;

    for(i=0; i<size-1; i++)
    {
        if(listaDeAlumnos[i].estado == OCUPADO)
        {
            for(j=i+1; j<size; j++)
            {
                if(listaDeAlumnos[j].estado == OCUPADO)
                {
                    if(strcmp(listaDeAlumnos[i].nombre, listaDeAlumnos[j].nombre)>0)
                    {
                        auxAlumno = listaDeAlumnos[i];
                        listaDeAlumnos[i] = listaDeAlumnos[j];
                        listaDeAlumnos[j] = auxAlumno;
                    }else if(strcmp(listaDeAlumnos[i].nombre, listaDeAlumnos[j].nombre)==0)
                    {
                        if(listaDeAlumnos[i].curso > listaDeAlumnos[j].curso)
                        {
                            auxAlumno = listaDeAlumnos[i];
                            listaDeAlumnos[i] = listaDeAlumnos[j];
                            listaDeAlumnos[j] = auxAlumno;
                        }
                    }
                }
            }
        }
    }
}

void listarAlumnos(Alumno listaDeAlumnos[], int size)
{
    int i;

    printf("\n Id     Nombre        Curso \n");
    for(i=0; i<size; i++)
    {
        printf("%3d %10s %10c \n", listaDeAlumnos[i].id, listaDeAlumnos[i].nombre, listaDeAlumnos[i].curso);
    }
}
