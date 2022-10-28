/*
 * eServicio.h
 *
 *  Created on: 21 oct 2022
 *      Author: Agustín
 */

#ifndef ESERVICIO_H_
#define ESERVICIO_H_

typedef struct{
	int id;
	char descripcion[25];
	int precio;

}eServicio;
/// @fn int mostrarServicio(eServicio[], int)
/// @brief muestra la lista de servicios existentes
///
/// @param servicio array de estructuras eServicio
/// @param tam tamaño del array
/// @return 1 si esta pudo mostrar los servicios, 0 si no
int mostrarServicio(eServicio servicio[], int tam);

/// @fn int cargarServicio(eServicio[], int, int, char[])
/// @brief carga la descripcion del servicio que elijamos mediante su id en un vector de caracteres
///
/// @param servicios array de estructuras eServicio
/// @param tam tamaño del array
/// @param idServicio ID del servicio que vamos a utilizar
/// @param servicio vector de caracteres en el que vamos a cargar la descripcion del serivio que elegimos utilizar
/// @return 1 si pudo cargar el servicio en el vector de caracteres, 0 si no
int cargarServicio(eServicio servicios[], int tam, int idServicio, char servicio[]);

#endif /* ESERVICIO_H_ */
