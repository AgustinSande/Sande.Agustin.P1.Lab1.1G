/*
 * eJugador.h
 *
 *  Created on: 17 oct 2022
 *      Author: Agustín
 */

#ifndef EMARCA_H_
#define EMARCA_H_


typedef struct {
	int id;
	char descripcion[20];

}eMarca;
/// @fn int mostrarMarca(eMarca[], int)
/// @brief muestra la lista de marcas
///
/// @param marca array de estructuras eMarca
/// @param tam tamaño del array
/// @return
int mostrarMarca(eMarca marca[], int tam);

/// @fn int cargarMarca(eMarca[], int, int, char[])
/// @brief carga la descripcion de la marca que elijamos mediante su id en un vector de caracteres
///
/// @param marca array de estructuras eMarca
/// @param tam tamaño del array
/// @param idMarca  Id de la marca que deseamos utilizar
/// @param marcaCargar vector de caracteres en el que vamos a cargar la descripcion de la marca que elegimos utilizar
/// @return
int cargarMarca(eMarca marca[], int tam, int idMarca, char marcaCargar[]);


#endif /* EMARCA_H_ */
