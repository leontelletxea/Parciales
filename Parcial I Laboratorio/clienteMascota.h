#include "cliente.h"
#include "mascota.h"
#include "validar.h"

/** \brief - Menu de opciones corriente con do while y llamadas a las funciones
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array de clientes
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array de mascotas
 * \param listaMascotasPorCliente[] eMascotasPorCliente - Recibe la lista de mascotas por cliente
 * \return void
 *
 */
void menuOpciones(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eMascotasPorCliente listaMascotasPorCliente[], eRaza listaDeRazas[], int raz, eLocalidad listaDeLocalidades[], int loc);

/** \brief - Recorre el array de mascotas y el de clientes, si coinciden sus id, los muestra juntos
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array de clientes
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array de mascotas
 * \return void
 *
 */
void mostrarMascotasConSusDuenios(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eRaza listaDeRazas[], int raz);

/** \brief - Recorre el array de clientes y el de mascotas, si coinciden sus id, los muestra juntos
 *
 * \param listaClientes[] eCliente eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array de clientes
 * \param listaMascotas[] eMascota eCliente - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array de mascotas
 * \return void
 *
 */
void mostrarClientesConSusMascotas(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eLocalidad listaDeLocalidades[], int loc);


/** \brief - Pide un id de cliente y si es valido, recorre el array y elimina a todas las mascotas de ese cliente
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array de clientes
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array de mascotas
 * \return void
 *
 */
void bajaClienteCascada(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam);

/** \brief - Recorre el array de clientes, el de mascotas y si el contador de mascotas por cliente es mayor a uno, muestra ese cliente
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array de clientes
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array de mascotas
 * \return void
 *
 */
void mostrarClientesConMasDeUnaMascota(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eLocalidad listaDeLocalidades[], int loc);

/** \brief - Recorre el array de mascotas y si la edad de la mascota es mayor a tres la muestra
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array de clientes
 * \param listaMascotas[] eMascota - Recibe la lista de clientes
 * \param tam int - Recibe el tamaño del array de clientes
 * \return void
 *
 */
void mostrarMascotasConMasDeTresAnios(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eRaza listaDeRazas[] , int raz);

/** \brief - Recorre el array de clientes y el de mascotas y ordena la lista por cantidad de mascotas
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array de clientes
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array de mascotas
 * \param listaMascotasPorCliente[] eMascotasPorCliente - Recibe la lista de mascotas por cliente
 * \return void
 *
 */
void ordenarClientesPorCantidadDeMascotas(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eMascotasPorCliente listaMascotasPorCliente[]);

/** \brief - Recorre el array de clientes y el de mascotas y ordena la lista por cantidad de mascotas y ante igualdad de criterio por nombre
 *
 * \param listaClientes[] eCliente - Recibe la lista de clientes
 * \param len int - Recibe el tamaño del array de clientes
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array de mascotas
 * \param listaMascotasPorCliente[] eMascotasPorCliente - Recibe la lista de mascotas por cliente
 * \return void
 *
 */
void ordenarClientesPorCantidadDeMascotasYNombres(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eMascotasPorCliente listaMascotasPorCliente[]);

/** \brief - Pide el id de la mascota que se desea modificar, si es valido, desplega un menu de opciones para editar los campos
 *
 * \param listaMascotas[] eMascota - Recibe la lista de mascotas
 * \param tam int - Recibe el tamaño del array
 * \return void
 *
 */
void modificarMascota(eMascota listaMascotas[], int tam, eRaza listaDeRazas[], int raz, eCliente listaClientes[], int len, eLocalidad listaDeLocalidades[], int loc);

void mostrarClientesConMasDeDosMascotaDelMismoSexo(eCliente listaClientes[], int len, eMascota listaMascotas[], int tam, eLocalidad listaDeLocalidades[], int loc);
