/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#ifndef IA_H
#define IA_H

#include "utilidades.h"
#include "estructuras.h"

enum AccionesIA
{
    IA_ATAQUE = 1,
    IA_DEFENSA = 2,
    IA_CURACION = 3,
    IA_SKIP = 4
};

/**
 * La funcion "iniciar_personaje_ia" configura e inicializa una entidad
 * controlada por el modo inteligente asignandole un nombre
 * y estadisticas base de forma automatica
 * 
 * @param ia Puntero a la entidad de la inteligencia artificial a inicializar
 * 
 * @pre El puntero 'ia' debe apuntar a una estructura de tipo entidad_t valida
 * 
 * @returns Retorna "EXIT_SUCCESS" si la inicializacion fue exitosa
 * o "EXIT_FAILURE" si ocurrio un error
 * 
 * @post Asigna nombre a la IA utilizando un archivo externo
 * Si no se puede leer el archivo "nombres_ia.txt" se asigna un nombre por defecto
 * 
 * @note Tambien llama a la funcion "asignar_puntos" para definir las estadisticas de la IA
 */
int iniciar_personaje_ia(entidad_t *ia);

/**
 * La funcion "logica_ia" es la aplicacion del modo inteligente pedido, con una "ia" que
 * segun su estado actual y el del jugador, evalua como jugar, aplicando probabilidades 
 * y condiciones basadas en vida y energia
 * 
 * @param jugador Puntero a la entidad que representa al jugador
 * @param ia Puntero a la entidad controlada por la inteligencia artificial
 * 
 * @pre Ambos punteros deben estar correctamente inicializados
 * 
 * @returns Retorna un codigo entero que indica la accion tomada por la IA
 *  - IA_ATAQUE si decide atacar al jugador
 *  - IA_DEFENSA si activa su defensa
 *  - IA_CURACION si se cura
 *  - IA_SKIP si decide saltear su turno
 * 
 * @post Puede modificar la energia y vida de las entidades dependiendo de la accion
 * 
 * @note Internamente utiliza las funciones "atacar", "defender", "curar" y "skipear_turno"
 * asi como la funcion "ia_randomizer" que ayuda con la aleatoriedad
 */
int logica_ia(entidad_t *jugador, entidad_t *ia);

/**
 * La funcion "obtener_nombre_random" selecciona un nombre aleatorio
 * desde un archivo de texto y lo copia en el destino indicado
 * Es utilizada para, de una lista de 10 nombres, seleccionar uno de
 * manera aleatoria y hacer que ese nombre sea el de la IA
 * 
 * @param destino Arreglo de caracteres donde se almacenara el nombre elegido
 * @param capacidad_destino Tamano maximo del arreglo destino
 * @param ruta_archivo Ruta del archivo de texto que contiene la lista de nombres
 * 
 * @pre El archivo de nombres debe existir y contener al menos un nombre valido
 * 
 * @returns Retorna "EXIT_SUCCESS" si se pudo asignar un nombre correctamente
 * o "EXIT_FAILURE" si no fue posible abrir el archivo o no habia nombres disponibles
 * 
 * @post Modifica el contenido del arreglo destino escribiendo el nombre seleccionado
 */
int obtener_nombre_random(char *destino, size_t capacidad_destino, const char *ruta_archivo);

#endif