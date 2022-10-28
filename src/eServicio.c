/*
 * eServicio.c
 *
 *  Created on: 21 oct 2022
 *      Author: Agustín
 */




#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "eServicio.h"
#include <string.h>

int mostrarServicio(eServicio servicio[], int tam){

	int todoOk = 0;
			limpiarPantalla();
			if (servicio != NULL && tam > 0) {

				printf("                                         *** Lista de Servicios ***        \n");
				printf(
						"-------------------------------------------------------------------------------------------------\n");
				printf(
						"|  ID   |         NOMBRE          |  PRECIO | \n");
				printf(
						"-------------------------------------------------------------------------------------------------\n");

			for(int i= 0; i < tam; i++){

				printf("| %-4d |    %-20s | %-5d   |\n", servicio[i].id, servicio[i].descripcion, servicio[i].precio);
			}


			todoOk=1;

			}return todoOk;




}

int cargarServicio(eServicio servicios[], int tam, int idServicio,
		char servicio[]) {
	int todoOk = 0;

	if (servicios != NULL && tam > 0 && servicio != NULL) {
		for (int i = 0; i < tam; i++) {
			if (servicios[i].id == idServicio) {
				strcpy(servicio, servicios[i].descripcion);
				break;
			}

		}

		todoOk = 1;
	}

	return todoOk;

}

