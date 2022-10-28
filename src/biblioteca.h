/*
 * biblioteca.h
 *
 *  Created on: 17 oct 2022
 *      Author: Agustín
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
/// @fn int confirmarSalida(char*)
/// @brief pide un caracter para confirmar la salida de un submenu
///
/// @param pControl puntero a la variable del caracter que va a modificar para salir de submenu
/// @return
int confirmarSalida(char *pControl);



void limpiarPantalla();

/// @fn int utn_getNumero(int*, char*, char*, int, int)
/// @brief Pide un numero dentro que debe estar incluido dentro del rango
///
/// @param pResultado puntero a la variable del numero que vamos a conseguir
/// @param mensaje mensaje de numero validado
/// @param mensajeError mensaje de numero no validado
/// @param minimo parametro minimo del rango
/// @param maximo parametro maximo del rango
/// @return
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo);

/// @fn int validarCaracter(char, char, char)
/// @brief Valida un caracter entre dos opciones
///
/// @param caracterIngresado
/// @param opcionA uno de los caracteres validos
/// @param opcionB el otro de los caracteres validos
/// @return
int validarCaracter(char caracterIngresado,char opcionA, char opcionB);

/// @fn int getFloat(float*, char*, char*, float, float)
/// @brief
///
/// @param pResultado puntero a la variable del numero flotante que vamos a conseguir
/// @param mensaje mensaje de numero flotante validado
/// @param mensajeError mensaje de numero no validado
/// @param minimo parametro minimo del rango
/// @param maximo parametro maximo del rango
/// @return
int getFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo);

//static
/// @fn int getInt(int*)
/// @brief Consigue un numero entero pidiendoselo al usuario por consola
///
/// @param pResultado puntero a la variable de numero que vamos a conseguir
/// @return
int getInt(int *pResultado);

/// @fn int getAnyFloat(float*)
/// @brief  Consigue un numero flotante pidiendoselo al usuario por consola
///
/// @param pResultado puntero a la variable de numero flotante que vamos a conseguir
/// @return
int getAnyFloat(float *pResultado);

#endif /* BIBLIOTECA_H_ */
