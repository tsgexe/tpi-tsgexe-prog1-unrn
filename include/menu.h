/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#ifndef MENU_H
#define MENU_H

#include "menu.h"
#include "combate.h"
#include "control_juego.h"
#include "entidades.h"
#include "historial.h"
#include "ia.h"
#include "utilidades.h"

/**
 * La funcion "mostrar_titulo_principal" imprime en pantalla
 * el titulo del juego (que usa caracteres ascii especiales)
 * con puros fines decorativos
 * Si al ejecutar se ven letras raras, utilizar antes de
 * ejecutar el comando "chcp 65001" en la consola
 * 
 * @pre No requiere parametros ni inicializacion previa
 * 
 * @post No modifica ningun dato del programa solo realiza salida por consola
 */
void mostrar_titulo_principal();

/**
 * La funcion "menu_jugador" muestra las opciones de accion disponibles
 * para el jugador durante su turno y solicita una entrada valida por consola
 * 
 * @pre Debe existir un juego activo con las constantes de costo definidas
 * 
 * @returns Un valor entero correspondiente a la eleccion del jugador
 *  - 1 para ATACAR
 *  - 2 para DEFENDER
 *  - 3 para CURAR
 *  - 4 para SALTAR TURNO
 * 
 * @post No modifica ninguna estructura del juego solo devuelve la opcion elegida
 */
int menu_jugador();

/**
 * La funcion "pausar_consola" pausa la ejecucion para que el programa
 * no se cierre, pero permite cerrarlo al presionar "enter"
 * Limpia el buffer para evitar problemas con la ejecucion normal
 * 
 * @pre Debe llamarse al final del programa o tras un mensaje informativo
 * 
 * @post No altera datos del programa solo pausa temporalmente la ejecucion
 */
void pausar_consola();

#endif