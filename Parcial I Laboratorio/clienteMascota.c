#include "clienteMascota.h"

void menuOpciones(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eMascotasPorCliente listaMascotasPorCliente[], eRaza listaDeRazas[], int raz, eLocalidad listaDeLocalidades[], int loc)
{
    int eleccion;

    do
    {
        printf("\n### MENU VETERINARIA ###\n");
        printf("1.Mostrar clientes\n");
        printf("2.Mostrar Mascotas\n");
        printf("3.Mostrar Clientes con sus Mascotas\n");
        printf("4.Agregar Mascotas\n");
        printf("5.Eliminar Mascotas\n");
        printf("6.Modificar Mascotas\n");
        printf("7.Agregar Cliente\n");
        printf("8.Eliminar Cliente y todas sus Mascotas\n");
        printf("9.Ordenar las Mascotas por tipo y listarlas con sus Duenios.\n");
        printf("10.Modificar Cliente\n");
        printf("11.Clientes con mas de una Mascota\n");
        printf("12.Mascotas con mas de tres anios\n");
        printf("13.Listar Mascotas por un tipo en particular\n");
        printf("14.Ordenar clientes por cantidad de Mascotas\n");
        printf("15.Ordenar clientes por cantidad de Mascotas y Nombre\n");
        printf("16.Mostrar promedio de edad entre Mascotas\n");
        printf("17.Mostrar promedio de edad entre Mascotas por tipo\n");
        printf("18.Mostrar porcentaje de mujeres sobre total de Clientes\n");
        printf("19.Mostrar Clientes con dos o mas Mascota del mismo sexo\n");
        printf("20.Mostrar Clientes por Localidad\n");
        printf("21.Ordenar Clientes por Descripcion y por nombre\n");
        printf("22.Salir del menu\n");
        fflush(stdin);
        eleccion = getInt("Ingrese una opcion: ","Error, elija una opcion valida: ",1,22);
        system("cls");
        /** Muestro el menu de opciones, pido que se ingrese una opcion y lo guardo en la variable, luego limpio la consola para emprolijar el programa */
        switch(eleccion)
        {
        /** Opero segun el caso, llamando a la respectiva funcion */
        case 1:
            mostrarClientes(listaClientes, len, listaDeLocalidades, loc);
            break;
        case 2:
            mostrarMascotasConSusDuenios(listaClientes, len, listaMascotas, tam, listaDeRazas, raz);
            break;
        case 3:
            mostrarClientesConSusMascotas(listaClientes, len, listaMascotas, tam, listaDeLocalidades, loc);
            break;
        case 4:
            mostrarClientes(listaClientes, len, listaDeLocalidades, loc);
            agregarMascota(listaMascotas, tam, len,listaDeRazas, raz);
            break;
        case 5:
            bajaMascota(listaMascotas, tam);
            break;
        case 6:
            modificarMascota(listaMascotas, tam, listaDeRazas, raz, listaClientes, len, listaDeLocalidades, loc);
            break;
        case 7:
            agregarCliente(listaClientes, len);
            break;
        case 8:
            bajaClienteCascada(listaClientes, len, listaMascotas, tam);
            break;
        case 9:
            ordenarMascotasPorTipo(listaMascotas, tam);
            mostrarMascotasConSusDuenios(listaClientes, len, listaMascotas, tam, listaDeRazas, raz);
            break;
        case 10:
            modificarCliente(listaClientes, len, listaDeLocalidades, loc);
            break;
        case 11:
            mostrarClientesConMasDeUnaMascota(listaClientes, len, listaMascotas, tam, listaDeLocalidades, loc);
            break;
        case 12:
            mostrarMascotasConMasDeTresAnios(listaClientes, len, listaMascotas, tam, listaDeRazas, raz);
            break;
        case 13:
            mostrarMascotasPorTipo(listaMascotas, tam, listaDeRazas, raz);
            break;
        case 14:
            ordenarClientesPorCantidadDeMascotas(listaClientes, len, listaMascotas, tam, listaMascotasPorCliente);
            mostrarClientes(listaClientes, len, listaDeLocalidades, loc);
            break;
        case 15:
            ordenarClientesPorCantidadDeMascotasYNombres(listaClientes, len, listaMascotas, tam, listaMascotasPorCliente);
            mostrarClientes(listaClientes, len, listaDeLocalidades, loc);
            break;
        case 16:
            mostrarPromedioDeEdadDeMascotas(listaMascotas, tam);
            break;
        case 17:
            mostrarPromedioDeEdadDeMascotasPorTipo(listaMascotas, tam);
            break;
        case 18:
            porcentajeDeMujeres(listaClientes, len);
            break;
        case 19:
            mostrarClientesConMasDeDosMascotaDelMismoSexo(listaClientes, len, listaMascotas, tam, listaDeLocalidades, loc);
            break;
        case 20:
            mostrarClientesPorLocalidad(listaClientes, len, listaDeLocalidades, loc);
            break;
        case 21:
            ordenarClientesPorDescripcionYNombre(listaClientes, len, listaDeLocalidades, loc);
            mostrarClientes(listaClientes, len, listaDeLocalidades, loc);
            break;
        }
        }while(eleccion!=22); /** Mientras la opcion ingresada sea distinta a 22, si es igual salgo */
        printf("Exit Console...\n");
}

void mostrarMascotasConSusDuenios(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eRaza listaDeRazas[], int raz)
{
    int i, j, a;
    int flag=0; /** Flag para mostrar una sola vez los titulos */

    for(i=0; i<tam; i++) /** Recorro el array de mascotas */
    {
        char razaMascota[51];
        if(listaMascotas[i].estado == OCUPADO) /** Si la lista de mascotas en la posicion i esta ocupada, entro */
        {
            for(j=0; j<len; j++) /** Recorro el array de clientes */
            {
                if(listaClientes[j].estado == OCUPADO) /** Si la lista de clientes en la posicion j esta ocupada, entro */
                {
                     /** Si el id de mascota en la posicion i es igual al id de cliente en la posicion j, entro */
                    if(listaMascotas[i].idDuenio == listaClientes[j].idCliente)
                    {
                        if(flag==0) /** Si el flag es igual a cero muestro los titulos */
                        {
                            printf("\nMASCOTAS CON SUS DUENIOS:\n");
                            printf("ID MASCOTA NOMBRE     TIPO       RAZA     EDAD     PESO     SEXO        CLIENTE\n");
                            flag=1; /** Cambio el flag para no mostrar los titulos mas de una vez */
                        }
                        for(a=0; a<raz; a++)
                        {
                            if(listaMascotas[i].idRazaMascota == listaDeRazas[a].idRaza)
                            {
                                strcpy(razaMascota, listaDeRazas[a].nombreDeRaza);
                            }
                        }
                        /** Imprimo la mascota en la posicion i */
                        printf("\n%5d %11s %8s %8s %8d %8d %8c", listaMascotas[i].idMascota,
                                                                 listaMascotas[i].nombreMascota,
                                                                 listaMascotas[i].tipo,
                                                                 razaMascota,
                                                                 listaMascotas[i].edadMascota,
                                                                 listaMascotas[i].peso,
                                                                 listaMascotas[i].sexoMascota);
                        /** Imprimo el cliente en la posicion j */
                        printf("%15s\n", listaClientes[j].nombre);

                    }
                }
            }
        }
    }
}

void mostrarClientesConSusMascotas(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eLocalidad listaDeLocalidades[], int loc)
{
    int i, j, a;

    printf("\n DUENIOS CON SUS MASCOTAS:\n");
    for(i=0;i<len;i++) /** Recorro el array de clientes */
    {
        char localidadTexto[51];
        if(listaClientes[i].estado == OCUPADO) /** Si la lista de clientes en la posicion i esta ocupada, entro */
        {
            for(a=0; a<loc; a++)
            {
                if(listaDeLocalidades[a].idLocalidad == listaClientes[i].localidad)
                {
                    strcpy(localidadTexto, listaDeLocalidades[a].localidad);
                    break;
                }
            }
            printf("\n NOMBRE CLIENTE     APELLIDO      LOCALIDAD");
            printf("\n %10s %15s %15s", listaClientes[i].nombre, listaClientes[i].apellido, localidadTexto); /** Imprimo el cliente en la posicion i */
            for(j=0;j<tam;j++) /** Recorro el array de mascotas */
            {
                if(j==0) /** Si es la primera vez que itera, muestro el titulo */
                {
                    printf("\n NOMBRE MASCOTA       TIPO\n");
                }
                if(listaMascotas[j].estado == OCUPADO) /** Si la lista de mascotas en la posicion j esta ocupada, entro */
                {
                    /** Si el id de cliente en la posicion i es igual al id de mascota en la posicion j, entro */
                    if(listaClientes[i].idCliente == listaMascotas[j].idDuenio)
                    {
                        printf("%10s %15s\n", listaMascotas[j].nombreMascota, listaMascotas[j].tipo); /** Imprimo la mascota en la posicion j */
                    }
                }
            }
        }
    }
}

void bajaClienteCascada(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam)
{
    int id;
    int i, j;
    char respuesta;
    /** Pido el id de cliente que se desea ingresar, entre unoy el tamaño del array y lo guardo en la variable */
    id = getInt("\nIngrese id del Cliente que desea eliminar: ","\nError, ingrese un Id valido", 1, len);
    for(i=0; i<len; i++) /** Recorro el array de clientes */
    {
        /** Si el id de la lista de clientes en la posicion i es igual al id ingresado por el usuario y la lista en esa posicion esta ocupada, entro */
        if(listaClientes[i].idCliente == id && listaClientes[i].estado == OCUPADO)
        {
            /** Pregunto si se desea dar de baja a ese cliente con todas sus mascotas y guardo su respuesta en la variable*/
            respuesta = getChar("\nDesea dar de baja el Cliente y todas las Mascotas que contiene?(ENTER=yes/n=NO): ","\nError ingrese (ENTER=yes/n=NO): ", '\n', 'n');
            if(respuesta == '\n') /** Si la respuesta es enter, entro */
            {
                listaClientes[i].estado = VACIO; /** Marco ese cliente como vacio */
                for(j=0; j<tam; j++) /** Recorro el array de mascotas */
                {
                    /** Si el id de la posicion de la lista de mascotas en la posicion j coincide con el id de cliente en la posicion i, entro */
                    if(listaClientes[i].idCliente == listaMascotas[j].idDuenio)
                    {
                        listaMascotas[j].estado = VACIO; /** Y marco esa mascota como vacia */
                    }
                }
            }else{ /** Sino,  si la respuesta es "n" rompo */
                break;
            }
        }
    }
}

void mostrarClientesConMasDeUnaMascota(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eLocalidad listaDeLocalidades[], int loc)
{
    int i, j, a;

    for(i=0; i<len; i++) /** Recorro el array de clientes */
    {
        char localidadTexto[51];
        int contadorMascotas=0; /** Inicializo el contador de mascotas adentro del for de clientes para que se inicialice en cero por cada cliente */
        if(listaClientes[i].estado == OCUPADO) /** Si el estado de la lista de clientes en la posicion i es igual a ocupado, entro */
        {
            for(a=0; a<loc; a++)
            {
                if(listaDeLocalidades[a].idLocalidad == listaClientes[i].localidad)
                {
                    strcpy(localidadTexto, listaDeLocalidades[a].localidad);
                }
            }
            for(j=0; j<tam; j++) /** Recorro el array de mascotas */
            {
                /** Si el estado de la lista de mascotas en la posicion j esta ocupado y el id de cliente en la posicion i es igual al id de duenio en la posicion j, entro*/
                if(listaMascotas[j].estado == OCUPADO && listaClientes[i].idCliente == listaMascotas[j].idDuenio)
                {
                    contadorMascotas++; /** Aumento el contador de mascotas para ese cliente */
                }
            }
        }
        if(contadorMascotas>1) /** Si el cliente en la posicion i tiene mas de una mascota, muesto ese cliente */
        {
            printf("\nID CLIENTE     NOMBRE   APELLIDO   LOCALIDAD  TELEFONO          EDAD        SEXO");
            printf("\n%5d %15s %10s %12s %10s %10d %10c\n", listaClientes[i].idCliente,
                                                            listaClientes[i].nombre,
                                                            listaClientes[i].apellido,
                                                            localidadTexto,
                                                            listaClientes[i].telefono,
                                                            listaClientes[i].edad,
                                                            listaClientes[i].sexo);
        }
    }
}

void mostrarMascotasConMasDeTresAnios(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eRaza listaDeRazas[] , int raz)
{
    int i, j, a;
    int flag=0; /** Flag para mostrar los titulos una sola vez */

    for(i=0; i<tam; i++) /** Recorro el array de mascotas */
    {
        char razaMascota[51];
        if(listaMascotas[i].estado == OCUPADO) /** Si la lista de mascotas en la posicion i esta ocupada, entro */
        {
            if(listaMascotas[i].edadMascota>3) /** Si la edad de esa mascota es mayor a 3, entro */
            {
                for(j=0; j<len; j++) /** Recorro el array de clientes */
                {
                    /** Si el id de cliente en la posicion j es igual al id de duenio en la posicion i, entro */
                    if(listaClientes[j].idCliente == listaMascotas[i].idDuenio)
                    {
                            if(flag==0) /** Si el flag es igual a cero muestro los titulos */
                            {
                                printf("\nMASCOTAS CON SUS DUENIOS:\n");
                                printf("ID MASCOTA NOMBRE     TIPO       RAZA     EDAD     PESO     SEXO        CLIENTE\n");
                                flag=1; /** Cambio el flag para no mostrar los titulos mas de una vez */
                            }
                            for(a=0; a<raz; a++)
                            {
                                if(listaMascotas[i].idRazaMascota == listaDeRazas[a].idRaza)
                                {
                                    strcpy(razaMascota, listaDeRazas[a].nombreDeRaza);
                                }
                            }
                            /** Muestro la mascota en la posicion i */
                            printf("\n%5d %11s %8s %8s %8d %8d %8c", listaMascotas[i].idMascota,
                                                                     listaMascotas[i].nombreMascota,
                                                                     listaMascotas[i].tipo,
                                                                     razaMascota,
                                                                     listaMascotas[i].edadMascota,
                                                                     listaMascotas[i].peso,
                                                                     listaMascotas[i].sexoMascota);

                            printf("%15s\n", listaClientes[j].nombre); /** Muestro el cliente en la posicion j */
                    }
                }
            }
        }
    }
}

void ordenarClientesPorCantidadDeMascotas(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eMascotasPorCliente listaMascotasPorCliente[])
{
    int i, j, a, b, c;
    eCliente auxCliente; /** Genero una variable de tipo eCliente auxiliar para ordenar la lista de clientes*/
    eMascotasPorCliente auxMascotasPorCliente; /** Genero una variable auxiliar de la estructura paralela de mascotas para ordenar */

    for(c=0; c<len; c++) /** Recorro el array paralelo e inicializo los datos con los del array de mascotas y la cantidad de mascotas en cero */
    {
        listaMascotasPorCliente[c].estado=listaClientes[c].estado;
        listaMascotasPorCliente[c].idClienteMascotas=listaClientes[c].idCliente;
        listaMascotasPorCliente[c].mascotas=0;
    }


    for(i=0;i<len;i++) /** Recorro el array de clientes */
    {
        int mascotasPorCliente=0; /** Inicializo el contador de mascotas para cada cliente */
        if(listaMascotasPorCliente[i].estado == OCUPADO) /** Si la lista de clientes en la posicion i esta ocupada, entro */
        {
            for(j=0;j<tam;j++) /** Recorro el array de mascotas */
            {
                /** Si la el estado de la lista de mascotas en la posicion j es ocupado y los id  de cliente y duenio coinciden, entro */
                if(listaMascotas[j].estado == OCUPADO && listaMascotas[j].idDuenio == listaClientes[i].idCliente)
                {
                    mascotasPorCliente++; /** Aumento el contador de mascotas para ese cliente */
                }
            }
            /** Cuando termino de recorrer todas las mascotas para ese cliente las guardo en la estructura paralela en la posicion i */
            listaMascotasPorCliente[i].mascotas = mascotasPorCliente;
        }
    }


    for(a=0; a<len-1; a++) /** Recorro el array de clientes hasta un numero menos que su tamaño */
    {
        if(listaMascotasPorCliente[a].estado==OCUPADO) /** Si la lista de clientes en la posicion a, esta ocupada , entro */
        {
            for(b=a+1; b<len; b++) /** Recorro el array paralelo de mascotas */
            {
                if(listaMascotasPorCliente[b].estado==OCUPADO) /** SI la lista paralela de mascotas en la posicion b esta ocupada, entro */
                {
                    /** Si la lista de mascotas por cliente en la posicion a es menor a la lista de mascotas por cliente en la posicion b, entro */
                    if(listaMascotasPorCliente[a].mascotas<listaMascotasPorCliente[b].mascotas)
                    {
                        auxCliente = listaClientes[a]; /** Guardo la lista de clientes en la posicion a en la variable auxiliar de eCliente */
                        listaClientes[a] = listaClientes[b]; /** En la lista en la posicion a guardo la lista en la posicion b */
                        listaClientes[b] = auxCliente; /** Y en la lista en la posicion b, la auxiliar */

                        /** Lo mismo con la estructura paralela, ya que sino la comparacion falla */
                        auxMascotasPorCliente = listaMascotasPorCliente[a];
                        listaMascotasPorCliente[a] = listaMascotasPorCliente[b];
                        listaMascotasPorCliente[b] = auxMascotasPorCliente;
                    }
                }
            }
        }
    }
}

void ordenarClientesPorCantidadDeMascotasYNombres(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eMascotasPorCliente listaMascotasPorCliente[])
{
    int i, j, a, b, c;
    eCliente auxCliente;
    eMascotasPorCliente auxMascotasPorCliente;

    for(c=0; c<len; c++)
    {
        listaMascotasPorCliente[c].estado=listaClientes[c].estado;
        listaMascotasPorCliente[c].idClienteMascotas=listaClientes[c].idCliente;
        listaMascotasPorCliente[c].mascotas=0;
    }


    for(i=0;i<len;i++)
    {
        int mascotasPorCliente=0;
        if(listaMascotasPorCliente[i].estado == OCUPADO)
        {
            for(j=0;j<tam;j++)
            {
                if(listaMascotas[j].estado == OCUPADO && listaMascotas[j].idDuenio == listaClientes[i].idCliente)
                {
                    mascotasPorCliente++;
                }
            }
            listaMascotasPorCliente[i].mascotas = mascotasPorCliente;
        }
    }


    for(a=0; a<len-1; a++)
    {
        if(listaMascotasPorCliente[a].estado==OCUPADO)
        {
            for(b=a+1; b<len; b++)
            {
                if(listaMascotasPorCliente[b].estado==OCUPADO)
                {
                    if(listaMascotasPorCliente[a].mascotas < listaMascotasPorCliente[b].mascotas)
                    {
                        auxCliente = listaClientes[a];
                        listaClientes[a] = listaClientes[b];
                        listaClientes[b] = auxCliente;

                        auxMascotasPorCliente = listaMascotasPorCliente[a];
                        listaMascotasPorCliente[a] = listaMascotasPorCliente[b];
                        listaMascotasPorCliente[b] = auxMascotasPorCliente;
                    }else if(listaMascotasPorCliente[a].mascotas == listaMascotasPorCliente[b].mascotas) /** Ante igualdad de criterio, entro */
                    {
                        if(strcmp(listaClientes[a].nombre, listaClientes[b].nombre)>0) /** Comparo y ordeno por nombre */
                        {
                            auxCliente = listaClientes[a];
                            listaClientes[a] = listaClientes[b];
                            listaClientes[b] = auxCliente;

                            auxMascotasPorCliente = listaMascotasPorCliente[a];
                            listaMascotasPorCliente[a] = listaMascotasPorCliente[b];
                            listaMascotasPorCliente[b] = auxMascotasPorCliente;
                        }
                    }
                }
            }
        }
    }
}

void modificarMascota(eMascota listaMascotas[], int tam, eRaza listaDeRazas[], int raz, eCliente listaClientes[], int len, eLocalidad listaDeLocalidades[], int loc)
{
    eMascota auxMascota;
    int id;
    int i, j, a, b;
    int opcion;
    int flag=0;
    int flag2=0;
    int elegirRaza;
    int elegirDuenio;
    int retorno;
    char respuesta;
    /** Pido un id entre el 1 y el tamaño de mascotas y lo guardo en la variable*/
    id = getInt("\nIngrese id de la Mascota que quiere modificar: ","\nError, ingrese un id valido: ", 1, tam);

    for(i=0; i<tam; i++) /** Recorro el array de mascotas */
    {
        char razaMascota[51]= " ";
        /** Si la posicion ingresada por el usuario es igual al id de la posicion i y la posicion i en estado es igual a ocupado entro */
        if(listaMascotas[i].idMascota == id && listaMascotas[i].estado == OCUPADO)
        {
            auxMascota.idMascota = listaMascotas[i].idMascota;
            strcpy(auxMascota.nombreMascota, listaMascotas[i].nombreMascota);
            strcpy(auxMascota.tipo, listaMascotas[i].tipo);
            auxMascota.idRazaMascota = listaMascotas[i].idRazaMascota;
            auxMascota.edadMascota = listaMascotas[i].edadMascota;
            auxMascota.peso = listaMascotas[i].peso;
            auxMascota.sexoMascota = listaMascotas[i].sexoMascota;
            auxMascota.idDuenio = listaMascotas[i].idDuenio;
            do /** Muestro la mascota en la posicion encontrada */
            {
                for(a=0; a<raz; a++)
                {
                    if(auxMascota.idRazaMascota == listaDeRazas[a].idRaza)
                    {
                        strcpy(razaMascota, listaDeRazas[a].nombreDeRaza);
                    }
                }
                printf(" ID MASCOTA NOMBRE    TIPO       RAZA      EDAD      PESO   SEXO   ID DUENIO\n");
                printf("\n %8d %8s %8s %8s %8d %8d %8c %8d", auxMascota.idMascota,
                                                            auxMascota.nombreMascota,
                                                            auxMascota.tipo,
                                                            razaMascota,
                                                            auxMascota.edadMascota,
                                                            auxMascota.peso,
                                                            auxMascota.sexoMascota,
                                                            auxMascota.idDuenio);
                printf("\nMenu edicion\n");
                printf("1).Nombre\n");
                printf("2).Tipo\n");
                printf("3).Raza\n");
                printf("4).Edad\n");
                printf("5).Peso\n");
                printf("6).Sexo\n");
                printf("7).Duenio\n");
                printf("8).Guardar cambios\n");
                printf("9).Salir menu edicion\n");
                opcion = getInt("Elija una opcion: ","Error, elija una opcion valida: ",1,9);
                system("cls");
                /** Muestro el menu de edicion, pido la opcion, la guardo en la variable y limpio la consola para emprolijar el programa */
                switch(opcion)
                {
                /** Edito el campo segun el caso */
                case 1:
                    do
                    {
                        retorno = getWord(auxMascota.nombreMascota,"\nIngrese el nuevo Nombre: ");
                    }while(retorno!=0);
                    break;
                case 2:
                    do
                    {
                        getWord(auxMascota.tipo,"\nIngrese el nuevo Tipo: ");
                    }while(strcmp(auxMascota.tipo, "perro")!=0 && strcmp(auxMascota.tipo, "gato")!=0 && strcmp(auxMascota.tipo, "raro")!=0);
                    break;
                case 3:
                    do
                    {
                    elegirRaza = getInt("\n1.Doberman\n2.Golden Retriever\n3.Persa\n4.Siames\n5.Puma\n6.Serpiente\nSeleccione la raza para su tipo: ", "\n1.Doberman\n2.Golden Retriever\n3.Persa\n4.Siames\n5.Puma\n6.Serpiente\nError, seleccione una raza valida: ", 1, 6);
                    for(b=0; b<raz; b++)
                    {
                        if(listaDeRazas[b].idRaza == elegirRaza)
                        {
                            if(strcmp(listaDeRazas[b].tipo, auxMascota.tipo)==0)
                            {
                                flag=1;
                                auxMascota.idRazaMascota = elegirRaza;
                                printf("\nSe cargo la raza correctamente\n");
                            }else{
                                flag=0;
                            }
                        }
                    }
                    }while(flag==0);
                    break;
                case 4:
                    auxMascota.edadMascota = getInt("\nIngrese la nueva Edad: ","\n", 0, 100);
                    break;
                case 5:
                    auxMascota.peso = getInt("\nIngrese el nuevo Peso: ","Error, ingrese un Peso valido: ", 0, 50);
                    break;
                case 6:
                    auxMascota.sexoMascota = getChar("\nIngrese el nuevo Sexo ('f' o 'm'): ","\nError ingrese ('f' o 'm'): ", 'f', 'm');
                    break;
                case 7:
                    mostrarClientes(listaClientes, len, listaDeLocalidades, loc);
                    do
                    {
                        elegirDuenio = getInt("\nIngrese el nuevo id de duenio: ", "\nError, ingrese un id de duenio valido: ", 1, len);
                        for(j=0; j<len; j++)
                        {
                            if(listaClientes[j].estado == OCUPADO)
                            {
                                if(listaClientes[j].idCliente == elegirDuenio)
                                {
                                    flag2=1;
                                    auxMascota.idDuenio = elegirDuenio;
                                }else{
                                flag=0;
                                }
                            }
                        }
                    }while(flag2==0);
                    break;
                case 8:
                    respuesta = getChar("\nDesea guardar los cambios? (Enter=si / n=No): ", "\nError, ingrese (Enter=si / n=No): ", '\n', 'n');
                    if(respuesta == '\n')
                    {
                        strcpy(listaMascotas[i].nombreMascota, auxMascota.nombreMascota);
                        strcpy(listaMascotas[i].tipo, auxMascota.tipo);
                        listaMascotas[i].idRazaMascota = auxMascota.idRazaMascota;
                        listaMascotas[i].edadMascota = auxMascota.edadMascota;
                        listaMascotas[i].peso = auxMascota.peso;
                        listaMascotas[i].sexoMascota = auxMascota.sexoMascota;
                        listaMascotas[i].idDuenio = auxMascota.idDuenio;
                        printf("\nLos datos han sido guardados satisfactoriamente!\n");
                    }else if(respuesta == 'n'){
                        printf("\nEl guardado de datos ha sido cancelado\n");
                    }
                    break;
                }
            }
            while(opcion!=9); /** Mientras la opcion sea distinta de 8, si es igual salgo */
        }
    }
}

void mostrarClientesConMasDeDosMascotaDelMismoSexo(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eLocalidad listaDeLocalidades[], int loc)
{
    int i, j, a;
    int flag=0;

    for(i=0; i<len; i++)
    {
        char localidadTexto[51];
        int contadorFemenino=0;
        int contadorMasculino=0;
        if(listaClientes[i].estado == OCUPADO)
        {
            for(a=0; a<loc; a++)
            {
                if(listaDeLocalidades[a].idLocalidad == listaClientes[i].localidad)
                {
                    strcpy(localidadTexto, listaDeLocalidades[a].localidad);
                }
            }
            for(j=0; j<tam; j++)
            {
                if(listaMascotas[j].estado == OCUPADO)
                {
                    if(listaClientes[i].idCliente == listaMascotas[j].idDuenio)
                    {
                           if(listaMascotas[j].sexoMascota == 'f')
                           {
                               contadorFemenino++;
                           }
                           if(listaMascotas[j].sexoMascota == 'm')
                           {
                               contadorMasculino++;
                           }
                    }
                }
            }
        }

        if(contadorFemenino>=2 || contadorMasculino>=2)
        {
            if(flag==0)
            {
                printf("\nClientes con mascotas del mismo sexo:\n");
                printf("\nID CLIENTE     NOMBRE   APELLIDO        LOCALIDAD      TELEFONO         EDAD        SEXO\n");
                flag=1;
            }
            printf("\n%5d %15s %10s %15s %15s %10d %10c\n", listaClientes[i].idCliente,
                                                            listaClientes[i].nombre,
                                                            listaClientes[i].apellido,
                                                            localidadTexto,
                                                            listaClientes[i].telefono,
                                                            listaClientes[i].edad,
                                                            listaClientes[i].sexo);
        }
    }
}
