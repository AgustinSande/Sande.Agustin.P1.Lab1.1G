/*
 * eTrabajo.c
 *
 *  Created on: 21 oct 2022
 *      Author: Agustín
 */
#include "eTrabajo.h"
#include "eNotebook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "biblioteca.h"
//#include "dataWarehouse.h"

//#include "eNotebook.h"
//#include "eMarca.h"
//#include "eFecha.h"

int altaTrabajo(eNotebook lista[], int tam, eTrabajo listaTrabajos[],
		int tamTrabajo, int *pId, eMarca marca[], int tamM, eTipo tipo[],
		int tamT, eServicio servicio[], int tamS, eFecha fecha[], int tamF, eCliente cliente[], int tamC) {

	//int indice;
	eTrabajo auxTrabajo;
//	int id;
	//int idServicio;
	int todoOk = 0;
	int indice;
	char confirma;
	//char servicioDesc[];
	if (listaTrabajos != NULL && tam > 0) {
		limpiarPantalla();
		printf(" ***   Alta Trabajo   *** \n");
		mostrarNotebooks(lista, tam, marca, tamM, tipo, tamT, cliente, tamC);

		do {
				if (utn_getNumero(&auxTrabajo.idNotebook, "Ingrese el numero de ID de la Notebook: \n",
									"Su numero no pudo ser validado\n Ingrese nuevamente un numero de ID de Notebook existente\n",
									0, 10000000) == 1) {
								printf("Su numero fue valido correctamente!\n");

							}
				indice = buscarNotebookId(lista, tam, auxTrabajo.idNotebook);
				if (indice == -1) {

								printf("El id ingresado no pertenece al sistema.\n");
							}
			}while (indice == -1);


		mostrarNotebook(lista[indice],tam, marca, tamM, tipo, tamT, cliente, tamC);
		printf("Confirma que quiere añadirle un trabajo a esta notebook?");
		fflush(stdin);

		confirma = tolower(getchar());
		while (!validarCaracter(confirma, 's', 'n')) {
			printf(
					"Caracter Invalido. Reingrese caracter valido para confirmar (s para confirmar - n para no confirmar): \n");
			fflush(stdin);
			confirma = tolower(getchar());

		}
		printf("\n\n");
		if (confirma == 's') {

			mostrarServicio(servicio, tamS);
			if (utn_getNumero(&auxTrabajo.idServicio,
					"Ingrese el numero de ID del servicio: \n",
					"Su numero no pudo ser validado\n Ingrese nuevamente un numero de ID de Servicio existente\n",
					20000, 20003) == 1) {
				printf("Su numero fue valido correctamente!\n");
			}
			if (utn_getNumero(&auxTrabajo.fecha[(*pId)].dia, "Ingrese el dia: \n",
					"Su numero no pudo ser validado\n Ingrese nuevamente un dia valido (0-31)\n",
					0, 31) == 1) {
				printf("Su numero fue valido correctamente!\n");
			}
			if (utn_getNumero(&auxTrabajo.fecha[(*pId)].mes, "Ingrese el mes: \n",
					"Su numero no pudo ser validado\n Ingrese nuevamente un mes valido(0-12)\n",
					0, 12) == 1) {
				printf("Su numero fue valido correctamente!\n");
			}
			if (utn_getNumero(&auxTrabajo.fecha[(*pId)].anio, "Ingrese el Año: \n",
					"Su numero no pudo ser validado\n Ingrese nuevamente un año valido\n",
					1990, 2022) == 1) {
				printf("Su numero fue valido correctamente!\n");
			}
			auxTrabajo.isEmpty = 0;
		}




	}

	auxTrabajo.id = *pId;
	listaTrabajos[(*pId)] = auxTrabajo;
	(*pId)++;


	todoOk = 1;
	return todoOk;
}



int mostrarTrabajo(eTrabajo p, eServicio servicio[], int tamT, int i){

char servicioDesc[20];
int todoOk = 0;
if(servicio != NULL && tamT > 0){
	cargarServicio(servicio, tamT, p.idServicio, servicioDesc);
	printf(
				"| %-2d |       %-4d       |      %-8d      |    %-12s  |  %-2d   |  %-2d | %-4d |\n",
				p.id, p.idNotebook, p.idServicio,servicioDesc, p.fecha[i].dia, p.fecha[i].mes,
				p.fecha[i].anio );

	todoOk = 1;
}


return todoOk;
}



int mostrarTrabajos(eTrabajo lista[], eServicio servicio[], int tamT, int tamS){
	int todoOk = 0;

	limpiarPantalla();
	if(lista != NULL && servicio != NULL && tamT > 0 && tamS > 0){
		printf(
						"                                *** Lista de Trabajos ***                               \n");
				printf(
						"----------------------------------------------------------------------------------------\n");
				printf(
						"|  ID  |  ID de Notebook  |    ID Servicio     |     Servicio     |  Dia  | Mes | Anio |\n");
				printf(
						"----------------------------------------------------------------------------------------\n");

				for (int i = 0; i < tamT; i++) {
					if(!lista[i].isEmpty){
						mostrarTrabajo(lista[i], servicio, tamT, i);
					}

				}


		todoOk = 1;
	}



	return todoOk;
}

int inicializarTrabajo(eTrabajo lista[], int tamT) {

	int todoOk = 0;
	if (lista != NULL && tamT > 0) {
		for (int i = 0; i < tamT; i++) {

			lista[i].isEmpty = 1;
		}

		todoOk = 1;
	}
	return todoOk;
}



