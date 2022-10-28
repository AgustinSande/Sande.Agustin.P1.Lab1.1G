/*
 * eCliente.h
 *
 *  Created on: 28 oct 2022
 *      Author: Agustín
 */

#ifndef ECLIENTE_H_
#define ECLIENTE_H_

typedef struct{
	int id;
	char nombre[20];
	char sexo;

}eCliente;

/// @fn int mostrarCliente(eCliente[], int)
/// @brief muestra la lista de clientes
///
/// @param cliente array de estructuras eCliente
/// @param tamC tamaño del array
/// @return
int mostrarCliente(eCliente cliente[], int tamC);

/// @fn int cargarCliente(eCliente[], int, int, char[])
/// @brief carga el nombre de un cliente en un vector de caracteres
///
/// @param cliente array de estructuras eClient
/// @param tam tamaño del array
/// @param idCliente   Id del cliente que deseamos utilizar
/// @param clienteCargar  Vector de caracteres en donde se va a cargar el nombre del cliente con el id que utilizamos
/// @return
int cargarCliente(eCliente cliente[], int tam, int idCliente, char clienteCargar[]);
#endif /* ECLIENTE_H_ */
