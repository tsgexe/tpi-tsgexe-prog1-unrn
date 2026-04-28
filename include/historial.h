/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#ifndef HISTORIAL_H
#define HISTORIAL_H

#include "menu.h"
#include "combate.h"
#include "control_juego.h"
#include "entidades.h"
#include "historial.h"
#include "ia.h"
#include "utilidades.h"
#include "estructuras.h"

/**
 * La funcion "iniciar_historial" inicializa la estructura del historial
 * de turnos dejando sus punteros y contadores en valores seguros
 * 
 * @param historial Puntero a la estructura historial_t que se desea iniciar
 * 
 * @pre El puntero "historial" debe apuntar a una estructura valida
 * 
 * @returns No retorna ningun valor (tipo void)
 * 
 * @post Deja el historial vacio, con "primero" y "ultimo" en NULL y "cantidad" en cero
 */
void iniciar_historial(historial_t *historial);

/**
 * La funcion "registro_historial" crea un nuevo nodo de historial
 * con la informacion del turno actual y lo agrega a la lista enlazada
 * 
 * @param historial Puntero al historial donde se agregara el registro
 * @param turno Numero de turno actual
 * @param personaje Nombre del personaje que realizo la accion
 * @param accion Cadena con la descripcion de la accion realizada
 * @param vida_jugador Valor actual de vida del jugador
 * @param energia_jugador Valor actual de energia del jugador
 * @param vida_ia Valor actual de vida de la inteligencia artificial
 * @param energia_ia Valor actual de energia de la inteligencia artificial
 * 
 * @pre El puntero "historial" debe estar inicializado y listo para usarse
 * 
 * @returns Retorna "EXIT_SUCCESS" si el registro fue agregado correctamente
 * o "EXIT_FAILURE" si no se pudo reservar memoria
 * 
 * @post Si la reserva de memoria fue exitosa, se agrega un nuevo nodo al final del historial
 * Si falla, el historial no se modifica
 */
int registro_historial(historial_t *historial, int turno, const char *personaje, const char *accion,
                       int vida_jugador, int energia_jugador, int vida_ia, int energia_ia);

/**
 * La funcion "guardar_historial" guarda todos los registros almacenados
 * en el historial dentro de un archivo de texto, sobreescribiendo su contenido anterior
 * 
 * @param historial Puntero a la estructura historial_t que contiene los registros
 * @param ruta_historial Ruta al archivo de texto donde se guardaran los datos
 * 
 * @pre El puntero "historial" debe estar correctamente inicializado y contener registros validos
 * 
 * @returns Retorna "EXIT_SUCCESS" si el archivo se guardo correctamente
 * o "EXIT_FAILURE" si ocurrio un error al acceder al archivo
 * 
 * @post Genera o reemplaza un archivo con el resumen completo de la batalla
 * incluyendo turnos, acciones, vida y energia de ambas entidades
 */
int guardar_historial(const historial_t *historial, const char *ruta_historial);

/**
 * La funcion "liberar_memoria_historial" libera toda la memoria
 * reservada dinamicamente para los nodos del historial
 * 
 * @param historial Puntero al historial cuya memoria se desea liberar
 * 
 * @pre El puntero "historial" debe apuntar a una estructura valida
 * 
 * @returns No retorna ningun valor (tipo void)
 * 
 * @post Libera todos los nodos del historial y deja los punteros
 * "primero" y "ultimo" en NULL, ademas de reiniciar el contador "cantidad" a cero
 */
void liberar_memoria_historial(historial_t *historial);

#endif