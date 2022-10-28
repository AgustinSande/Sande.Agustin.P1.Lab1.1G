/*
 * eNotebook.h
 *
 *  Created on: 21 oct 2022
 *      Author: Agustín
 */

#ifndef ENOTEBOOK_H_
#define ENOTEBOOK_H_

#include "biblioteca.h"
#include "dataWarehouse.h"
#include "eTrabajo.h"
#include "eTipo.h"
#include "eServicio.h"
#include "eMarca.h"
#include "eFecha.h"
#include "eCliente.h"
//#include "eMarca.h"
//
//#include "eTipo.h"
//#include "eServicio.h"


typedef struct{
	int id;
	char modelo[20];
	int idMarca;
	int idTipo;
	int precio;
	int isEmpty;
	int idCliente;

}eNotebook;
/// @fn int hardcodearNotebook(eNotebook[], int, int, int*)
/// @brief
///
/// @param lista array de estructuras  eNotebook
/// @param tam tamaño del array lista
/// @param cant cantidad de notebooks que se quieren hardcodear
/// @param pId puntero al ID de la notebook actual
/// @return
int hardcodearNotebook(eNotebook lista[], int tam, int cant, int* pId);

int menu();
/// @fn int inicializarNotebook(eNotebook[], int)
/// @brief Pone todos los isEmpty de lista en 1
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @return
int inicializarNotebook(eNotebook lista[], int tam);


/// @fn int buscarLibre(eNotebook[], int)
/// @brief busca el indice de un campo isEmpty == 0 dentro del array lista
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @return retorna el indice de una estructura vacia o -1 si no hay estructuras vacias
int buscarLibre(eNotebook lista[], int tam);

/// @fn int altaNotebook(eNotebook[], int, int*, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief Da de alta una notebook en la lista
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param pId puntero al ultimo id perteneciente a la lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estrcuturas eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo cargar una notebook, 0 si no pudo
int altaNotebook(eNotebook lista[], int tam, int *pId, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);

/// @fn int bajaNotebook(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief Da de baja una notebook en la lista
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estrcuturas eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo dar de baja una notebook, 0 si no pudo
int bajaNotebook(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);

/// @fn int buscarNotebookId(eNotebook[], int, int)
/// @brief busca una notebook en la lista a partir del id que le pasamos
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param id ID de la notebook que deseamos buscar
/// @return
int buscarNotebookId(eNotebook lista[], int tam, int id);

/// @fn int modificarNotebook(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief modifica una notebook ya existente de la lista
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estrcuturas eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo modificar la notebook, 0 si no pudo

int modificarNotebook(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);
/// @fn int submenuModificar()
/// @brief submenu para elegir que modificacion se quiere realizar
///
/// @return retorna opcion elegida por el usuario
int submenuModificar();

/// @fn void mostrarNotebook(eNotebook, int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief muestra una unica notebook en particular
///
/// @param p estructura que deseamos mostrar
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estrcuturas eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo mostrar la notebook, 0 si no pudo
void mostrarNotebook(eNotebook p, int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);

/// @fn int mostrarNotebooks(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief muestra todas las notebooks existentes en la lista
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estrcuturas eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo mostrar las notebooks, 0 si no pudo
int mostrarNotebooks(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);

/// @fn int altaTrabajo(eNotebook[], int, eTrabajo[], int, int*, eMarca[], int, eTipo[], int, eServicio[], int, eFecha[], int, eCliente[], int)
/// @brief
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param listaTrabajos array de estrcuturas eTrabajo
/// @param tamTrabajo tamaño del array listaTrabajos
/// @param pId puntero al id del trabajo actual
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param servicio  array de estrcuturas eServicio
/// @param tamS tamaño del array servicio
/// @param fecha array de estrcuturas eFecha
/// @param tamF tamaño del array fecha
/// @param cliente array de estructuras eCliente
/// @param tamC tamaño del array cliente
/// @return
int altaTrabajo(eNotebook lista[], int tam, eTrabajo listaTrabajos[],
		int tamTrabajo, int *pId, eMarca marca[], int tamM, eTipo tipo[],
		int tamT, eServicio servicio[], int tamS, eFecha fecha[], int tamF, eCliente cliente[], int tamC);


/// @fn int mostrarTrabajo(eTrabajo, eServicio[], int, int)
/// @brief muestra un solo trabajo cargado en la estructura eTrabajo
///
/// @param p estructura que deseamos mostrar
/// @param servicio array de estructuras eServicio
/// @param tamT tamaño del array servicio
/// @param i indice que queremos mostrar para la fecha
/// @return 1 si pudo mostrarlo, 0 si no pudo
int mostrarTrabajo(eTrabajo p, eServicio servicio[], int tamT, int i);
/// @fn int mostrarTrabajos(eTrabajo[], eServicio[], int, int)
/// @brief muestra todos los trabajos realizados
///
/// @param lista array de estructuras eTrabajo
/// @param servicio array de estructuras eServicio
/// @param tamT tamaño del array lista
/// @param tamS tamaño del array servicio
/// @return 1 si pudo mostrar los trabajos, 0 si no pudo
int mostrarTrabajos(eTrabajo lista[], eServicio servicio[], int tamT, int tamS);

/// @fn int inicializarTrabajo(eTrabajo[], int)
/// @brief pone todos los isEmpty de la en la lista de estructuras eTrabajo en 1
///
/// @param lista array de estructuras eTrabajo
/// @param servicio array de estructuras eServicio
/// @return 1 si pudo inicializar los trabajos, 0 si no pudo
int inicializarTrabajo(eTrabajo lista[], int tamT);

/// @fn int realizarInformes(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief funcion principal para realizar los informes
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estructuras eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo realizar los informes, 0 si no pudo
int realizarInformes(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);
/// @fn int mostrarNotebookPorId(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief muestra una notebook segun el id que le pasemos
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estructuras eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo mostrar la notebook por id, 0 si no pudo
int mostrarNotebookPorId(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);
/// @fn int mostrarNotebookSegunMarca(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief muestra lista de notebooks segun la marca que se elija
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estructuras eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo realizar los informes, 0 si no pudo
int mostrarNotebookSegunMarca(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);
/// @fn int mostrarNotebookMasBarata(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief muestra la notebook mas barata cargada en la lista
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estructuras eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo realizar los informes, 0 si no pudo
int mostrarNotebookMasBarata(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);
/// @fn int mostrarNotebookMarca(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int, int)
/// @brief muestra una notebook en particular a partir del id que le pasamos
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estructuras eCliente
/// @param tamC tamaño del array cliente
/// @param idMarca Id de la marca que le pasamos a la funcion que utilizara para mostrar la notebook
/// @return 1 si pudo realizar su tarea, 0 si no pudo
int mostrarNotebookMarca(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC,int  idMarca);

/// @fn int mostrarNotebookListaMarca(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief muestra una lista de las notebooks agrupadas segun su marca
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estructuras eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo realizar los informes, 0 si no pudo
int mostrarNotebookListaMarca(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);

/// @fn int mostrarNotebooksSegunTipoMarca(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief pide al usuario el id de una marca y de un tipo para mostrar las notebooks que pertenecen a ambos grupos
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estructuras eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo realizar los informes, 0 si no pudo
int mostrarNotebooksSegunTipoMarca(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);
/// @fn int mostrarMarcaMasElegida(eNotebook[], int, eMarca[], int, eTipo[], int, eCliente[], int)
/// @brief muestra cual es la o las marcas mas elegidas por los clientes
///
/// @param lista array de estrcuturas eNotebook
/// @param tam tamaño del array lista
/// @param marca array de estrcuturas eMarca
/// @param tamM tamaño del array marca
/// @param tipo array de estrcuturas eTipo
/// @param tamT tamaño del array tipo
/// @param cliente array de estructuras eCliente
/// @param tamC tamaño del array cliente
/// @return 1 si pudo realizar los informes, 0 si no pudo
int mostrarMarcaMasElegida(eNotebook lista[], int tam, eMarca marca[], int tamM, eTipo tipo[], int tamT, eCliente cliente[], int tamC);


#endif /* ENOTEBOOK_H_ */


