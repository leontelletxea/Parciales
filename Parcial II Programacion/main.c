#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[51];
    char apellido;
    int division;
}eAlumno;;

eAlumno* constructorPorDefecto();
eAlumno* constructorParametrizado(char* nombre, char apellido, float* division);
void escribirEnArchivoBinario();
void leerArchivoBinario();

int main()
{
    escribirEnArchivoBinario();
    system("pause");
    system("cls");
    leerArchivoBinario();
}

eAlumno* constructorPorDefecto()
{
    eAlumno* listaDeAlumnos = (eAlumno*) malloc(sizeof(eAlumno));
    return listaDeAlumnos;
}

eAlumno* constructorParametrizado(char* nombre, char apellido, float* division)
{
    eAlumno* listaDeAlumnos;

    if(listaDeAlumnos!=NULL)
    {
        listaDeAlumnos = constructorPorDefecto();
        strcpy(listaDeAlumnos->nombre, nombre);
        listaDeAlumnos->apellido= apellido;
        listaDeAlumnos->division = *division;
    }
    return listaDeAlumnos;
}

void escribirEnArchivoBinario()
{
    FILE* pFile = NULL;
    char nombre[51] ="Leon";
    char apellido = 'T';
    float division = 1;
    eAlumno* listaDeAlumnos = constructorParametrizado(nombre, apellido, &division);

    pFile = fopen("data.bin", "wb");

    if(pFile!=NULL)
    {
        fwrite(listaDeAlumnos, sizeof(eAlumno),1,pFile);
        printf("*Se cargaron los datos en el archivo\n\n");
    }
    fclose(pFile);
}

void leerArchivoBinario()
{
    FILE* pFile = NULL;
    eAlumno listaDeAlumnos[1];

    pFile = fopen("data.bin", "rb");

    if(pFile!=NULL)
    {
        printf("*Lectura del archivo binario:\n\n");
        while(!feof(pFile))
        {
            if(feof(pFile))
            {
                break;
            }
            fread(listaDeAlumnos,sizeof(eAlumno),1,pFile);
            printf("%s %c %d\n\n", listaDeAlumnos->nombre, listaDeAlumnos->apellido, listaDeAlumnos->division);
        }
    }
    fclose(pFile);
}
