/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/**
 * La funcion "fallo_accion" determina de manera aleatoria
 * si una accion realizada por una entidad falla o tiene exito
 * 
 * @pre Debe haberse inicializado el generador de numeros aleatorios con srand
 * 
 * @returns Un valor booleano que indica el resultado del intento
 *  - false si la accion tiene exito (probabilidad del 70%)
 *  - true si la accion falla (probabilidad del 30%)
 * 
 * @post No modifica ninguna estructura ni variable global solo devuelve el resultado
 */
bool fallo_accion();

/**
 * La funcion "ia_randomizer" genera un numero entero aleatorio
 * dentro del rango 1 a 100 utilizado para la toma de decisiones de la IA
 * 
 * @pre Debe haberse inicializado el generador de numeros aleatorios con srand
 * 
 * @returns Un entero entre 1 y 100 representando una probabilidad
 * 
 * @post No modifica ningun valor del programa solo devuelve un numero aleatorio
 */
int ia_randomizer();

/**
 * La funcion "limpiar_buffer" limpia la entrada estandar, eliminando caracteres
 * residuales hasta encontrar un salto de linea o EOF
 * 
 * @pre Debe utilizarse luego de una lectura de entrada invalida con scanf o fgets
 * 
 * @post Asegura que el buffer de entrada quede vacio para futuras lecturas
 */
void limpiar_buffer();

#endif