/*
TP INTEGRADOR
-----------------
Tomas Santiago Gonzalez
Usuario Github: tsgexe
*/

#include "control_juego.h"
#include "historial.h"
#include "menu.h"
#include "ia.h"
#include "combate.h"

void control_juego(entidad_t *jugador, entidad_t *ia)
{
    bool muerte_entidad = false;
    bool repetir_accion = true;
    int opcion = 0;
    int opcion_ia = 0;
    int turno = TURNO_JUGADOR;
    int contador_turno = 1;

    // Se define e inicia un historial
    historial_t historial;
    iniciar_historial(&historial);

    printf("ATENCION, JUGADOR! %s aparece frente a ti y no parece amistoso...\n", ia->nombre);

    printf("PREPARATE PARA LA BATALLA!\n");
    
    while (muerte_entidad == false)
    {
        if (comprobar_estado(jugador) == ENTIDAD_MUERTA)
        {
            muerte_entidad = true;
            printf("%s HA GANADO LA BATALLA!\n", ia->nombre);
            printf("Has perdido...\n");
            printf("STATS FINALES:\n");
            mostrar_datos_entidad(jugador, ia);
            guardar_historial(&historial, "historial/historial.txt");
            liberar_memoria_historial(&historial);
        }
        else if (comprobar_estado(ia) == ENTIDAD_MUERTA)
        {
            muerte_entidad = true;
            printf("%s HA GANADO LA BATALLA!\n", jugador->nombre);
            printf("Has ganado...\n");
            printf("STATS FINALES:\n");
            mostrar_datos_entidad(jugador, ia);
            guardar_historial(&historial, "historial/historial.txt");
            liberar_memoria_historial(&historial); 
        }
        else
        {
            if (turno == TURNO_JUGADOR)
            {
                repetir_accion = true;
                printf("\n- - - Es tu turno! - - -\n");
                printf("TURNO N°: %d\n", contador_turno);
                mostrar_datos_entidad(jugador, ia);

                opcion = menu_jugador();
                printf("OPCION LEIDA: %d\n", opcion);

                while (repetir_accion == true)
                {
                    switch (opcion)
                    {
                    case 1:
                        printf("-> %s ATACA A %s\n", jugador->nombre, ia->nombre);
                        atacar(jugador, ia);
                        registro_historial(&historial, contador_turno, jugador->nombre, "utiliza ATACAR", jugador->vida, jugador->energia, ia->vida, ia->energia);
                        repetir_accion = false;
                        
                        turno = TURNO_IA;
                        break;
                    case 2:
                        printf("-> %s SE DEFIENDE DE %s\n", jugador->nombre, ia->nombre);
                        defender(jugador);
                        registro_historial(&historial, contador_turno, jugador->nombre, "utiliza DEFENDER", jugador->vida, jugador->energia, ia->vida, ia->energia);
                        repetir_accion = false;
                        turno = TURNO_IA;
                        break;
                    case 3:
                        printf("-> %s SE CURA\n", jugador->nombre);
                        curar(jugador);
                        registro_historial(&historial, contador_turno, jugador->nombre, "utiliza CURAR", jugador->vida, jugador->energia, ia->vida, ia->energia);
                        repetir_accion = false;
                        turno = TURNO_IA;
                        break;
                    case 4:
                        printf("-> %s SALTEA SU TURNO\n", jugador->nombre);
                        skipear_turno(jugador);
                        registro_historial(&historial, contador_turno, jugador->nombre, "utiliza SALTAR TURNO", jugador->vida, jugador->energia, ia->vida, ia->energia);
                        repetir_accion = false;
                        turno = TURNO_IA;
                        break;
                    default:
                        printf("OPCION NO VALIDA\n");
                        repetir_accion = true;
                        break;
                    }
                }
            }
            else if (turno == TURNO_IA)
            {
                repetir_accion = true;

                printf("\n- - - Es el turno de %s!- - -\n", ia->nombre);
                printf("TURNO N°: %d\n", contador_turno);

                mostrar_datos_entidad(jugador, ia);

                opcion_ia = logica_ia(jugador, ia);

                switch (opcion_ia)
                {
                case 1:
                    printf("<- %s ATACA A %s\n", ia->nombre, jugador->nombre);
                    registro_historial(&historial, contador_turno, ia->nombre, "utiliza ATAQUE", ia->vida, ia->energia, jugador->vida, jugador->energia);
                    turno = TURNO_JUGADOR;
                    break;
                case 2:
                    printf("<- %s SE DEFIENDE DE %s\n", ia->nombre, jugador->nombre);
                    registro_historial(&historial, contador_turno, ia->nombre, "utiliza DEFENDER", ia->vida, ia->energia, jugador->vida, jugador->energia);
                    turno = TURNO_JUGADOR;
                    break;
                case 3:
                    printf("<- %s SE CURA\n", ia->nombre);
                    registro_historial(&historial, contador_turno, ia->nombre, "utiliza CURAR", ia->vida, ia->energia, jugador->vida, jugador->energia);
                    turno = TURNO_JUGADOR;
                    break;
                case 4:
                    printf("<- %s SALTEA SU TURNO\n", ia->nombre);
                    registro_historial(&historial, contador_turno, ia->nombre, "utiliza SALTAR TURNO", ia->vida, ia->energia, jugador->vida, jugador->energia);
                    turno = TURNO_JUGADOR;
                    break;
                }

                contador_turno++;
            }
        }
    }
}

int comprobar_estado(entidad_t *personaje)
{
    int codigo_retorno = 0;

    if (personaje->vida <= 0)
    {
        codigo_retorno = ENTIDAD_MUERTA;
    }
    else
    {
        codigo_retorno = ENTIDAD_VIVA;
    }

    return codigo_retorno;
}