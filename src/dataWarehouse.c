/*
 * DataWarehouse.c
 *
 *  Created on: 17 oct 2022
 *      Author: Agustín
 */


/*
 * DataWarehouse.c
 *
 *  Created on: 13 oct 2022
 *      Author: Agustín
 */

#include "dataWarehouse.h"
#include "eNotebook.h"
#include <string.h>

char nombres[10][20] = {
	"Lionel Messi",
	"Paulo Dybala",
	"Emiliano Martinez",
	"Angel Di Maria",
	"Cristian Romero",
	"Nicolas Otamendi",
	"Leandro Paredes",
	"Lautaro Martinez",
	"Rodrigo De Paul",
	"German Pezzella"

};

char sexos[10] ={'m', 'm','f','m','f','f','m','f','m','m'};

int edades [10] = {20,30,32,54,33,50,60,26,53,67};

float alturas[10] = {1.65,1.70,1.81,1.65,1.80,1.92,1.73,1.66,1.84,1.91};

char conferederaciones[10][25] = {
	"CONMEBOL", "UEFA","AFC", "CAF", "CONCACAF","OFC", "UEFA", "UEFA", "CONMEBOL", "CONCACAF"


};

char posiciones[10][25] = {
		"Delantero", "Delantero", "Arquero","Delantero", "Defensor", "Defensor", "Mediocampista","Delanteor", "Mediocampista", "Defensor"


};

int aniosContrato[10] = {
		2,3,4,1,2,3,4,4,2,5



};
int numeroCamisetas[10] = {
		10,7,1,11, 2,23,5,9,8,14




};


float salarios[10] = {
		200000, 100000, 80000, 86000,130000,150000,500000,20000,210000,60000


};





char nombresConfLista[6][15] = {

	"CONMBEOL", "UEFA", "AFC", "CAF", "CONCACAF", "OFC"
};

char regionesConfLista[6][25] = {
		"SUDAMERICA", "EUROPA", "ASIA", "AFRICA", "NORTE Y CENTRO AMERICA", "OCEANIA"


};

int anioCreacionConfLista[6] =  {
	1916,1954,1954,1957,1961,1966


};

int idConfederaciones [10] = {

	100,101,102,103,105,02,104,102,105,500
};
char modelos [10][25] = {
		"A3000","A3002","A3003","A3004","A3005","A3006","A3007","A3008","A3009","A3010"


};

int idMarca [10] = {
		1000,1001,1002,1000,1002,1002,1001,1002,1001,1001



};

int idTipo [10] = {
		5000,5001,5002,5000,5003,5002,5001,5002,5001,5001



};

int precios [10] = {
	20000,10000,15500,16000,13000,20500,22000,23000,30000,10000


};

int idsCliente [10] = {
		1,2,3,4,2,2,1,3,2,3


};

int idsNotebook [10] = {

		1,2,3,4,2,1,2,1,5,2


};

int idsServicio[10] = {

	20001,20000,20002,20001,20003,20002,20000,20001,20001,20003,

};


int dias [10] = {

		1,2,3,4,5,6,7,8,9,10
};

int mes [10] = {

		1,2,3,4,1,2,1,2,6,7
};

int anios [10] = {

	1999,2002,2003,2005,2001,2005,2009,2006,2001,2002

};
int hardcodearNotebook(eNotebook lista[], int tam, int cant, int* pId){
	int contador = -1;
	if ( lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL){
		contador = 0;
		for(int i = 0; i < cant; i++){
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].modelo, modelos[i]);
			lista[i].idMarca = idMarca[i];
			lista[i].idTipo = idTipo[i];
			lista[i].isEmpty = 0;
			lista[i].precio = precios[i];
			lista[i].idCliente = idsCliente[i];
			contador++;

		}
	}

	return contador;
}

int hardcodearTrabajo(eTrabajo listaTrabajos[], int tam, int cant, int* pId){
	int contador = -1;
		if ( listaTrabajos != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL){
			contador = 0;
			for(int i = 0; i < cant; i++){
				listaTrabajos[i].id = *pId;
				(*pId)++;
				listaTrabajos[i].idNotebook = idsNotebook[i];
				listaTrabajos[i].idServicio = idsServicio[i];
				listaTrabajos[i].isEmpty = 0;
				listaTrabajos[i].fecha[i].dia = dias[i];
				listaTrabajos[i].fecha[i].mes = mes[i];
				listaTrabajos[i].fecha[i].anio = anios[i];
				contador++;

			}
		}

		return contador;


}
