#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#define OCUPADO 1
#define VACIO 0
#define M 20

typedef struct
{
 int idMascota;
 int idDuenio;
 char nombreMascota[51];
 char tipo[51];
 int idRazaMascota;
 int edadMascota;
 int peso;
 char sexoMascota;
 int estado;
}eMascota;

typedef struct
{
 int idRaza;
 char nombreDeRaza[51];
 char pais[51];
 char tipo[51];
}eRaza;
/** \brief - Harcodeo de datos corriente
 *
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array
 * \return void
 *
 */
void harcordearMascotas(eMascota listaMascotas[], int tam);

/** \brief - Inicializa todos los estados para que no se muestre basura
 *
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array
 * \return void
 *
 */
void inicializarMascotas(eMascota listaMascotas[], int tam);

/** \brief - Pide los datos de la mascota y los guarda en una posicion libre
 *
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array de mascotas
 * \param len int - Recibe el tamaño del array de clientes
 * \return void
 *
 */
void agregarMascota(eMascota listaMascotas[], int tam, int len, eRaza listaDeRazas[], int raz);

/** \brief - Recorre el array y busca una posicion libre, esta funcion es llamada desde agregarMascota();
 *
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array
 * \return int - Devuelve la posicion que encuentre libre, o -1 en caso de no encontrar nada
 *
 */
int buscarLibreMascota(eMascota listaMascotas[], int tam);

/** \brief - Crea un id unico mediante una variable estatica, es llamada desde agregarMascota();
 *
 * \return int - Retorna el id creado
 *
 */
int crearIdMascota();

/** \brief - Pide el id de la mascota que se desea eliminar, pregunta y si la respuesta es si, se marca esa posicion como Vacia
 *
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array
 * \return void
 *
 */
void bajaMascota(eMascota listaMascotas[], int tam);

/** \brief - Ordena el listado de mascotas por tipo, recorriendo el array
 *
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array
 * \return void
 *
 */
void ordenarMascotasPorTipo(eMascota listaMascotas[], int tam);

/** \brief - Muestra las mascotas por tipo, recorriendo el array
 *
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array
 * \return void
 *
 */
void mostrarMascotasPorTipo(eMascota listaMascotas[], int tam, eRaza listaDeRazas[], int raz);

/** \brief - Calcula y muestra el promedio de edad de las mascotas
 *
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array
 * \return void
 *
 */
void mostrarPromedioDeEdadDeMascotas(eMascota listaMascotas[], int tam);

/** \brief - Calcula, muestra el promedio de edad de las mascotas por tipo
 *
 * \param listaMascotas[] eMascota eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array
 * \return void
 *
 */
void mostrarPromedioDeEdadDeMascotasPorTipo(eMascota listaMascotas[], int tam);



