#include <stdio.h>
#include <stdlib.h>
#include "clienteMascota.h"
#define R 6
#define L 3

int main()
{
    /** Genero las variables de tipo estructura para pasarselas a menuOpciones(); */
    eCliente listaClientes[C];
    eMascota listaMascotas[M];
    eMascotasPorCliente listaMascotasPorCliente[C];
    eRaza listaDeRazas[R]={{1, "Doberman", "China", "perro"},{2, "Golden", "EEUU", "perro"},{3, "Persa", "España", "gato"},{4, "Siames", "Paris", "gato"},{5, "Puma", "Egipto", "raro"},{6, "Serpiente", "EEUU", "raro"}};
    eLocalidad listaDeLocalidades[L]={{1, "Quilmes", "", "", "Normal"},{2, "Rosario", "", "", "Turbio"},{3, "Santa Rosa", "", "", "Amigable"}};
    //inicializarClientes(listaClientes, C);
    //inicializarMascotas(listaMascotas, M);
    /** Comento los inicializadores para harcodear los datos */
    harcordearClientes(listaClientes, C);
    harcordearMascotas(listaMascotas, M);

    menuOpciones(listaClientes, C, listaMascotas, M, listaMascotasPorCliente, listaDeRazas, R, listaDeLocalidades, L); /** Llamo a la funcion menuOpciones(); que contiene el menu con el do while */
    return 0;
}
