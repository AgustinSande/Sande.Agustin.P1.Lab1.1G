/*
 * eTipo.h
 *
 *  Created on: 21 oct 2022
 *      Author: Agustín
 */

#ifndef ETIPO_H_
#define ETIPO_H_

typedef struct{
	int id;
	char descripcion[20];


}eTipo;

/// @fn int mostrarTipo(eTipo[], int)
/// @brief muestra la lista de tipos existentes
///
/// @param tipo array de estructuras eTipo
/// @param tam tamaño del array tipo
/// @return 1 si esta pudo mostrar los tipos, 0 si no
int mostrarTipo(eTipo tipo[], int tam);
/// @fn int cargarTipo(eTipo[], int, int, char[])
/// @brief carga la descripcion del tipo que elijamos mediante su id en un vector de caracteres
///
/// @param tipo array de estructuras eTipo
/// @param tam tamaño del array tipo
/// @param idTipo id del tipo que deseamos utilizar
/// @param tipoCargar vector de caracteres que vamos a cargar con la descripcion del tipo que elegimos mediante el id
/// @return
int cargarTipo(eTipo tipo[], int tam, int idTipo, char tipoCargar[]);

#endif /* ETIPO_H_ */
