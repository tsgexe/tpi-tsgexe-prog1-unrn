/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#include "menu.h"
#include "combate.h"
#include "control_juego.h"
#include "entidades.h"
#include "historial.h"
#include "ia.h"
#include "utilidades.h"

int iniciar_personaje(entidad_t *personaje)
{
    int codigo_retorno = EXIT_SUCCESS;
    char nombre_ingresado[LARGO_NOMBRE];

    if (personaje == NULL)
    {
        fprintf(stderr, "ERROR: El puntero del personaje es NULL y no se puede iniciar\n");

        codigo_retorno = EXIT_FAILURE;
    }
    else
    {
        printf("Ingrese el nombre de su personaje: ");

        if (fgets(nombre_ingresado, LARGO_NOMBRE, stdin) == NULL)
        {
            fprintf(stderr, "ERROR: El nombre ingresado es invalido\n");

            codigo_retorno = EXIT_FAILURE;
        }
        else
        {
            if (strchr(nombre_ingresado, '\n') == NULL)
            {
                limpiar_buffer();
            }
            else
            {
                nombre_ingresado[strcspn(nombre_ingresado, "\n")] = '\0';
            }

            if (strlen(nombre_ingresado) == 0)
            {
                fprintf(stderr, "ERROR: Debe ingresar al menos un caracter para el nombre\n");
                codigo_retorno = EXIT_FAILURE;
            }
            else if (strlen(nombre_ingresado) >= LARGO_NOMBRE)
            {
                fprintf(stderr, "ERROR: El nombre ingresado debe ser menor a %d caracteres\n", LARGO_NOMBRE);
                codigo_retorno = EXIT_FAILURE;
            }
            else
            {
                strcpy(personaje->nombre, nombre_ingresado);
                printf("Tu nombre es %s! Bienvenido!\n", personaje->nombre);
                codigo_retorno = EXIT_SUCCESS;
            }
        }
    }

    return codigo_retorno;
}

int asignar_puntos(entidad_t *personaje)
{
    int puntos_totales = 10;
    int asignacion_random = 0;
    int codigo_retorno = EXIT_SUCCESS;

    if (personaje == NULL)
    {
        fprintf(stderr, "ERROR: Puntero a personaje es NULL\n");
        codigo_retorno = EXIT_FAILURE;
    }
    else
    {

        personaje->stats.ataque = 1;
        personaje->stats.resistencia = 1;
        personaje->stats.curacion = 1;
        personaje->stats.energia = 1;

        while (puntos_totales > 0)
        {
            asignacion_random = rand() % 3;

            if (asignacion_random == 0)
            {
                personaje->stats.ataque++;
                puntos_totales--;
            }
            else if (asignacion_random == 1)
            {
                personaje->stats.resistencia++;
                puntos_totales--;
            }
            else if (asignacion_random == 2)
            {
                personaje->stats.energia++;
                puntos_totales--;
            }
        }

        printf("ESTADISTICAS ALEATORIAS FUERON APLICADAS A %s!\n", personaje->nombre);
    }

    return codigo_retorno;
}

void mostrar_datos_entidad(entidad_t *jugador, entidad_t *ia)
{
    printf("===============================================\n");
    
    // Encabezados con formato centrado/alineado
    // Usa '%-20s' para alinear el nombre a la izquierda en un espacio de 20
    printf("| %-20s | %-20s |\n", jugador->nombre, ia->nombre);
    printf("===============================================\n");
    
    // Fila de VIDA
    // Usa '%-20d' para alinear el valor a la izquierda en un espacio de 20
    printf("| VIDA: %-14d | VIDA: %-14d |\n", jugador->vida, ia->vida);
    
    // Fila de ENERGIA
    printf("| ENERGIA: %-11d | ENERGIA: %-11d |\n", jugador->energia, ia->energia);

    printf("===============================================\n");
}

void mostrar_puntos_stats(entidad_t *jugador, entidad_t *ia)
{
    printf("- STATS DE %s -\n", jugador->nombre);
    printf("- ATAQUE:\t %d\n", jugador->stats.ataque);
    printf("- RESISTENCIA:\t %d\n", jugador->stats.resistencia);
    printf("- CURACION:\t %d\n", jugador->stats.curacion);
    printf("- ENERGIA:\t %d\n", jugador->stats.energia);
    
    printf("STATS DE %s:\n", ia->nombre);
    printf("- ATAQUE:\t %d\n", ia->stats.ataque);
    printf("- RESISTENCIA:\t %d\n", ia->stats.resistencia);
    printf("- CURACION:\t %d\n", ia->stats.curacion);
    printf("- ENERGIA:\t %d\n", ia->stats.energia);
}
