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
#include "estructuras.h"

int logica_ia(entidad_t *jugador, entidad_t *ia)
{
    int codigo_accion = 0;
    int probabilidad = ia_randomizer();

    if (jugador == NULL || ia == NULL)
    {
        fprintf(stderr, "ERROR: Una o mas entidades no se han inicializado correctamente\n");
    }
    else
    {
        if (ia->vida <= 15)
        {
            if (probabilidad <= 85)
            {
                if (ia->energia >= COSTO_CURAR)
                {
                    curar(ia);
                    codigo_accion = IA_CURACION;
                }
                else if (ia->energia >= COSTO_DEFENDER)
                {
                    defender(ia);
                    codigo_accion = IA_DEFENSA;
                }
                else
                {
                    skipear_turno(ia);
                    codigo_accion = IA_SKIP;
                }
            }
            else
            {
                if (ia->energia >= COSTO_ATAQUE)
                {
                    atacar(ia, jugador);
                    codigo_accion = IA_ATAQUE;
                }
                else if (ia->energia >= COSTO_DEFENDER)
                {
                    defender(ia);
                    codigo_accion = IA_DEFENSA;
                }
                else
                {
                    skipear_turno(ia);
                    codigo_accion = IA_SKIP;
                }
            }
        }
        else if (ia->vida <= 35)
        {
            if (probabilidad <= 65)
            {
                if (ia->energia >= COSTO_CURAR)
                {
                    curar(ia);
                    codigo_accion = IA_CURACION;
                }
                else if (ia->energia >= COSTO_DEFENDER)
                {
                    defender(ia);
                    codigo_accion = IA_DEFENSA;
                }
                else
                {
                    skipear_turno(ia);
                    codigo_accion = IA_SKIP;
                }
            }
            else if (probabilidad <= 85)
            {
                if (ia->energia >= COSTO_ATAQUE)
                {
                    atacar(ia, jugador);
                    codigo_accion = IA_ATAQUE;
                }
                else if (ia->energia >= COSTO_DEFENDER)
                {
                    defender(ia);
                    codigo_accion = IA_DEFENSA;
                }
                else
                {
                    skipear_turno(ia);
                    codigo_accion = IA_SKIP;
                }
            }
            else
            {
                if (ia->energia >= COSTO_DEFENDER)
                {
                    defender(ia);
                    codigo_accion = IA_DEFENSA;
                }
                else
                {
                    skipear_turno(ia);
                    codigo_accion = IA_SKIP;
                }
            }
        }
        else if (ia->energia <= 25)
        {
            if (probabilidad <= 70)
            {
                skipear_turno(ia);
                codigo_accion = IA_SKIP;
            }
            else
            {
                if (ia->energia >= COSTO_DEFENDER)
                {
                    defender(ia);
                    codigo_accion = IA_DEFENSA;
                }
                else
                {
                    skipear_turno(ia);
                    codigo_accion = IA_SKIP;
                }
            }
        }
        else if (ia->energia <= 40)
        {
            if (probabilidad <= 60)
            {
                if (ia->energia >= COSTO_DEFENDER)
                {
                    defender(ia);
                    codigo_accion = IA_DEFENSA;
                }
                else
                {
                    skipear_turno(ia);
                    codigo_accion = IA_SKIP;
                }
            }
            else
            {
                skipear_turno(ia);
                codigo_accion = IA_SKIP;
            }
        }
        else if (jugador->vida <= 40 || ia->vida > jugador->vida * 2)
        {
            if (probabilidad <= 90)
            {
                if (ia->energia >= COSTO_ATAQUE)
                {
                    atacar(ia, jugador);
                    codigo_accion = IA_ATAQUE;
                }
                else if (ia->energia >= COSTO_DEFENDER)
                {
                    defender(ia);
                    codigo_accion = IA_DEFENSA;
                }
                else
                {
                    skipear_turno(ia);
                    codigo_accion = IA_SKIP;
                }
            }
            else
            {
                if (ia->energia >= COSTO_DEFENDER)
                {
                    defender(ia);
                    codigo_accion = IA_DEFENSA;
                }
                else
                {
                    skipear_turno(ia);
                    codigo_accion = IA_SKIP;
                }
            }
        }
        else
        {
            if (ia->energia >= COSTO_ATAQUE)
            {
                atacar(ia, jugador);
                codigo_accion = IA_ATAQUE;
            }
            else if (ia->energia >= COSTO_DEFENDER)
            {
                defender(ia);
                codigo_accion = IA_DEFENSA;
            }
            else
            {
                skipear_turno(ia);
                codigo_accion = IA_SKIP;
            }
        }
    }

    return codigo_accion;
}

int iniciar_personaje_ia(entidad_t *ia)
{   
    int codigo_retorno = EXIT_SUCCESS;

    char nombre_default[LARGO_NOMBRE] = "Lorem Ipsum"; 

    if (ia == NULL)
    {
        fprintf(stderr, "ERROR: la entidad 'IA' no se ha inicializado correctamente");
        codigo_retorno = EXIT_FAILURE; 
    }
    else
    {
        if (obtener_nombre_random(ia->nombre, sizeof(ia->nombre), "nombres_ia/nombres_ia.txt") == EXIT_SUCCESS)
        {
            printf("La IA se llama: %s\n", ia->nombre);
            asignar_puntos(ia);
        }
        else
        {
            printf("Se asignara un nombre predeterminado...\n");
            printf("Nombre predeterminado: %s\n", nombre_default);
            strncpy(ia->nombre, nombre_default, LARGO_NOMBRE);
            asignar_puntos(ia);
        }

        printf("IA generada -> %s\n", ia->nombre);
    }

    return codigo_retorno;
}

int obtener_nombre_random(char *destino, size_t capacidad_destino, const char *ruta_archivo)
{
    int codigo_retorno = EXIT_SUCCESS;
    char buffer_nombre[LARGO_NOMBRE];
    const int max_nombres = 10;
    char nombres[max_nombres][LARGO_NOMBRE];
    int contador_nombres = 0;

    FILE *lista_nombres = fopen(ruta_archivo, "r");

    if (lista_nombres == NULL)
    {
        perror("ERROR AL ABRIR ARCHIVO DE NOMBRES PARA IA");
        codigo_retorno = EXIT_FAILURE;
    }
    else
    {
        while (contador_nombres < max_nombres && fgets(buffer_nombre, sizeof(buffer_nombre), lista_nombres) != NULL)
        {
            buffer_nombre[strcspn(buffer_nombre, "\n")] = '\0';

            if (strlen(buffer_nombre) > 0)
            {
                strncpy(nombres[contador_nombres], buffer_nombre, LARGO_NOMBRE - 1);
                nombres[contador_nombres][LARGO_NOMBRE - 1] = '\0';
                contador_nombres++;
            }
        }

        fclose(lista_nombres);

        if (contador_nombres > 0)
        {
            int indice_random = rand() % contador_nombres;
            strncpy(destino, nombres[indice_random], capacidad_destino - 1);
            destino[capacidad_destino - 1] = '\0';
        }
        else
        {
            fprintf(stderr, "ERROR: No se encontraron nombres en el archivo\n");
            codigo_retorno = EXIT_FAILURE;
        }
    }

    return codigo_retorno;
}