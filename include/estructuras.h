/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define LARGO_NOMBRE 20

#include "utilidades.h"
#include <stdlib.h>

/**
 * La estructura "nodo_historial_t" representa un nodo individual
 * dentro de la lista enlazada que almacena el historial de turnos
 * Cada nodo guarda informacion sobre una accion realizada durante la batalla
 * 
 * @param turno Numero del turno correspondiente al registro
 * @param personaje Nombre del personaje que realizo la accion
 * @param accion Descripcion corta de la accion ejecutada
 * @param vida_jugador Valor actual de vida del jugador en el turno
 * @param energia_jugador Valor actual de energia del jugador en el turno
 * @param vida_ia Valor actual de vida de la inteligencia artificial en el turno
 * @param energia_ia Valor actual de energia de la inteligencia artificial en el turno
 * @param siguiente Puntero al siguiente nodo del historial
 * 
 * @note Se utiliza dentro de la estructura "historial_t" para construir una lista enlazada simple
 */
typedef struct nodo_historial
{
    int turno;
    char personaje[LARGO_NOMBRE];
    char accion[30];
    int vida_jugador;
    int energia_jugador;
    int vida_ia;
    int energia_ia;
    struct nodo_historial *siguiente;
} nodo_historial_t;

/**
 * La estructura "historial_t" administra una lista enlazada de registros de batalla
 * permitiendo almacenar, recorrer y liberar el historial de turnos
 * 
 * @param primero Puntero al primer nodo del historial
 * @param ultimo Puntero al ultimo nodo del historial
 * @param cantidad Cantidad total de registros almacenados
 * 
 * @note Es usada por funciones como "iniciar_historial" y "registro_historial"
 * para gestionar dinamicamente los registros de la partida
 */
typedef struct
{
    nodo_historial_t *primero;
    nodo_historial_t *ultimo;
    size_t cantidad;
} historial_t;

/**
 * El enumerador "EstadoEntidad" define los posibles estados de una entidad
 * durante la partida segun su nivel de vida
 * 
 * @value ENTIDAD_MUERTA Indica que la entidad tiene 0 o menos puntos de vida
 * @value ENTIDAD_VIVA Indica que la entidad sigue activa en combate
 * 
 * @note Utilizado en la funcion "comprobar_estado" para determinar el estado actual
 */
enum EstadoEntidad
{
    ENTIDAD_MUERTA = 0,
    ENTIDAD_VIVA = 1
};

/**
 * La estructura "atributos_t" contiene las estadisticas basicas
 * de una entidad utilizadas en combate
 * 
 * @param energia Nivel base de regeneracion y reserva energetica
 * @param ataque Nivel de fuerza ofensiva que incrementa el dano infligido
 * @param resistencia Nivel de defensa que reduce el dano recibido
 * @param curacion Nivel de efectividad al recuperar vida
 * 
 * @note Forma parte de la estructura "entidad_t" como miembro "stats"
 */
typedef struct entidad
{
    int energia;
    int ataque;
    int resistencia;
    int curacion;
} atributos_t;

/**
 * La estructura "entidad_t" representa a un personaje o enemigo en combate
 * y agrupa tanto su estado actual como sus estadisticas
 * 
 * @param nombre Nombre identificador de la entidad
 * @param vida Puntos de vida actuales
 * @param energia Puntos de energia disponibles
 * @param defensa_activa Indica si la defensa esta activada en el turno
 * @param ultimo_daño Guarda el ultimo valor de dano recibido
 * @param stats Estructura "atributos_t" con las estadisticas de combate
 * 
 * @note Utilizada tanto para el jugador como para la inteligencia artificial
 */
typedef struct
{
    char nombre[LARGO_NOMBRE];
    int vida;
    int energia;
    bool defensa_activa;
    int ultimo_daño;
    atributos_t stats;
} entidad_t;

/**
 * El enumerador "costos" define los valores energeticos
 * requeridos para ejecutar cada accion disponible en combate
 * 
 * @value COSTO_ATAQUE Costo energetico para ejecutar un ataque
 * @value COSTO_DEFENDER Costo energetico para activar la defensa
 * @value COSTO_CURAR Costo energetico para realizar una curacion
 * 
 * @note Estos valores son constantes y se utilizan en funciones
 * como "atacar", "defender" y "curar"
 */
enum costos
{
    COSTO_ATAQUE = 25,
    COSTO_DEFENDER = 15,
    COSTO_CURAR = 40
};

#endif