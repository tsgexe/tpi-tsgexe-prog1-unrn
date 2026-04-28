/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#include "combate.h"
#include "entidades.h"
#include "utilidades.h"

int atacar(entidad_t *atacante, entidad_t *enemigo)
{
    float daño_original = 0;
    float daño_real = 0;
    int codigo_retorno = EXIT_SUCCESS;

    if (atacante == NULL || enemigo == NULL)
    {
        fprintf(stderr, "ERROR: Una de las entidades (atacante o enemigo) no se ha inicializado correctamente");
        codigo_retorno = EXIT_FAILURE;
    }
    else
    {

        if (fallo_accion() == true)
        {
            printf("%s ha errado su ataque!\n", atacante->nombre);
            descontar_energia(atacante, COSTO_ATAQUE);
            codigo_retorno = EXIT_FAILURE;
        }
        else if (atacante->energia < COSTO_ATAQUE)
        {
            printf("%s no tiene energia para atacar...\n", atacante->nombre);
            codigo_retorno = EXIT_FAILURE;
        }
        else
        {
            descontar_energia(atacante, COSTO_ATAQUE);

            // El atacante realizo con exito su ataque
            daño_original = 20 + (atacante->stats.ataque * 1.5);
            daño_real = daño_original - (enemigo->stats.resistencia * 0.8);

            if (enemigo->defensa_activa == true)
            {
                daño_real *= 0.5;
                enemigo->defensa_activa = false;
            }

            // Se castea daño_real a int y se resta a la vida del enemigo
            enemigo->vida -= (int)daño_real;
            enemigo->ultimo_daño = (int)daño_real;

            if (enemigo->vida <= 0)
            {
                enemigo->vida = 0;
            }
        }
    }

    return codigo_retorno;
}

int defender(entidad_t *personaje)
{
    int codigo_retorno = EXIT_SUCCESS;

    if (personaje == NULL)
    {
        fprintf(stderr, "ERROR: La entidad 'personaje' no se ha inicializado correctamente");
    }
    else
    {
        if (fallo_accion() == true)
        {
            printf("%s no se puede defender!\n", personaje->nombre);
            descontar_energia(personaje, COSTO_DEFENDER);
            codigo_retorno = EXIT_FAILURE;
        }
        else if (personaje->energia < COSTO_DEFENDER)
        {
            printf("%s no tiene energia para defenderse...\n", personaje->nombre);
        }
        else
        {

            personaje->defensa_activa = true;
            descontar_energia(personaje, COSTO_DEFENDER);
        }
    }

    return codigo_retorno;
}

int curar(entidad_t *personaje)
{
    int codigo_retorno = EXIT_SUCCESS;

    if (personaje == NULL)
    {
        fprintf(stderr, "ERROR: No se ha podido acceder a entidad 'personaje'\n");
        codigo_retorno = EXIT_FAILURE;
    }
    else
    {
        if (fallo_accion() == true)
        {
            printf("%s no ha podido curarse!\n", personaje->nombre);
            descontar_energia(personaje, COSTO_CURAR);
        }
        else if (personaje->energia < COSTO_CURAR)
        {
            printf("%s no tiene energia para curarse...\n", personaje->nombre);
        }
        else if (personaje ->vida == VIDA_MAX)
        {
            printf("%s se ha tratado de curar pero tiene su vida completa!\n", personaje->nombre);
        }
        else
        {
            descontar_energia(personaje, COSTO_CURAR);
            personaje->vida += 10;
        }
    }

    return codigo_retorno;
}

int descontar_energia(entidad_t *personaje, int costo_energia)
{
    int codigo_retorno = EXIT_SUCCESS;

    if (personaje == NULL)
    {
        fprintf(stderr, "ERROR: La entidad 'personaje' no se ha inicializado correctamente");
    }
    else
    {
        if (personaje->energia >= costo_energia)
        {
            personaje->energia -= costo_energia;
        }
        else
        {
            codigo_retorno = EXIT_FAILURE;
        }
    }

    return codigo_retorno;
}

int recuperar_energia(entidad_t *jugador, entidad_t *ia, bool es_turno_ia)
{
    int codigo_retorno = EXIT_SUCCESS;
    entidad_t *objetivo = NULL;
    float energia_recuperada = 0;

    if (es_turno_ia == true)
    {
        objetivo = ia;
    }
    else
    {
        objetivo = jugador;
    }

    if (objetivo->energia < ENERGIA_BASE)
    {
        energia_recuperada = 4 + (objetivo->stats.energia * 0.3f);

        objetivo->energia += (int)energia_recuperada;

        if (objetivo->energia > ENERGIA_BASE)
        {
            objetivo->energia = ENERGIA_BASE;
        }
    }
    else
    {
        codigo_retorno = EXIT_FAILURE;
    }

    return codigo_retorno;
}

int skipear_turno(entidad_t *personaje)
{
    int codigo_retorno = EXIT_SUCCESS;
    float energia_recuperada = 0;

    if (personaje->energia < ENERGIA_BASE)
    {
        energia_recuperada = (ENERGIA_BASE - personaje->energia) * 0.4f;

        personaje->energia += (int)energia_recuperada;

        if (personaje->energia > ENERGIA_BASE)
        {
            personaje->energia = ENERGIA_BASE;
        }
    }
    else
    {
        codigo_retorno = EXIT_FAILURE;
    }

    return codigo_retorno;
}