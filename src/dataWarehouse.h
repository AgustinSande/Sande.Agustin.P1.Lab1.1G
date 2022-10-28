/*
 * DataWarehouse.h
 *
 *  Created on: 17 oct 2022
 *      Author: Agustín
 */
#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_

//#include "eNotebook.h"
#include "eTrabajo.h"
/// @fn int hardcodearTrabajo(eTrabajo[], int, int, int*)
/// @brief
///
/// @param listaTrabajos array de estructuras eTrabajo
/// @param tam tamaño del array
/// @param cant cantidad de estructuras que se quieren hardcodear
/// @param pId Id del trabajo actual
/// @return
int hardcodearTrabajo(eTrabajo listaTrabajos[], int tam, int cant, int* pId);
//int hardcodearNotebook(eNotebook lista[], int tam, int cant, int* pId);
//int hardcodeoListaConfederaciones(eConfederacion listaConfederacion[], int tam);


#endif /* DATAWAREHOUSE_H_ */
