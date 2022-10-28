/*
 ============================================================================
 Name        : Parcial.c
 Author      : Agustin Sande
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#define TAM_M 4
#define TAM_T 4
#define TAM_S 4
#define TAM 10
#define TAM_C 6
#define TAM_F 10
#define TAM_TRABAJOS 10
#define TAM_CLIENTE 4


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "dataWarehouse.h"
#include "eNotebook.h"
//#include "eTrabajo.h"
//#include "eMarca.h"
//#include "eTipo.h"
//#include "eFecha.h"
//#include "eServicio.h"



int main(void) {
	setbuf(stdout, NULL);
	char seguir = 's';
	int nextId = 1;
	int nextIdTrabajo = 1;

	int notebooksCargadas = 0;

	eNotebook lista[TAM];
	eTrabajo listaTrabajo[TAM_TRABAJOS];
	eFecha fecha[TAM_F];
	eCliente cliente[TAM_CLIENTE] = {
			{1, "Juan",  'm'},{2, "Maria", 'f'},{3, "Pablo", 'm'},{4, "Lucio", 'm'}
	};
	eMarca marca[TAM_M] = {
	{1000, "CompaQ"},{1001, "Asus"}, {1002, "Acer"}, {1003, "HP"}

	};
	eTipo tipo[TAM_T] = {
			{5000, "Gamer"}, {5001, "Disenio"}, {5002, "Ultrabook"}, {5003, "Normalita"}


	};
	eServicio servicio[TAM_S] = {

			{20000, "Bateria", 2250},
			{20001, "Display", 10300},
			{20002, "Teclado", 4000},
			{20003, "Fuente", 5600},




	};


	if (!inicializarNotebook(lista, TAM)) {
		printf("Problema al inicializar!\n");
	}
	inicializarTrabajo(listaTrabajo, TAM_T);
	hardcodearNotebook(lista, TAM, 10, &nextId);
	//No funciona para las fechas :(
	hardcodearTrabajo(listaTrabajo, TAM_TRABAJOS, 4, &nextIdTrabajo );

		do {
			for (int i = 0; i < TAM; i++) {

				if (!lista[i].isEmpty) {
					notebooksCargadas = 1;
					break;
				} else {
					notebooksCargadas = 0;
				}
			}
			switch (menu()) {

			case 1:
				if (!altaNotebook(lista, TAM, &nextId, marca, TAM_M, tipo, TAM_T, cliente, TAM_CLIENTE)) {
					printf("No se pudo realizar el alta\n");
				} else {

					printf("Alta exitosa\n 	");
				}
				break;
			case 2:
				if (!notebooksCargadas) {
					printf(
							"No hay notebooks cargadas. Cargue al menos una notebook para realizar una modificacion! \n");
					break;
				}
				modificarNotebook(lista, TAM, marca, TAM_M, tipo, TAM_T, cliente, TAM_CLIENTE);
				break;


			case 3:

				if (!notebooksCargadas) {
					printf(
							"No hay notebooks cargadas. Cargue al menos una notebook para realizar una modificacion! \n");

				} else if (!bajaNotebook(lista, TAM, marca, TAM_M, tipo, TAM_T,cliente, TAM_CLIENTE)) {
					printf("No se pudo realizar la baja\n");
				} else {

					printf("Baja exitosa\n 	");
				}

				break;
			case 4:
				if (!notebooksCargadas) {
					printf(
							"No hay notebooks cargadas. Cargue al menos una notebook para realizar una modificacion! \n");

				} else {
					mostrarNotebooks(lista, TAM, marca, TAM_M, tipo, TAM_T,cliente, TAM_CLIENTE);
				}
				break;
			case 5: mostrarMarca(marca, TAM_M);
				break;
			case 6:mostrarTipo(tipo, TAM_T);
				break;
			case 7: mostrarServicio(servicio, TAM_S);
				break;
			case 8: altaTrabajo(lista, TAM, listaTrabajo, TAM_TRABAJOS, &nextIdTrabajo, marca, TAM_M, tipo, TAM_T, servicio, TAM_S, fecha, TAM_F, cliente, 4);
				break;
			case 9: mostrarTrabajos(listaTrabajo, servicio, TAM_T, TAM_S);
				break;
			case 10:realizarInformes(lista, TAM, marca, TAM_M,  tipo, TAM_T,cliente, TAM_CLIENTE);
				break;
			case 11:printf("Ha seleccionado salir\n");

			confirmarSalida(&seguir);
			if (seguir == 's') {
				printf("Ha cancelado la salida de la aplicacion \n");
			} else {
				printf("Ha salido de la aplicacion con exito!\n");

			}
			break;

			default:
				printf("Opcion invalida!\n");
			}
			system("pause");

		} while (seguir == 's');



	return 0;
}



