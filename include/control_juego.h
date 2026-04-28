/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#ifndef CONTROL_JUEGO_H
#define CONTROL_JUEGO_H

#include "menu.h"
#include "combate.h"
#include "control_juego.h"
#include "entidades.h"
#include "historial.h"
#include "ia.h"
#include "utilidades.h"
#include "estructuras.h"

#define IA_ON true
#define IA_OFF false
#define TURNO_IA 0
#define TURNO_JUGADOR 1

/**
 * La funcion "control_juego" administra el flujo principal del combate entre el jugador y la IA,
 * alternando los turnos, procesando las acciones elegidas y registrando el desarrollo en un historial
 * 
 * @param jugador Puntero a la entidad del jugador
 * @param ia Puntero a la entidad de la inteligencia artificial
 * 
 * @pre Ambas entidades deben estar correctamente inicializadas con valores validos
 * 
 * @returns No retorna ningun valor
 * 
 * @post Controla los turnos de combate hasta que una de las entidades quede con vida igual o menor a cero.
 * Registra las acciones en el historial, muestra la informacion de combate y libera la memoria del historial al finalizar
 */
void control_juego(entidad_t *jugador, entidad_t *ia);

/**
 * La funcion "comprobar_estado" determina si una entidad continua viva o ha sido derrotada,
 * segun el valor actual de su atributo de vida
 * 
 * @param personaje Puntero a la entidad cuyo estado se desea comprobar
 * 
 * @pre El puntero debe estar correctamente inicializado
 * 
 * @returns Retorna "ENTIDAD_MUERTA" si la vida es menor o igual a cero,
 * o "ENTIDAD_VIVA" si la entidad aun posee puntos de vida
 * 
 * @post No modifica los atributos del personaje, solo evalua su estado actual
 */
int comprobar_estado(entidad_t *personaje);

#endif