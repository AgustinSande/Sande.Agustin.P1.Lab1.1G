/*
 * eNotebook.c
 *
 *  Created on: 21 oct 2022
 *      Author: Agustín
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#include "dataWarehouse.h"
#include "eNotebook.h"
#include "eTrabajo.h"
#include "eMarca.h"
#include "eFecha.h"
#include "eTipo.h"
#include "eServicio.h"
#include "eCliente.h"







int menu(){
	int opcion;
	limpiarPantalla();



	printf("     *** ABM Notebook  ***\n\n");
	printf(
			"1- Alta Notebook\n");
	printf("2- Baja Notebook\n");
	printf("3- Modificar Notebook\n");
	printf("4- Mostrar Notebooks\n");
	printf("5- Listar Marcas\n");
	printf("6- Listar Tipos\n");
	printf("7- Listar Servicios\n");
	printf("8- Alta Trabajo\n");
	printf("9- Listar Trabajos\n");
	printf("10- Realizar Informes\n");
	printf("11- Salir\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;

}

int inicializarNotebook(eNotebook lista[], int tam) {

	int todoOk = 0;
	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {

			lista[i].isEmpty = 1;
		}

		todoOk = 1;
	}
	return todoOk;
}

int buscarLibre(eNotebook lista[], int tam) {

	int indiceEstructuraVacia = -1;
	for (int i = 0; i < tam; i++) {

		if (lista[i].isEmpty) {
			indiceEstructuraVacia = i;
			break;
		}

	}

	return indiceEstructuraVacia;
}

int altaNotebook(eNotebook lista[], int tam, int *pId, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC) {
	int indice;
	eNotebook auxNotebook;
	int todoOk = 0;
	int i = 0;
	if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0) {
		limpiarPantalla();
		printf(" ***   Alta Notebook   *** \n");
		indice = buscarLibre(lista, tam);
		if (indice == -1) {
			printf("No hay lugar\n");
		} else {

			auxNotebook.id = *pId;
			(*pId)++;

			printf("Ingrese nombre del modelo: \n");
			fflush(stdin);
			gets(auxNotebook.modelo);
			strlwr(auxNotebook.modelo);
			auxNotebook.modelo[0] = toupper(auxNotebook.modelo[0]);
			while (auxNotebook.modelo[i] != '\0') {
				if (auxNotebook.modelo[i] == ' ') {
					auxNotebook.modelo[i + 1] = toupper(
							auxNotebook.modelo[i + 1]);
				}

				i++;
			}
			if(strlen(auxNotebook.modelo) > 20){
				printf("El nombre ingresado es demasiado largo. Reingrese nombre del modelo: \n");
				fflush(stdin);
				gets(auxNotebook.modelo);
				strlwr(auxNotebook.modelo);
				auxNotebook.modelo[0] = toupper(auxNotebook.modelo[0]);
				while (auxNotebook.modelo[i] != '\0') {
					if (auxNotebook.modelo[i] == ' ') {
						auxNotebook.modelo[i + 1] = toupper(
								auxNotebook.modelo[i + 1]);
					}

					i++;
				}


			}
			mostrarMarca(marca, tamM);
			if (utn_getNumero(&auxNotebook.idMarca,
					"Ingrese el numero de ID de la marca: \n",
					"Su numero no pudo ser validado\n Ingrese nuevamente un numero de ID de la marca (1000-1003)\n",
					1000, 1003) == 1) {
				printf("Su numero fue valido correctamente!\n");
			}
			mostrarTipo(tipo, tamT);
			if(utn_getNumero(&auxNotebook.idTipo, "Ingrese el numero de ID del tipo: \n",
						 "Su numero no pudo ser validado\n Ingrese nuevamente un ID del tipo valido (5000-5003)\n", 5000, 5003) == 1){
						 printf("Su numero fue valido correctamente!\n");
						 }
			if (utn_getNumero(&auxNotebook.precio,
								"Ingrese el precio: \n",
								"Su numero no pudo ser validado\n Ingrese nuevamente un precio valido (1-100000)\n",
								1, 100000) == 1) {
							printf("Su numero fue valido correctamente!\n");
						}
			mostrarCliente(cliente, tamC);
			if(utn_getNumero(&auxNotebook.idCliente, "Ingrese el numero de ID del cliente: \n",
									 "Su numero no pudo ser validado\n Ingrese nuevamente un ID del tipo valido (0,3)\n", 0, 3) == 1){
									 printf("Su numero fue valido correctamente!\n");
									 }

									}
//			mostrarConfederaciones(listaConfederacion, tamC);
//						if(utn_getNumero(&auxJugador.idConfederacion, "Ingrese el id de la confederacion: \n",
//												"Su numero no pudo ser validado\n Ingrese nuevamente un ID valido (100-105)\n", 100, 105) == 1){
//											printf("Su numero fue valido correctamente!\n");
//										}

			auxNotebook.isEmpty = 0;
			lista[indice] = auxNotebook;
			todoOk = 1;
		}
	return todoOk;
	}



void mostrarNotebook(eNotebook p, int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC) {
	char marcaDesc[20];
	char tipoDesc[20];

	char clienteDesc[20];
	cargarMarca(marca, tam, p.idMarca, marcaDesc);
	cargarTipo(tipo, tam, p.idTipo, tipoDesc);
	cargarCliente(cliente, tam, p.idCliente, clienteDesc);
	printf(
			"|  %-4d| %-6s   |   %-4d   |  %-4d    |  %-7d  |   %-12s   |  %-10s  |    %-15s    |\n",
			p.id, p.modelo,  p.idMarca, p.idTipo, p.precio,  marcaDesc, tipoDesc, clienteDesc);

}

int mostrarNotebooks(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC){
	int flag = 1;
	int todoOk = 0;
	eNotebook auxNotebook;
	limpiarPantalla();

	if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0) {


		printf("                                                  *** Lista de Notebooks ***        \n");
				printf(
						"--------------------------------------------------------------------------------------------------------------\n");
				printf(
						"|  ID  |  Modelo  | ID Marca | ID Tipo  |  Precio  |     Marca        |   Tipo       |  Nombre del cliente  | \n");
				printf(
						"--------------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < tam - 1; i++) {
								for (int j = i + 1; j <tam; j++) {
									if(lista[i].id > lista[j].id){
										auxNotebook = lista[i];
										lista[i] = lista[j];
										lista[j] = auxNotebook;

									}

								}

							}


		for (int i = 0; i < tam; i++) {
			if (!(lista[i].isEmpty)) {
				mostrarNotebook(lista[i], tam, marca, tamM, tipo, tamT, cliente, tamC);
				flag = 0;
			}





		}
		if (flag) {
			printf("No hay notebooks para mostrar\n");
		}

		todoOk = 1;
	}

	return todoOk;

}

int bajaNotebook(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC) {
	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	eNotebook auxNotebook;
	//eJugador auxJugador;
	if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0) {
		limpiarPantalla();
		mostrarNotebooks(lista, tam, marca, tamM, tipo, tamT, cliente, tamC);
		printf("\n\n      *** Baja Jugador ***     \n \n");

		printf("Ingrese ID: ");
		scanf("%d", &id);
		indice = buscarNotebookId(lista, tam, id);
		if (indice == -1) {
			printf("El ID: %d no esta registrado en el sistema\n", id);
		} else {
			for (int i = 0; i < tam - 1; i++) {
											for (int j = i + 1; j <tam; j++) {
												if(lista[i].id > lista[j].id){
													auxNotebook = lista[i];
													lista[i] = lista[j];
													lista[j] = auxNotebook;

												}

											}

										}
			mostrarNotebook(lista[indice], tam,marca, tamM, tipo, tamT, cliente, tamC);
			printf("Confirma baja?:\n");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's') {
				lista[indice].isEmpty = 1;
				todoOk = 1;
			} else {
				printf("Baja cancelada por el usuario \n");
			}

		}
	}

	return todoOk;
}

int buscarNotebookId(eNotebook lista[], int tam, int id) {
	int indice = -1;
	for (int i = 0; i < tam; i++) {

		if (lista[i].id == id && !lista[i].isEmpty) {
			indice = i;
			break;
		}

	}

	return indice;
}

int modificarNotebook(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC){

	int todoOk = 0;
	int indice;
	int id;
	int i=0;
	char confirma;
	char seguir = 's';

	eNotebook auxNotebook;
	 if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0) {
		limpiarPantalla();
		for (int i = 0; i < tam - 1; i++) {
										for (int j = i + 1; j <tam; j++) {
											if(lista[i].id > lista[j].id){
												auxNotebook = lista[i];
												lista[i] = lista[j];
												lista[j] = auxNotebook;

											}

										}

									}
		mostrarNotebooks(lista, tam, marca, tamM, tipo, tamT, cliente, tamC);
		printf("\n\n     *** Modificar Notebook ***     \n \n");
		if (utn_getNumero(&id, "Ingrese el ID: \n",
				"Su numero no pudo ser validado\n Ingrese nuevamente un ID valido\n",
				1, 99999999) == 1) {
			printf("Su numero fue valido correctamente!\n");
		}
		indice = buscarNotebookId(lista, tam, id);

		if (indice == -1) {
			printf("El ID: %d no esta registrado en el sistema\n", id);
		} else {
			mostrarNotebook(lista[indice], tam, marca, tamM, tipo, tamT, cliente, tamC);
			printf("Confirma que quiere modificar esta notebook?");
			fflush(stdin);
			//scanf("%c", &confirma);
			confirma = tolower(getchar());
			while (!validarCaracter(confirma, 's', 'n')) {
				printf(
						"Caracter Invalido. Reingrese caracter valido para confirmar (s para confirmar - n para no confirmar): \n");
				fflush(stdin);
				confirma = tolower(getchar());

			}
			printf("\n\n");
			if (confirma == 's') {
				do {
					mostrarNotebook(lista[indice], tam, marca, tamM, tipo, tamT, cliente, tamC);
					printf("---------------------------------------------------------------------------------------------------------------------------------------------\n\n");
					switch (submenuModificar()) {
					case 1:
						printf(
								"Ha ingresado para modificar el modelo de la notebook\n");
						printf(
								"Cual es el nuevo modelo que desea ingresar?: \n");
						fflush(stdin);
						gets(lista[indice].modelo);
						strlwr(lista[indice].modelo);
						lista[indice].modelo[0] = toupper(
								lista[indice].modelo[0]);
						while (lista[indice].modelo[i] != '\0') {
										if (lista[indice].modelo[i] == ' ') {
											lista[indice].modelo[i + 1] = toupper(
													lista[indice].modelo[i + 1]);
										}

										i++;
									}
						if(strlen(lista[indice].modelo) > 20){
										printf("El nombre ingresado es demasiado largo. Reingrese nombre del modelo: \n");
										fflush(stdin);
										gets(lista[indice].modelo);
										strlwr(lista[indice].modelo);
										lista[indice].modelo[0] = toupper(lista[indice].modelo[0]);
										while (lista[indice].modelo[i] != '\0') {
											if (lista[indice].modelo[i] == ' ') {
												lista[indice].modelo[i + 1] = toupper(
														lista[indice].modelo[i + 1]);
											}

											i++;
										}


									}

						break;
					case 2:

						printf(
								"Ha ingresado para modificar la marca de la notebook\n");
						printf(
								"Cual es la nueva marca que desea ingresar?(Compaq - Asus - Acer - HP): \n");
						fflush(stdin);
						mostrarMarca(marca, tamM);
									if (utn_getNumero(&lista[indice].idMarca,
											"Ingrese el numero de ID de la marca: \n",
											"Su numero no pudo ser validado\n Ingrese nuevamente un numero de ID de la marca (1000-1003)\n",
											1000, 1003) == 1) {
										printf("Su numero fue valido correctamente!\n");
									}






						break;
					case 3:
						printf(
														"Ha ingresado para modificar el tipo de la notebook\n");
												printf(
														"Cual es el nuevo tipo que desea ingresar?(Gamer - Disenio - Ultrabook - Normalita): \n");
												fflush(stdin);
												mostrarTipo(tipo, tamT);
															if (utn_getNumero(&lista[indice].idTipo,
																	"Ingrese el numero de ID del tipo: \n",
																	"Su numero no pudo ser validado\n Ingrese nuevamente un numero de ID del tipo (5000-5003)\n",
																	5000, 5003) == 1) {
																printf("Su numero fue valido correctamente!\n");
															}

						break;
					case 4:
						printf(
																				"Ha ingresado para modificar el precio de la notebook\n");

																					if (utn_getNumero(&lista[indice].precio,
																							"Ingrese el nuevo precio: \n",
																							"Su numero no pudo ser validado\n Ingrese nuevamente un precio valido (1-99999)\n",
																							1, 99999) == 1) {
																						printf("Su numero fue valido correctamente!\n");
																					}

						break;
					case 5:
						printf("Ha salido de la modificacion de los datos\n");
						seguir = 'n';
						break;
					default:
						printf("La opcion ingresada no es valida\n");

					}

					system("pause");
				} while (seguir == 's');

			} else {
				printf(
						"Se ha cancelado la modificacion de los datos del jugador\n");
			}

		}
	}

	return todoOk;
}

int submenuModificar() {
	int opcion;

	printf("     *** Que datos desea modificar?  ***\n\n");
	printf("1- Modelo\n");
	printf("2- Marca\n");
	printf("3- Tipo\n");
	printf("4- Precio\n");
	printf("5- Salir\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;

}




int submenuInformes(){


	int opcion;
		printf("\n Que informe desea realizar?\n\n");
		printf("1- Mostrar Notebook por ID\n");
		printf("2- Mostrar Notebooks segun la marca seleccionada\n");
		printf("3- Informar la/s notebook/s mas barata/s.\n");
		printf("4- Lista de Notebooks separados por marca\n");
		printf("5- Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa  marca\n");
		printf("6- Mostrar la o las marcas mas elegidas por los clientes\n");
		printf("7- Trabajos realizados a una Notebook por ID\n");
		printf("11- Salir\n");

		if (utn_getNumero(&opcion, "Ingrese el numero de informe que desea aplicar: \n",
				"Su numero no pudo ser validado\n Ingrese nuevamente un numero de informe valido (1-7)\n",
				1, 7) == 1) {
			printf("Su numero fue valido correctamente!\n");
		}
		return opcion;
	}



int realizarInformes(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC) {

	int todoOk = 0;
	char seguirInformes = 's';
	if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0) {
		do {
			switch (submenuInformes()) {
			case 1:
				mostrarNotebookPorId(lista, tam, marca,
						tamM, tipo, tamT, cliente, tamC);

				break;
			case 2:
				mostrarNotebookSegunMarca(lista, tam, marca,
						tamM, tipo, tamT, cliente, tamC);
				break;
			case 3:
				mostrarNotebookMasBarata(lista, tam, marca,
						tamM, tipo, tamT, cliente, tamC);
				break;
			case 4:
				mostrarNotebookListaMarca(lista, tam, marca,
						tamM, tipo, tamT, cliente, tamC);
				break;
			case 5:
				mostrarNotebooksSegunTipoMarca(lista, tam, marca,
						tamM, tipo, tamT, cliente, tamC);
				break;

			case 6:
				mostrarMarcaMasElegida(lista, tam, marca,
						tamM, tipo, tamT, cliente, tamC);
				break;

				break;
			case 11:
				printf("Ha seleccionado salir\n");
				confirmarSalida(&seguirInformes);
				if (seguirInformes == 'n') {
					printf("Ha salido del submenu con exito!\n");

				}
				break;
			default:
				printf("Opcion invalida!\n");

			}
			system("pause");

		} while (seguirInformes == 's');

		todoOk = 1;
	}

	return todoOk;
}

int mostrarNotebookPorId(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC) {
	int todoOk = 0;

	int id;
	int indice;
	if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0) {
	do {
					if (utn_getNumero(&id, "Ingrese el numero de ID de la Notebook: \n",
										"Su numero no pudo ser validado\n Ingrese nuevamente un numero de ID de Notebook existente\n",
										0, 10000000) == 1) {
									printf("Su numero fue valido correctamente!\n");

								}
					indice = buscarNotebookId(lista, tam, id);
					if (indice == -1) {

									printf("El id ingresado no pertenece al sistema.\n");
								}
				}while (indice == -1);


		for (int i = 0; i < tam; i++) {

			if (!(lista[i].isEmpty)
					&& (id == lista[i].id)) {
				printf("                                                  *** Lista de Notebooks ***        \n");
								printf(
										"--------------------------------------------------------------------------------------------------------------\n");
								printf(
										"|  ID  |  Modelo  | ID Marca | ID Tipo  |  Precio  |     Marca        |   Tipo       |  Nombre del cliente  | \n");
								printf(
										"--------------------------------------------------------------------------------------------------------------\n");
				mostrarNotebook(lista[i], tam, marca, tamM, tipo, tamT, cliente, tamC);

			}

		}

		todoOk = 1;
	}

	return todoOk;

}

int mostrarNotebookSegunMarca(eNotebook lista[], int tam,  eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC){
	int idMarca;
	int todoOk = 0;
	if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0){



	mostrarMarca(marca, tamM);
				if (utn_getNumero(&idMarca,
						"Ingrese el numero de ID de la marca: \n",
						"Su numero no pudo ser validado\n Ingrese nuevamente un numero de ID de la marca (1000-1003)\n",
						1000, 1003) == 1) {
					printf("Su numero fue valido correctamente!\n");
				}


			for(int i=0; i < tam; i++){

				if(idMarca == lista[i].idMarca && !lista[i].isEmpty){

					mostrarNotebook(lista[i], tam, marca, tamM, tipo, tamT, cliente, tamC);

				}

			}

				todoOk= 1;
	}
	return todoOk;
}


int mostrarNotebookMasBarata(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC){


	    int todoOk = 0;
		int flagPrecio = 1;
		int minPrecio;
		//char nombreJug[20];
		//char confederacion[20];
		if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0) {
			for (int i = 0; i < tam; i++) {

				if (!lista[i].isEmpty) {
					if (flagPrecio
							|| lista[i].precio < minPrecio) {

						minPrecio = lista[i].precio;
						flagPrecio = 0;
//						strcpy(nombreJug, lista[i].nombre);

					}

				}

			}
			//printf("%d\n", minPrecio);

			//printf("%s    %s\n", nombreJug, confederacion);
			printf("Las Notebooks mas baratas son las siguientes:\n\n");
			for (int i = 0; i < tam; i++) {
				if (!lista[i].isEmpty
						&& lista[i].precio == minPrecio) {

					mostrarNotebook(lista[i], tam, marca, tamM, tipo, tamT, cliente, tamC);
//					cargarRegionConfederacion(listaConfederacion, tam,
//							lista[i].idConfederacion, confederacion);

//					if (!strcmp(nombreJug, lista[i].nombre) == 0) {
//						strcpy(nombreJug, lista[i].nombre);
//						printf("%d\n", maxAniosContrato);
//						printf("%s     %s\n", nombreJug, confederacion);
					}

				}



			todoOk = 1;
		}

		return todoOk;
}


int mostrarNotebookMarca(eNotebook lista[], int tam,  eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC, int idMarca){

	int todoOk = 0;
		//char confederacion[20];
		int flag = 1;
		if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0){

			for (int i = 0; i < tam; i++) {

				if (!(lista[i].isEmpty)
						&& (idMarca == lista[i].idMarca)) {
					mostrarNotebook(lista[i], tam, marca, tamM, tipo, tamT, cliente, tamC);
					flag = 0;
				}

			}
			if (flag) {

				printf("No hay notebooks para mostrar de esta marca\n"
						);
			}
			todoOk = 1;
		}

		return todoOk;

}

int mostrarNotebookListaMarca (eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC){
	int todoOk = 0;
	if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0){
		limpiarPantalla();
		printf("Notebooks de cada marca\n");

		for (int i = 0; i < tamM; i++) {

					printf("\n\nMarca: %s\n", marca[i].descripcion);

					printf(
											"|  ID  |  Nombre  de Modelo    |   ID Marca  |  ID Modelo        |  Precio |       Marca              |   Modelo                      |\n");
									printf(
											"----------------------------------------------------------------------------------------------------------------------------------------\n");
									mostrarNotebookMarca(lista, tam, marca, tamM, tipo, tamT,cliente, tamC, marca[i].id);
				}
		todoOk=1;
	}

	return todoOk;
}

int mostrarNotebooksSegunTipoMarca(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC){
		int idMarca;
		int idTipo;
		int todoOk = 0;
		int contador = 0;
		char marcaDesc[20];
		char tipoDesc[20];

		if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0) {



		mostrarMarca(marca, tamM);
					if (utn_getNumero(&idMarca,
							"Ingrese el numero de ID de la marca: \n",
							"Su numero no pudo ser validado\n Ingrese nuevamente un numero de ID de la marca (1000-1003)\n",
							1000, 1003) == 1) {
						printf("Su numero fue valido correctamente!\n");
					}

				mostrarTipo(tipo, tamT);
					if(utn_getNumero(&idTipo, "Ingrese el numero de ID del tipo: \n",
											 "Su numero no pudo ser validado\n Ingrese nuevamente un ID del tipo valido (5000-5003)\n", 5000, 5003) == 1){
											 printf("Su numero fue valido correctamente!\n");
											 }
					cargarMarca(marca, tamM, idMarca, marcaDesc);
					cargarTipo(tipo, tamT, idTipo, tipoDesc);
					printf(
											"|  ID  |  Nombre  de Modelo    |   ID Marca  |  ID Modelo        |  Precio |       Marca              |   Modelo                      |\n");
									printf(
											"----------------------------------------------------------------------------------------------------------------------------------------\n");
				for(int i=0; i < tam; i++){

					if(idMarca == lista[i].idMarca && idTipo == lista[i].idTipo && !lista[i].isEmpty){
						contador++;
						mostrarNotebook(lista[i], tam, marca, tamM, tipo, tamT, cliente, tamC);

					}

				}
				printf("Hay %d de Notebooks de la marca %s y tipo %s\n", contador, marcaDesc, tipoDesc);
					todoOk= 1;
		}
		return todoOk;


}



int mostrarMarcaMasElegida(eNotebook lista[], int tam,eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC){
	int todoOk = 0;
	int cantMarca[] = {0,0,0,0};
	int masMarca;




	if (lista != NULL && tam > 0 && marca != NULL && tamM > 0 && tipo != NULL && tamT > 0 && cliente != NULL && tamC > 0){

		for(int i = 0; i < tamM; i++){

			for(int j = 0; j < tam; j++){

				if (!lista[j].isEmpty
										&& lista[j].idMarca
												== marca[i].id) {
									cantMarca[i]++;
				}


			}



		}

		for (int i = 0; i < tamM; i++) {

					if (i == 0 || cantMarca[i] > masMarca) {

						masMarca = cantMarca[i];


					}
		}



		for (int i = 0; i < tamM; i++) {

					if (cantMarca[i] == masMarca) {

						printf("\nLa marca mas elegida es %s con %d notebooks\n\n",
								marca[i].descripcion, masMarca);
						printf("\n");

					}

				}
	todoOk = 1;
	}


	return todoOk;
}


