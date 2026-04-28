/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#ifndef COMBATE_H
#define COMBATE_H

#include "menu.h"
#include "combate.h"
#include "control_juego.h"
#include "entidades.h"
#include "historial.h"
#include "ia.h"
#include "utilidades.h"
#include "estructuras.h"

#define VIDA_MAX 100
#define ENERGIA_BASE 100

/**
 * La funcion "atacar" permite que una entidad realice un ataque sobre otra,
 * calculando el daño final en base a sus estadisticas de ataque y resistencia,
 * y restando energia al atacante segun el costo del ataque
 * 
 * @param atacante Puntero a la entidad que realiza el ataque
 * @param enemigo Puntero a la entidad que recibe el ataque
 * 
 * @pre Ambos punteros deben estar correctamente inicializados
 * 
 * @returns Retorna "EXIT_SUCCESS" si el ataque se realizo correctamente,
 * o "EXIT_FAILURE" si el ataque fallo o alguna de las entidades no es valida
 * 
 * @post Modifica la vida del enemigo y la energia del atacante
 */
int atacar(entidad_t *atacante, entidad_t *enemigo);

/**
 * La funcion "defender" activa el estado de defensa para una entidad,
 * permitiendo reducir el daño recibido en el siguiente turno
 * 
 * @param personaje Puntero a la entidad que se defendera
 * 
 * @pre El puntero debe estar correctamente inicializado
 * 
 * @returns Retorna "EXIT_SUCCESS" si la accion fue realizada,
 * o "EXIT_FAILURE" si la accion fallo o no habia energia suficiente
 * 
 * @post Activa la bandera de defensa y reduce la energia del personaje
 */
int defender(entidad_t *personaje);

/**
 * La funcion "curar" restaura una cantidad fija de vida a la entidad,
 * siempre que posea la energia suficiente y no tenga la vida al maximo
 * 
 * @param personaje Puntero a la entidad que se desea curar
 * 
 * @pre El puntero debe estar correctamente inicializado y la vida menor a VIDA_MAX
 * 
 * @returns Retorna "EXIT_SUCCESS" si la curacion fue exitosa,
 * o "EXIT_FAILURE" si no habia energia suficiente o la accion fallo
 * 
 * @post Incrementa la vida del personaje sin superar el limite definido por VIDA_MAX
 */
int curar(entidad_t *personaje);

/**
 * La funcion "recuperar_energia" regenera parcialmente la energia de una entidad
 * al finalizar el turno, dependiendo de sus estadisticas
 * 
 * @param jugador Puntero a la entidad del jugador
 * @param ia Puntero a la entidad de la inteligencia artificial
 * @param es_turno_ia Indica si la entidad que recupera energia es la IA
 * 
 * @pre Ambas entidades deben estar correctamente inicializadas
 * 
 * @returns Retorna "EXIT_SUCCESS" si se recupero energia correctamente,
 * o "EXIT_FAILURE" si la energia ya estaba al maximo
 * 
 * @post Aumenta la energia de la entidad hasta el limite ENERGIA_BASE
 */
int recuperar_energia(entidad_t *jugador, entidad_t *ia, bool es_turno_ia);

/**
 * La funcion "descontar_energia" reduce la energia disponible de una entidad
 * segun el costo de la accion ejecutada
 * 
 * @param personaje Puntero a la entidad a la cual se le descontara energia
 * @param costo_energia Costo energetico de la accion realizada
 * 
 * @pre El puntero debe estar correctamente inicializado y el costo debe ser positivo
 * 
 * @returns Retorna "EXIT_SUCCESS" si la energia fue descontada correctamente,
 * o "EXIT_FAILURE" si la entidad no tiene energia suficiente
 * 
 * @post Modifica el valor del atributo energia de la entidad
 */

int descontar_energia(entidad_t *personaje, int costo_energia);

/**
 * La funcion "skipear_turno" permite a una entidad omitir su accion actual
 * a cambio de recuperar parte de su energia base
 * 
 * @param personaje Puntero a la entidad que desea saltar su turno
 * 
 * @pre El puntero debe estar correctamente inicializado
 * 
 * @returns Retorna "EXIT_SUCCESS" si la energia fue recuperada,
 * o "EXIT_FAILURE" si la energia ya estaba al maximo
 * 
 * @post Incrementa la energia del personaje sin superar ENERGIA_BASE
 */
int skipear_turno(entidad_t *personaje);

#endif