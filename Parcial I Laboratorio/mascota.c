#include "mascota.h"

void harcordearMascotas(eMascota listaMascotas[], int tam)
{
    int i;
    int idMascota[M]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int idDuenio[M]={1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5};
    char nombreMascota[M][51]={"Pelusa", "Michifusa", "Kenia", "Indio", "Firulais", "Pichichus", "Rocky", "Stefy", "Indio", "Roco", "Chicho"};
    char tipo[M][51]={"gato", "gato", "perro", "perro", "gato", "perro", "raro", "perro", "gato", "gato", "perro"};
    int idRazaMascota[M]={3, 4, 2, 1, 4, 2, 6, 1, 4, 3, 2};
    int peso[M]={10, 12, 11, 3, 2, 10, 2, 11, 3, 2, 12};
    int edadMascota[M]={1, 2, 7, 8, 2, 5, 1, 7, 8, 2, 14};
    char sexoMascota[M]={'f', 'f', 'm', 'm', 'm', 'm', 'f', 'm', 'm', 'm', 'm'};
    int estado[M]={OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

    for(i=0; i<tam; i++)
    {
      listaMascotas[i].idMascota = idMascota[i];
      listaMascotas[i].idDuenio = idDuenio[i];
      strcpy(listaMascotas[i].nombreMascota, nombreMascota[i]);
      strcpy(listaMascotas[i].tipo, tipo[i]);
      listaMascotas[i].idRazaMascota = idRazaMascota[i];
      listaMascotas[i].peso = peso[i];
      listaMascotas[i].edadMascota = edadMascota[i];
      listaMascotas[i].sexoMascota = sexoMascota[i];
      listaMascotas[i].estado = estado[i];
    }

}

void inicializarMascotas(eMascota listaMascotas[], int tam)
{
    int i;
    for(i=0; i<tam; i++) /** Recorro el array de mascotas */
    {
        listaMascotas[i].estado=VACIO; /** Inicializo los estados como vacios para que no se carge basura */
        listaMascotas[i].idDuenio=0;  /** Inicializo los id de duenios en cero para que no se carge basura */
        listaMascotas[i].idRazaMascota=0;
    }
}

void agregarMascota(eMascota listaMascotas[], int tam, int len, eRaza listaDeRazas[], int raz)
{
    int i;
    int posicion;
    int elegirRaza;
    int flag=0;
    int retorno;
    posicion = buscarLibreMascota(listaMascotas, tam); /** Llamo a la funcion buscarLibreMascota(); y guardo la posicion que retorna en la variable */
    if(posicion!=-1) /** Si la posicion que retorna es distinta a -1 (Posicion invalida) entro */
    {
        listaMascotas[posicion].idMascota = crearIdMascota(listaMascotas, tam); /** Asigno el id autoincremental al id de esa mascota */
        /** Pido todos los datos del cliente y los guardo en la posicion libre encontrada por buscarLibreCliente(); */
        do
        {
            retorno = getWord(listaMascotas[posicion].nombreMascota, "\nIngrese el Nombre de la Mascota: ");
        }while(retorno!=0);

        do
        {
            getWord(listaMascotas[posicion].tipo,"\nIngrese el Tipo de Mascota (perro/gato/raro): ");
        }while(strcmp(listaMascotas[posicion].tipo, "perro")!=0 && strcmp(listaMascotas[posicion].tipo, "gato")!=0 && strcmp(listaMascotas[posicion].tipo, "raro")!=0);

        do
        {
        elegirRaza = getInt("\n1.Doberman\n2.Golden Retriever\n3.Persa\n4.Siames\n5.Puma\n6.Serpiente\nSeleccione la raza para su tipo: ", "\n1.Doberman\n2.Golden Retriever\n3.Persa\n4.Siames\n5.Puma\n6.Serpiente\nError, seleccione una raza valida: ", 1, 6);
        for(i=0; i<raz; i++)
        {
            if(listaDeRazas[i].idRaza == elegirRaza)
            {
                if(strcmp(listaDeRazas[i].tipo, listaMascotas[posicion].tipo)==0)
                {
                    listaMascotas[posicion].idRazaMascota = elegirRaza;
                    printf("\nSe cargo la raza correctamente\n");
                    flag=1;
                }else{
                flag=0;
                }
            }
        }
        }while(flag==0);

        listaMascotas[posicion].edadMascota = getInt("\nIngrese Edad: ","\nError, ingrese una Edad valida: ",0,100);
        listaMascotas[posicion].peso = getInt("\nIngrese Peso: ","\nError, ingrese un Peso valido: ",0,50);
        listaMascotas[posicion].sexoMascota = getChar("Ingrese Sexo ('f'o'm'): ", "\nError, ingrese un Sexo valido: ", 'f', 'm');
        listaMascotas[posicion].idDuenio = getInt("\nIngrese Id del duenio: ","\nError, ingrese un id valido: ",1, len);
        listaMascotas[posicion].estado = OCUPADO;
        printf("\nMascota agregada exitosamente\n");
    }
}

int buscarLibreMascota(eMascota listaMascotas[], int tam)
{
    int i;
    int retorno = -1; /** Valor para saber si devuelve una posicion valida o no */
    for(i=0; i<tam; i++) /** Recorro el array de mascotas */
    {
        if(listaMascotas[i].estado == VACIO) /** Si la lista de mascotas en la posicion i esta vacia, entro */
        {
            retorno = i; /** Guardo esa posicion vacia en la variable*/
            break; /** Y rompo para que no siga iterando */
        }
    }
    return retorno; /** Retorno la posicion vacia */
}

int crearIdMascota()
{
    static int id=0; /** Variable estatica para que cada vez que incrementa el numero quede en ese mismo y no se inicialice en cero nuevamente */
    id++; /** Incremento en uno el numero estatico */
    return id; /** Retorno el id */
}

void bajaMascota(eMascota listaMascotas[], int tam)
{
    int id;
    int i;
    char respuesta;
    /** Pido el id de mascota que se desea eliminar, entre uno y el tamaño del array y lo guardo en la variable */
    id = getInt("\nIngrese id de la Mascota que desea eliminar: ","\nError, ingrese un id valido", 0, tam);
    for(i=0; i<tam; i++)
    {
        /** Si la lista de mascotas en la posicion i en estado es igual a el id ingresado por el usuario y la lista en la posicion y esta ocupada, entro */
        if(listaMascotas[i].idMascota == id && listaMascotas[i].estado == OCUPADO)
        {
            /** Pregunto si quiere dar de baja esa mascota y guardo la respuesta en la variable */
            respuesta = getChar("\nDesea dar de baja la Mascota?(ENTER=yes/n=NO): ","\nError ingrese (ENTER=yes/n=NO): ", '\n', 'n');
            if(respuesta == '\n') /** Si la respuesta es enter, entro */
            {
                listaMascotas[i].estado = VACIO; /** Marco como vacia la posicion elegida por el usuario */
            }else{
            break; /** Sino, rompo para que no siga iterando */
            }
        }
    }
}

void ordenarMascotasPorTipo(eMascota listaMascotas[], int tam)
{
    int i;
    int j;
    eMascota auxMascota; /** Genero una variable auxiliar de tipo eMascota para ordenar */

    for(i=0; i<tam-1; i++) /** Recorro el array de mascotas hasta una posicion antes del tamaño*/
    {
        if(listaMascotas[i].estado==OCUPADO)
        {
            for(j=i+1; j<tam; j++) /** Recorro el array de mascotas hasta una posicion antes del tamaño desde una posicion mas del tamaño de i*/
            {
                if(listaMascotas[j].estado==OCUPADO)
                {
                    if(strcmp(listaMascotas[i].tipo,listaMascotas[j].tipo)>0) /** Comparacion para ordenamiento de la A-Z */
                    {
                        auxMascota = listaMascotas[i]; /** Paso la lista de mascotas a la variable auxiliar */
                        listaMascotas[i] = listaMascotas[j]; /** Paso la posicion j a la posicion i */
                        listaMascotas[j] = auxMascota; /** Y paso el auxiliar que fue asignado a la posicion j */
                    }
                }
            }
        }
    }
}

void mostrarMascotasPorTipo(eMascota listaMascotas[], int tam, eRaza listaDeRazas[], int raz)
{
    int i, a;
    int flag=0; /** Flag que cambia para mostrar una sola vez los titulos */
    char tipo[51];
    int retorno;

    do
    {
        retorno = getWord(tipo, "\nIngrese el tipo de mascota que desea listar: "); /** Pido el tipo que se desea mostrar y lo guardo en la variable */
    }while(retorno!=0);

    for(i=0; i<tam; i++) /** Recorro el array de mascotas */
    {
        char razaMascota[51];
        if(listaMascotas[i].estado == OCUPADO) /** Si la lista de mascotas en la posicion i esta ocupada, entro */
        {
            if(flag==0) /** Si el flag es igual a cero, muestro los titulos */
            {
                printf("\nMascotas de tipo %s:\n", tipo);
                printf("ID MASCOTA NOMBRE     TIPO    RAZA       EDAD     PESO     SEXO\n");
                flag=1; /** Cambio el flag para que no se muestren mas veces los titulos */
            }
            for(a=0; a<raz; a++)
            {
                if(listaMascotas[i].idRazaMascota == listaDeRazas[a].idRaza)
                {
                    strcpy(razaMascota, listaDeRazas[a].nombreDeRaza);
                }
            }
            /** Si el tipo ingresado es igual a perro, y la lista en la posicionn es igual a perro muestro la mascota en esa posicon */
            if(strcmp(tipo, "perro")==0 && strcmp(listaMascotas[i].tipo, "perro")==0)
            {
                printf("\n%5d %11s %8s %8s %8d %8d %8c\n", listaMascotas[i].idMascota,
                                                             listaMascotas[i].nombreMascota,
                                                             listaMascotas[i].tipo,
                                                             razaMascota,
                                                             listaMascotas[i].edadMascota,
                                                             listaMascotas[i].peso,
                                                             listaMascotas[i].sexoMascota);
            }
            /** Si el tipo ingresado es igual a gato, y la lista en la posicionn es igual a gato muestro la mascota en esa posicon */
            if(strcmp(tipo, "gato")==0 && strcmp(listaMascotas[i].tipo, "gato")==0)
            {
                printf("\n%5d %11s %8s %8d %8d %8d %8c\n", listaMascotas[i].idMascota,
                                                             listaMascotas[i].nombreMascota,
                                                             listaMascotas[i].tipo,
                                                             listaMascotas[i].idRazaMascota,
                                                             listaMascotas[i].edadMascota,
                                                             listaMascotas[i].peso,
                                                             listaMascotas[i].sexoMascota);
            }
            /** Si el tipo ingresado es igual a raro, y la lista en la posicionn es igual a raro muestro la mascota en esa posicon */
            if(strcmp(tipo, "raro")==0 && strcmp(listaMascotas[i].tipo, "raro")==0)
            {
                printf("\n%5d %11s %8s %8d %8d %8d %8c\n", listaMascotas[i].idMascota,
                                                             listaMascotas[i].nombreMascota,
                                                             listaMascotas[i].tipo,
                                                             listaMascotas[i].idRazaMascota,
                                                             listaMascotas[i].edadMascota,
                                                             listaMascotas[i].peso,
                                                             listaMascotas[i].sexoMascota);
            }
        }
    }
}

void mostrarPromedioDeEdadDeMascotas(eMascota listaMascotas[], int tam)
{
    int i;
    int acumuladorEdadMascotas=0; /** Variable para acumular la edad de las mascotas */
    int contadorEdadMascotas=0; /** Variable para contar la cantidad de mascotas */
    float promedio=0; /** Variable para calcular el promedio */

    for(i=0; i<tam; i++) /** Recorro el array de mascotas */
    {
        if(listaMascotas[i].estado == OCUPADO) /** Si la lista de mascotas en la posicion i esta ocupada, entro */
        {
            acumuladorEdadMascotas += listaMascotas[i].edadMascota; /** Acumulo la edad de esa macota en la variable */
            contadorEdadMascotas++; /** Aumento el contador en uno */
        }
    }
    if(contadorEdadMascotas>0) /** Si el contador es mayor a uno, se que por lo menos hay una mascota en la lista */
    {
        promedio=(float)acumuladorEdadMascotas/contadorEdadMascotas; /** Calculo el promedio y lo guardo en la variable */
        printf("\nEl promedio de edad entre las Mascotas es: %.1f\n", promedio); /** Muestro el promedio */
    }else{ /** Sino, informo que no hay ningun dato para mostrar */
        printf("\nNo hay datos para mostrar\n");
    }
}

void mostrarPromedioDeEdadDeMascotasPorTipo(eMascota listaMascotas[], int tam)
{
    int i;
    /** Acumuladores, contadores y variables de promedio para cada tipo */
    int acumuladorPerro=0;
    int contadorPerro=0;
    float promedioPerro=0;
    int acumuladorGato=0;
    int contadorGato=0;
    float promedioGato=0;
    int acumuladorRaro=0;
    int contadorRaro=0;
    float promedioRaro=0;

    for(i=0; i<tam; i++) /** Recorro el array de mascotas */
    {
        if(listaMascotas[i].estado == OCUPADO) /** Si la lista de mascotas en la posicion i esta ocupada, entro */
        {
            if(strcmp(listaMascotas[i].tipo, "perro")==0) /** Si el tipo de la lista en la posicion i es igual a perro, entro */
            {
                acumuladorPerro += listaMascotas[i].edadMascota; /** Acumulo la edad en la variable */
                contadorPerro++; /** Aumento el contador en uno */
            }
            if(strcmp(listaMascotas[i].tipo, "gato")==0) /** Si el tipo de la lista en la posicion i es igual a gato, entro */
            {
                acumuladorGato += listaMascotas[i].edadMascota; /** Acumulo la edad en la variable */
                contadorGato++; /** Aumento el contador en uno */
            }
            if(strcmp(listaMascotas[i].tipo, "raro")==0) /** Si el tipo de la lista en la posicion i es igual a raro, entro */
            {
                acumuladorRaro += listaMascotas[i].edadMascota; /** Acumulo la edad en la variable */
                contadorRaro++; /** Aumento el contador en uno */
            }
        }
    }
    if(contadorPerro>0) /** Si el contador es mayor a uno, se que por lo menos hay una mascota en la lista */
    {
        promedioPerro=(float)acumuladorPerro/contadorPerro; /** Calculo el promedio y lo guardo en la variable */
        printf("\nEl promedio de edad entre los Perros es: %.1f\n", promedioPerro); /** Muestro el promedio */
    }else{
        printf("\nNo hay datos de este tipo para mostrar\n"); /** Sino, informo que no hay ningun dato para mostrar */
    }

    if(contadorGato>0) /** Si el contador es mayor a uno, se que por lo menos hay una mascota en la lista */
    {
        promedioGato=(float)acumuladorGato/contadorGato; /** Calculo el promedio y lo guardo en la variable */
        printf("\nEl promedio de edad entre los Gatos es: %.1f\n", promedioGato); /** Muestro el promedio */
    }else{
        printf("\nNo hay datos de este tipo para mostrar\n");/** Sino, informo que no hay ningun dato para mostrar */
    }

    if(contadorRaro>0) /** Si el contador es mayor a uno, se que por lo menos hay una mascota en la lista */
    {
        promedioRaro=(float)acumuladorRaro/contadorRaro; /** Calculo el promedio y lo guardo en la variable */
        printf("\nEl promedio de edad entre los Raros es: %.1f\n", promedioRaro); /** Muestro el promedio */
    }else{
        printf("\nNo hay datos de este tipo para mostrar\n");/** Sino, informo que no hay ningun dato para mostrar */
    }
}
