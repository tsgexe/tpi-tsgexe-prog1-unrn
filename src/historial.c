/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#include "historial.h"

void iniciar_historial(historial_t *historial)
{
    historial->primero = NULL;
    historial->ultimo = NULL;
    historial->cantidad = 0;
}

int registro_historial(historial_t *historial, int turno, const char *personaje, const char *accion,
                       int vida_jugador, int energia_jugador, int vida_ia, int energia_ia)
{
    int codigo_retorno = EXIT_SUCCESS;
    nodo_historial_t *nuevo = malloc(sizeof(nodo_historial_t));

    if (nuevo == NULL)
    {
        fprintf(stderr, "ERROR: No se ha podido crear un nuevo nodo de historial\n");
        codigo_retorno = EXIT_FAILURE;
    }
    else
    {
        nuevo->turno = turno;

        strncpy(nuevo->personaje, personaje, LARGO_NOMBRE - 1);
        nuevo->personaje[LARGO_NOMBRE - 1] = '\0';

        strncpy(nuevo->accion, accion, sizeof(nuevo->accion) - 1);
        nuevo->accion[sizeof(nuevo->accion) - 1] = '\0';

        nuevo->vida_jugador = vida_jugador;
        nuevo->energia_jugador = energia_jugador;
        nuevo->vida_ia = vida_ia;
        nuevo->energia_ia = energia_ia;
        nuevo->siguiente = NULL;

        if (historial->primero == NULL)
        {
            historial->primero = nuevo;
        }
        else
        {
            historial->ultimo->siguiente = nuevo;
        }

        historial->ultimo = nuevo;
        historial->cantidad++;
    }

    return codigo_retorno;
}

int guardar_historial(const historial_t *historial, const char *ruta_historial)
{
    int codigo_retorno = EXIT_SUCCESS;
    nodo_historial_t *actual = NULL;
    FILE *archivo_historial = fopen(ruta_historial, "w");

    if (archivo_historial == NULL)
    {
        perror("NO SE PUDO ACCEDER AL ARCHIVO DE HISTORIAL");
        codigo_retorno = EXIT_FAILURE;
    }
    else
    {
        fprintf(archivo_historial, "===== HISTORIAL DE BATALLA =====\n");

        actual = historial->primero;
        while (actual != NULL)
        {
            fprintf(archivo_historial,
                    "[Turno %d] %s → %s\n"
                    "\t%s: VIDA %d | ENERGÍA %d\n"
                    "\t%s: VIDA %d | ENERGÍA %d\n"
                    "-----------------------------------\n",
                    actual->turno,
                    actual->personaje,
                    actual->accion,
                    "Jugador", actual->vida_jugador, actual->energia_jugador,
                    "IA", actual->vida_ia, actual->energia_ia);

            actual = actual->siguiente;
        }

        fprintf(archivo_historial, "=================================\n\n");
        fclose(archivo_historial);
    }

    return codigo_retorno;
}

void liberar_memoria_historial(historial_t *historial)
{
    nodo_historial_t *actual = historial->primero;
    while (actual != NULL)
    {
        nodo_historial_t *borrar = actual;
        actual = actual->siguiente;
        free(borrar);
    }

    historial->primero = NULL;
    historial->ultimo = NULL;
    historial->cantidad = 0;
}