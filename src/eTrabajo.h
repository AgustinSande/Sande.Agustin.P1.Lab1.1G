/*
 * eTrabajo.h
 *
 *  Created on: 21 oct 2022
 *      Author: Agustín
 */
#ifndef ETRABAJO_H_
#define ETRABAJO_H_

#include "eFecha.h"
typedef struct{
	int id;
	int idNotebook;
	int idServicio;
	eFecha fecha[10];
	int isEmpty;

}eTrabajo;



#endif /*ETRABAJO_H_*/

