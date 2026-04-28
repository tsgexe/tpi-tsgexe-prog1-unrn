/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#include "utilidades.h"

bool fallo_accion()
{
    bool fallo = true;
    int numero_random = 0;

    numero_random = (rand() % 100 + 1);

    if (numero_random <= 70)
    {
        fallo = false;
    }
    else
    {
        fallo = true;
    }

    return fallo;
}

int ia_randomizer()
{
    int numero_random = 0;

    numero_random = (rand() % 100 + 1);

    return numero_random;
}

void limpiar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}