


#include "eMarca.h"
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <string.h>
int mostrarMarca(eMarca marca[], int tam){

	int todoOk = 0;
		limpiarPantalla();
		if (marca != NULL && tam > 0) {

			printf("                                         *** Lista de Confederaciones ***        \n");
			printf(
					"-------------------------------------------------------------------------------------------------\n");
			printf(
					"|  ID  |         NOMBRE           | \n");
			printf(
					"-------------------------------------------------------------------------------------------------\n");

		for(int i= 0; i < tam; i++){

			printf("|  %-4d|           %-20s    \n", marca[i].id, marca[i].descripcion);
		}


		todoOk=1;

		}return todoOk;
}


int cargarMarca(eMarca marca[], int tam, int idMarca, char marcaCargar[]){
	int todoOk = 0;

		if(marca != NULL && tam > 0 && marcaCargar != NULL){
			for(int i= 0; i < tam; i++){
				if(marca[i].id == idMarca){
					strcpy(marcaCargar, marca[i].descripcion);
					break;
				}


			}



			todoOk = 1;
		}



		return todoOk;







}
