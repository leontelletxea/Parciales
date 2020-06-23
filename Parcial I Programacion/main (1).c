#include <stdio.h>
#include <stdlib.h>

char contarVocales(char* cadena);

int main()
{
    char cadena[51];
    char vocalMaxima;

    printf("Ingrese una palabra: ");
    scanf("%s", &cadena);

    vocalMaxima = contarVocales(cadena);
    printf("\n*La vocal que mas aparece en la palabra %s es: %c\n", cadena, vocalMaxima);
}

char contarVocales(char* cadena)
{
    int j;
    int a=0;
    int e=0;
    int i=0;
    int o=0;
    int u=0;
    int vocales=0;
    char vocalMaxima;

    for(j=0; cadena[j]!='\0'; j++)
    {
        switch(cadena[j])
        {
        case 'a':
            a++;
            vocales++;
            break;
        case 'e':
            e++;
            vocales++;
            break;
        case 'i':
            i++;
            vocales++;
            break;
        case 'o':
            o++;
            vocales++;
            break;
        case 'u':
            u++;
            vocales++;
            break;
        }
    }
    printf("\n*La palabra '%s' tiene %d vocales\n", cadena, vocales);


    if(a>=e && a>=i && a>=o && a>=u)
    {
        vocalMaxima='a';
    }
    if(e>=a && e>=i && e>=o && e>=u)
    {
        vocalMaxima='e';
    }
    if(i>=a && i>=e && i>=o && i>=u)
    {
        vocalMaxima='i';
    }
    if(o>=a && o>=e && o>=i && o>=u)
    {
        vocalMaxima='o';
    }
    if(u>=a && u>=e && u>=i && u>=o)
    {
        vocalMaxima='u';
    }

    return vocalMaxima;
}
