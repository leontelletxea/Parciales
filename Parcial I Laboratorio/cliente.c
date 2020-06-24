#include "cliente.h"

void harcordearClientes(eCliente listaClientes[], int len)
{
    int i;
    int idCliente[C]={1, 2, 3, 4, 5};
    char nombre[C][51]={"Sofia", "Osvaldo", "Ornella", "Tomas", "Jorge"};
    char apellido[C][51]={"Boubeta", "Fernandez", "Giacomozzi", "Saalcedo", "Riveros"};
    int localidad[C]={1, 2, 3, 2, 1};
    char telefono[C][51]={"1151034576", "1151034577", "1151034578", "1151034579", "1151034580"};
    int edad[C]={30, 59, 18, 19, 60};
    char sexo[C]={'f', 'm', 'f', 'm', 'm'};
    int estado[C]={OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

    for(i=0; i<C; i++)
    {
      listaClientes[i].idCliente = idCliente[i];
      strcpy(listaClientes[i].nombre, nombre[i]);
      strcpy(listaClientes[i].apellido, apellido[i]);
      listaClientes[i].localidad = localidad[i];
      strcpy(listaClientes[i].telefono, telefono[i]);
      listaClientes[i].edad = edad[i];
      listaClientes[i].sexo = sexo[i];
      listaClientes[i].estado = estado[i];
    }
}

void mostrarClientes(eCliente listaClientes[], int len, eLocalidad listaDeLocalidades[], int loc)
{
    int i, a;
    printf("\nID CLIENTE     NOMBRE   APELLIDO        LOCALIDAD      TELEFONO         EDAD        SEXO\n");
    for(i=0; i<len; i++) /** Recorro el array de clientes */
    {
        char localidadTexto[51];
        if(listaClientes[i].estado == OCUPADO) /** Si la posicion i de la lista de clientes esta ocupada, muestro ese cliente */
        {
            for(a=0; a<loc; a++)
            {
                if(listaDeLocalidades[a].idLocalidad == listaClientes[i].localidad)
                {
                    strcpy(localidadTexto, listaDeLocalidades[a].localidad);
                }
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

void inicializarClientes(eCliente listaClientes[], int len)
{
    int i;
    for(i=0; i<len; i++) /** Recorro el array de clientes */
    {
        listaClientes[i].estado=VACIO; /** Inicializo los estados como vacios para que no se carge basura */
        listaClientes[i].idCliente=0; /** Inicializo los id de clientes en cero para que no se carge basura */
    }
}

void agregarCliente(eCliente listaClientes[], int len)
{
    int posicion;
    int elegirLocalidad;
    int retorno;

    posicion = buscarLibreCliente(listaClientes, len); /** Llamo a la funcion buscarLibreCliente(); y guardo la posicion que retorna en la variable */
    if(posicion!=-1) /** Si la posicion que retorna es distinta a -1 (Posicion invalida) entro */
    {
        listaClientes[posicion].idCliente = crearIdCliente(listaClientes, len); /** Asigno el id autoincremental al id de ese cliente */
        /** Pido todos los datos del cliente y los guardo en la posicion libre encontrada por buscarLibreCliente(); */
        do
        {
            retorno = getWord(listaClientes[posicion].nombre, "\nIngrese el Nombre del Cliente: ");
        }while(retorno!=0);

        do
        {
            retorno = getWord(listaClientes[posicion].apellido,"\nIngrese el Apellido del Cliente: ");
        }while(retorno!=0);

        elegirLocalidad = getInt("\n1.Quilmes\n2.Rosario\n3.Santa Rosa\nSeleccione la localidad: ", "\n1.Quilmes\n2.Rosario\n3.Santa Rosa\nError, seleccione una localidad valida: ", 1, 3);
        listaClientes[posicion].localidad = elegirLocalidad;
        getWord(listaClientes[posicion].telefono, "\nIngrese el telefono: ");
        listaClientes[posicion].edad = getInt("\nIngrese la Edad: ","\nError, ingrese una edad valida: ",0,100);
        listaClientes[posicion].sexo = getChar("\nIngrese el sexo ('f'o'm'): ", "\nError, ingrese un sexo valido: ", 'f', 'm');
        listaClientes[posicion].estado = OCUPADO;
        printf("\nCliente agregado exitosamente\n");
    }
}

void modificarCliente(eCliente listaClientes[], int len, eLocalidad listaDeLocalidades[], int loc)
{
    eCliente auxCliente;
    int id;
    int i, a;
    int opcion;
    int retorno;
    char respuesta;
    /** Pido un id entre el 1 y el tamaño de clientes y lo guardo en la variable*/
    id = getInt("\nIngrese id del cliente que quiere modificar: ","\nError, ingrese un id valido: ", 1, len);

    for(i=0; i<len; i++) /** Recorro el array de clientes */
    {
        char localidadTexto[51];
        /** Si la posicion ingresada por el usuario es igual al id de la posicion i y la posicion i en estado es igual a ocupado entro */
        if(listaClientes[i].idCliente == id && listaClientes[i].estado == OCUPADO)
        {
            for(a=0; a<loc; a++)
            {
                if(listaDeLocalidades[a].idLocalidad == listaClientes[i].localidad)
                {
                    strcpy(localidadTexto, listaDeLocalidades[a].localidad);
                }
            }
            strcpy(auxCliente.nombre, listaClientes[i].nombre);
            strcpy(auxCliente.apellido, listaClientes[i].apellido);
            auxCliente.localidad = listaClientes[i].localidad;
            strcpy(auxCliente.telefono, listaClientes[i].telefono);
            auxCliente.edad = listaClientes[i].edad;
            auxCliente.sexo = listaClientes[i].sexo;
            do /** Muestro el cliente en la posicion encontrada */
            {
                printf("\nID CLIENTE     NOMBRE   APELLIDO   LOCALIDAD  TELEFONO          EDAD        SEXO");
                printf("\n%5d %15s %10s %12s %10s %10d %10c\n", listaClientes[i].idCliente,
                                                                auxCliente.nombre,
                                                                auxCliente.apellido,
                                                                localidadTexto,
                                                                auxCliente.telefono,
                                                                auxCliente.edad,
                                                                auxCliente.sexo);
                printf("\nMenu edicion\n");
                printf("\n1).Nombre\n");
                printf("2).Apellido\n");
                printf("3).Localidad\n");
                printf("4).Telefono\n");
                printf("5).Edad\n");
                printf("6).Sexo\n");
                printf("7).Guardar cambios\n");
                printf("8).Salir menu edicion\n");
                opcion = getInt("Elija una opcion: ","Error, elija una opcion valida: ",1,8);
                system("cls");
                /** Muestro el menu de edicion, pido la opcion, la guardo en la variable y limpio la consola para emprolijar el programa */
                switch(opcion)
                {
                /** Edito el campo segun el caso */
                case 1:
                    do
                    {
                        retorno = getWord(auxCliente.nombre,"\nIngrese el nuevo Nombre: ");
                    }while(retorno!=0);
                    break;
                case 2:
                    do
                    {
                        retorno = getWord(auxCliente.apellido,"\nIngrese el nuevo Apellido: ");
                    }while(retorno!=0);
                    break;
                case 3:
                    auxCliente.localidad = getInt("\n1.Quilmes\n2.Rosario\n3.Santa Rosa\nSeleccione la localidad: ", "\n1.Quilmes\n2.Rosario\n3.Santa Rosa\nError, seleccione una localidad valida: ", 1, 3);
                    break;
                case 4:
                    getWord(auxCliente.telefono,"\nIngrese el nuevo Telefono: ");
                    break;
                case 5:
                    auxCliente.edad = getInt("\nIngrese la nueva edad: ","Error, ingrese una edad valida", 0, 100);
                    break;
                case 6:
                    auxCliente.sexo = getChar("\nIngrese el nuevo sexo ('f' o 'm'): ","\nError ingrese ('f' o 'm'): ", 'f', 'm');
                    break;
                case 7:
                    respuesta = getChar("\nDesea guardar los cambios? (Enter=si / n=No): ", "\nError, ingrese (Enter=si / n=No): ", '\n', 'n');
                    if(respuesta == '\n')
                    {
                        strcpy(listaClientes[i].nombre, auxCliente.nombre);
                        strcpy(listaClientes[i].apellido, auxCliente.apellido);
                        listaClientes[i].localidad = auxCliente.localidad;
                        strcpy(listaClientes[i].telefono, auxCliente.telefono);
                        listaClientes[i].edad = auxCliente.edad;
                        listaClientes[i].sexo = auxCliente.sexo;
                        printf("\nLos datos han sido guardados satisfactoriamente!\n");
                    }else if(respuesta == 'n'){
                        printf("\nEl guardado de datos ha sido cancelado\n");
                    }
                    break;

                }
            }
            while(opcion!=8); /** Mientras la opcion ingresada sea distinta de 7, si es igual salgo */
        }
    }
}

int buscarLibreCliente(eCliente listaClientes[], int len)
{
    int i;
    int retorno = -1; /** Valor para saber si devuelve una posicion valida o no */
    for(i=0; i<len; i++) /** Recorro el array de clientes */
    {
        if(listaClientes[i].estado == VACIO) /** Si la lista de clientes en la posicion i esta vacia, entro */
        {
            retorno = i; /** Guardo esa posicion vacia en la variable*/
            break; /** Y rompo para que no siga iterando */
        }
    }
    return retorno; /** Retorno la posicion vacia */
}

int crearIdCliente()
{
    static int id=0; /** Variable estatica para que cada vez que incrementa el numero quede en ese mismo y no se inicialice en cero nuevamente */
    id++; /** Incremento en uno el numero estatico */
    return id; /** Retorno el id */
}

void porcentajeDeMujeres(eCliente listaClientes[], int len)
{
    int i;
    int contadorMujeres=0;
    float porcentajeMujeres=0;
    int totalOcupados=0;
    /** Genero todos los acumuladores, contadores y promedios*/

    for(i=0; i<len; i++) /** Recorro el array de clientes */
    {
        if(listaClientes[i].estado == OCUPADO) /** Si la lista de clientes en la posicion i esta ocupada, entro */
        {
            totalOcupados++;
            if(listaClientes[i].sexo == 'f') /** Si la lista de clientes en la posicion i en sexo es igual a f entro */
            {
                contadorMujeres++; /** Aumento el contador f */
            }
        }
    }
    if(contadorMujeres>0) /** Si el contador f es mayor a cero, se que hay al menos una mujer en la lista y entro */
    {
        porcentajeMujeres=((float)contadorMujeres*100)/totalOcupados; /** Calculo el promedio y lo guardo en la variable f */
        printf("\nEl Porcentaje de clientas mujeres es: %% %.1f\n", porcentajeMujeres); /** Imprimo el promedio f */
    }else
    {
        printf("\nNo hay Clientas mujeres para promediar\n"); /** Sino informo que no hay nada para mostrar */
    }
}

void mostrarClientesPorLocalidad(eCliente listaClientes[], int len, eLocalidad listaDeLocalidades[], int loc)
{
    int i, a;
    int flag=0;
    int localidad;

    localidad = getInt("\n1.Quilmes\n2.Rosario\n3.Santa Rosa\nSeleccione la localidad para listar sus clientes: ", "\n1.Quilmes\n2.Rosario\n3.Santa Rosa\nError seleccione una localidad valida: ", 1, 3);

    for(i=0; i<len; i++)
    {
        char localidadTexto[51];
        if(listaClientes[i].estado == OCUPADO)
        {
            for(a=0; a<loc; a++)
            {
                if(listaDeLocalidades[a].idLocalidad == listaClientes[i].localidad)
                {
                    strcpy(localidadTexto, listaDeLocalidades[a].localidad);
                }
            }
            if(flag==0)
            {
                printf("\nLista de por localidad: %s\n", localidadTexto);
                printf("\nID CLIENTE     NOMBRE   APELLIDO        LOCALIDAD      TELEFONO         EDAD        SEXO\n");
                flag=1;
            }
            if(listaClientes[i].localidad==localidad)
            {
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
}

void ordenarClientesPorDescripcionYNombre(eCliente listaClientes[], int len, eLocalidad listaDeLocalidades[], int loc)
{
    eCliente auxCliente;
    int i, j, a, b;

    for(i=0; i<len-1; i++)
    {
        if(listaClientes[i].estado==OCUPADO)
        {
            for(j=0; j<loc; j++)
            {
                if(listaDeLocalidades[j].idLocalidad==listaClientes[i].localidad)
                {
                    for(a=i+1; a<len; a++)
                    {
                        if(listaClientes[a].estado==OCUPADO)
                        {
                            for(b=0; b<loc; b++)
                            {
                                if(listaDeLocalidades[b].idLocalidad==listaClientes[a].localidad)
                                {

                                    if(strcmp(listaDeLocalidades[j].descripcion, listaDeLocalidades[b].descripcion)>0)
                                    {
                                        auxCliente = listaClientes[i];
                                        listaClientes[i] = listaClientes[a];
                                        listaClientes[a] = auxCliente;
                                        }else if(strcmp(listaDeLocalidades[j].descripcion, listaDeLocalidades[b].descripcion)>0)
                                        {
                                        if(strcmp(listaClientes[i].nombre, listaClientes[a].nombre)>0)
                                        {
                                            auxCliente = listaClientes[i];
                                            listaClientes[i] = listaClientes[a];
                                            listaClientes[a] = auxCliente;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("\nLa lista fue ordenada satisfactoriamente...\n\n");
}
