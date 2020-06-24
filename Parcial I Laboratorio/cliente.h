#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#define OCUPADO 1
#define VACIO 0
#define C 10

typedef struct
{
 int idCliente;
 char nombre[51];
 char apellido[51];
 int localidad;
 char telefono[51];
 int edad;
 char sexo;
 int estado;
}eCliente;

typedef struct
{
 int idClienteMascotas;
 int estado;
 int mascotas;
}eMascotasPorCliente;

typedef struct
{
 int idLocalidad;
 char localidad[51];
 char provincia[51];
 char codigoPostal[51];
 char descripcion[51];
}eLocalidad;

/** \brief - Harcodeo de datos corriente
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void harcordearClientes(eCliente listaClientes[], int len);

/** \brief - Inicializa todos los estados para que no se muestre basura
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void inicializarClientes(eCliente listaClientes[], int len);

/** \brief - Pide los datos del cliente y los guarda en una posicion libre
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void agregarCliente(eCliente listaClientes[], int len);

/** \brief - Recorre el array y busca una posicion libre, esta funcion es llamada desde agregarCliente();
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array
 * \return int - Devuelve la posicion que encuentre libre, o -1 en caso de no encontrar nada
 *
 */
int buscarLibreCliente(eCliente listaClientes[], int len);

/** \brief - Crea un id unico mediante una variable estatica, es llamada desde agregarCliente();
 *
 * \return int - Retorna el id creado
 *
 */
int crearIdCliente();

/** \brief - Pide el id del cliente que se desea modificar, si es valido, desplega un menu de opciones para editar los campos
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void modificarCliente(eCliente listaClientes[], int len, eLocalidad listaDeLocalidades[], int loc);

/** \brief - Recorre el array de clientes y muestra las posiciones ocupadas
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void mostrarClientes(eCliente listaClientes[], int len, eLocalidad listaDeLocalidades[], int loc);

/** \brief - Recorre el array de clientes, calcula y muestra el porcentaje de mujeres sobre el total de clientes activos
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array
 * \return void
 *
 */
void porcentajeDeMujeres(eCliente listaClientes[], int len);

void mostrarClientesPorLocalidad(eCliente listaClientes[], int len, eLocalidad listaDeLocalidades[], int loc);

void ordenarClientesPorDescripcionYNombre(eCliente listaClientes[], int len, eLocalidad listaDeLocalidades[], int loc);
