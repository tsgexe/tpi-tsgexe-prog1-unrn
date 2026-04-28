/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#include "menu.h"
#include "combate.h"

void mostrar_titulo_principal()
{
    printf("┓   ┳┓     ┓┓    \n");
    printf("┃ ┏┓┣┫┏┓╋┏┓┃┃┏┓  \n");
    printf("┗┛┗┻┻┛┗┻┗┗┻┗┗┗┻  \n");
    printf("┏┓    ┓   ┳┓     \n");
    printf("┃┃┏┓┏┓┃ ┏┓┃┃┏┓╋┏┓\n");
    printf("┣┛┗┛┛ ┗┛┗┻┛┗┗┛┗┗┻\n");
    printf("© tsgexe. 2025\n");
    printf("Ingenieria en Computacion\n");
    printf("Programacion 1\n");
    printf("Universidad Nacional de Rio Negro\n");
    printf("=================================\n");
}

int menu_jugador()
{
    int opcion = 0;
    bool error_entrada = true;
    int retorno_scanf = 0;

    printf("\n===== QUE QUIERES HACER? =====\n");
    printf("1. \tATACAR   (Coste: %d)\n", COSTO_ATAQUE);
    printf("2. \tDEFENDER (Coste: %d)\n", COSTO_DEFENDER);
    printf("3. \tCURAR    (Coste: %d)\n", COSTO_CURAR);
    printf("4. \tSALTAR TURNO\n");

    while (error_entrada == true)
    {
        printf("TU ELECCION -> ");
        retorno_scanf = scanf("%d", &opcion);

        if (retorno_scanf != 1)
        {
            limpiar_buffer();

            printf("Entrada invalida: Solo puede ingresar numeros\n");
        }
        else if (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4)
        {
            error_entrada = false;
        }
        else
        {
            limpiar_buffer();

            printf("Opcion incorrecta, vuelva a ingresar\n");
        }
    }

    return opcion;
}

void pausar_consola()
{
    printf("\n===== Juego terminado. Presiona ENTER para salir del programa ===== ");
    
    limpiar_buffer();
    
    getchar(); 
}

