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

#define ENERGIA_BASE 100

int main()
{
    srand((unsigned)time(NULL));

    int manejo_error = 0;

    entidad_t jugador =
    {
        .vida = 100,
        .energia = ENERGIA_BASE,
        .defensa_activa = false,

        .stats =
        {
            .energia = 0,
            .ataque = 0,
            .resistencia = 0,
        }
    };

    entidad_t ia =
    {
        .vida = 100,
        .energia = ENERGIA_BASE,
        .defensa_activa = false,

        .stats =
        {
            .energia = 0,
            .ataque = 0,
            .resistencia = 0,
        }
    };

    mostrar_titulo_principal();

    manejo_error = iniciar_personaje(&jugador);
    if (manejo_error == EXIT_FAILURE)
    {
        fprintf(stderr, "ERROR CRITICO: No se ha iniciado personaje correctamente. Programa no puede seguir\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        manejo_error = 0;
    }

    manejo_error = asignar_puntos(&jugador);
    if (manejo_error == EXIT_FAILURE)
    {
        fprintf(stderr, "ERROR CRITICO: La asignacion aleatoria de puntos ha fallado. Programa no puede seguir\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        manejo_error = 0;
    }

    manejo_error = iniciar_personaje_ia(&ia);
    if (manejo_error == EXIT_FAILURE)
    {
        fprintf(stderr, "ERROR CRITICO: No se ha iniciado IA correctamente. Programa no puede seguir\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        manejo_error = 0;
    }

    mostrar_puntos_stats(&jugador, &ia);

    control_juego(&jugador, &ia);

    pausar_consola();

    return 0;
}