/*
 * eCliente.c
 *
 *  Created on: 28 oct 2022
 *      Author: Agustín
 */
#include "eCliente.h"
#include "biblioteca.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int mostrarCliente(eCliente cliente[], int tamC){

	int todoOk = 0;
			limpiarPantalla();
			if (cliente != NULL && tamC > 0) {

				printf("                                         *** Lista de Tipos ***        \n");
				printf(
						"-------------------------------------------------------------------------------------------------\n");
				printf(
						"|  ID  |         NOMBRE           | SEXO |\n");
				printf(
						"-------------------------------------------------------------------------------------------------\n");

			for(int i= 0; i < tamC; i++){

				printf("|  %-4d|           %-20s    |  %c\n", cliente[i].id, cliente[i].nombre, cliente[i].sexo);
			}


			todoOk=1;

			}return todoOk;




}


int cargarCliente(eCliente cliente[], int tam, int idCliente, char clienteCargar[]){
	int todoOk = 0;

		if(cliente != NULL && tam > 0 && clienteCargar != NULL){
			for(int i= 0; i < tam; i++){
				if(cliente[i].id == idCliente){
					strcpy(clienteCargar, cliente[i].nombre);

					break;
				}


			}



			todoOk = 1;
		}



		return todoOk;







}
