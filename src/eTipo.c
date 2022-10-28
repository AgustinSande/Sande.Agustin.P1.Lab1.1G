/*
 * eTipo.c
 *
 *  Created on: 21 oct 2022
 *      Author: Agustín
 */



#include "eTipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int mostrarTipo(eTipo tipo[], int tam){

	int todoOk = 0;
			limpiarPantalla();
			if (tipo != NULL && tam > 0) {

				printf("                                         *** Lista de Tipos ***        \n");
				printf(
						"-------------------------------------------------------------------------------------------------\n");
				printf(
						"|  ID  |         NOMBRE           | \n");
				printf(
						"-------------------------------------------------------------------------------------------------\n");

			for(int i= 0; i < tam; i++){

				printf("|  %-4d|           %-20s    \n", tipo[i].id, tipo[i].descripcion);
			}


			todoOk=1;

			}return todoOk;




}



int cargarTipo(eTipo tipo[], int tam, int idTipo, char tipoCargar[]){
	int todoOk = 0;

		if(tipo != NULL && tam > 0 && tipoCargar != NULL){
			for(int i= 0; i < tam; i++){
				if(tipo[i].id == idTipo){
					strcpy(tipoCargar, tipo[i].descripcion);
					break;
				}


			}



			todoOk = 1;
		}



		return todoOk;







}
