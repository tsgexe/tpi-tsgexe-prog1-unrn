/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#ifndef ENTIDADES_H
#define ENTIDADES_H

#include "estructuras.h"
#include "utilidades.h"

/**
 * La funcion "iniciar_personaje" solicita al usuario ingresar un nombre
 * para el personaje y lo almacena dentro de la estructura recibida
 * 
 * @param personaje Puntero a la estructura de tipo entidad_t donde se guardara el nombre
 * 
 * @pre El puntero "personaje" debe estar correctamente inicializado
 * 
 * @returns Retorna "EXIT_SUCCESS" si el nombre fue asignado correctamente
 * o "EXIT_FAILURE" si se produjo un error durante la lectura o validacion
 * 
 * @post Si el nombre es valido, se copia en el campo "nombre" del personaje
 * Si ocurre un error, el personaje no se modifica
 */
int iniciar_personaje(entidad_t *personaje);

/**
 * La funcion "asignar_puntos" distribuye de manera aleatoria un total de
 * 10 puntos entre los atributos ataque, resistencia y energia del personaje
 * 
 * @param personaje Puntero a la estructura de tipo entidad_t a la que se asignaran los puntos
 * 
 * @pre El puntero "personaje" debe estar correctamente inicializado
 * 
 * @returns Retorna "EXIT_SUCCESS" si la asignacion se realiza correctamente
 * o "EXIT_FAILURE" si el puntero es NULL
 * 
 * @post Modifica los valores de los campos del struct "stats" del personaje,
 * incrementando ataque, resistencia y energia de forma aleatoria
 */
int asignar_puntos(entidad_t *personaje);

/**
 * La funcion "mostrar_datos_entidad" imprime una tabla en consola mostrando
 * los valores actuales de vida y energia del jugador y la IA en formato comparativo
 * 
 * @param jugador Puntero a la entidad del jugador
 * @param ia Puntero a la entidad de la inteligencia artificial
 * 
 * @pre Ambos punteros deben estar correctamente inicializados
 * 
 * @returns No retorna ningun valor (tipo void)
 * 
 * @post No modifica ningun dato, solo muestra la informacion actual en consola
 */
void mostrar_datos_entidad(entidad_t *jugador, entidad_t *ia);

/**
 * La funcion "mostrar_puntos_stats" muestra en pantalla los puntos
 * asignados a cada atributo (ataque, resistencia, curacion y energia)
 * tanto del jugador como de la inteligencia artificial
 * 
 * @param jugador Puntero a la entidad del jugador
 * @param ia Puntero a la entidad de la inteligencia artificial
 * 
 * @pre Ambos punteros deben estar correctamente inicializados
 * 
 * @returns No retorna ningun valor (tipo void)
 * 
 * @post No modifica ningun valor, solo imprime los puntos de estadisticas actuales
 */
void mostrar_puntos_stats(entidad_t *jugador, entidad_t *ia);

#endif