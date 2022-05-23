#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "notebook.h"
#include "trabajo.h"
#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "inputs.h"
#include "hardcodeo.h"

#define TAMNOTEBOOK 100
#define TAMTRABAJOS 20
#define TAMMARCAS 4
#define TAMTIPOS 4
#define TAMSERVICIO 4
int main()
{
    char salir;
    int contadorIdNotebook=1;
    int contadorIdTrabajo=1;
    int hayUnNotebook=0;
    int hayUnTrabajo=0;


    eNotebook listaNotebook[TAMNOTEBOOK];

    eMarca listaMarcas[TAMMARCAS]={{1000, "Compaq"}, {1001, "Asus"}, {1002, "Acer"}, {1003, "HP"}};

    eTipo listaTipos[TAMTIPOS]={{5000, "Gamer"}, {5001, "Disenio"}, {5002, "UltraBook"}, {5003, "Normalita"}};

    eServicio listaServicio[TAMSERVICIO]={{20000,"Bateria", 2250.00}, {20001, "Display", 10300.00}, {20002, "Mantenimiento", 4400.00}, {20003, "Fuente", 5600.00}};

    eTrabajo listaTrabajos[TAMTRABAJOS];

    inicializarNotebook(listaNotebook, TAMNOTEBOOK);
    inicializarTrabajo(listaTrabajos, TAMTRABAJOS);

    harcodearNotebooks(listaNotebook, TAMNOTEBOOK, 10, &contadorIdNotebook);
    hayUnNotebook=1;

    hardcodearTrabajos(listaTrabajos, TAMTRABAJOS, 10, &contadorIdTrabajo);
    hayUnTrabajo=1;

    do
    {


        switch(menu())
        {
            case 1:
                if(altaNotebook(listaNotebook, TAMNOTEBOOK, listaMarcas, TAMMARCAS, listaTipos, TAMTIPOS, &contadorIdNotebook)==0)
                {
                   hayUnNotebook=1;
                }
                break;
            case 2:
                if(hayUnNotebook==1)
                {
                  modificarNotebook(listaNotebook, TAMNOTEBOOK, listaMarcas, TAMMARCAS, listaTipos, TAMTIPOS);
                }
                else
                {
                   printf("\nNo se han ingresados notebooks al sistema...\n\n");
                }
                break;
            case 3:
                if(hayUnNotebook==1)
                {
                    BajaNotebook(listaNotebook, TAMNOTEBOOK, listaMarcas, TAMMARCAS, listaTipos, TAMTIPOS);
                }
                else
                {
                   printf("\nNo se han ingresados notebooks al sistema...\n\n");
                }
                break;
            case 4:
                if(hayUnNotebook==1)
                {
                    mostrarNotebooks(listaNotebook, TAMNOTEBOOK, listaMarcas, TAMMARCAS, listaTipos, TAMTIPOS);
                }
                else
                {
                    printf("\nNo se han ingresados notebooks al sistema...\n\n");
                }
                break;
            case 5:
                mostrarMarcas(listaMarcas, TAMMARCAS);
                break;
            case 6:
                mostrarTipos(listaTipos, TAMTIPOS);
                break;
            case 7:
                mostrarServicios(listaServicio, TAMSERVICIO);
                break;
            case 8:
                if(hayUnNotebook==1)
                {
                    altaTrabajo(listaTrabajos, TAMTRABAJOS, listaNotebook, TAMNOTEBOOK, listaMarcas, TAMMARCAS, listaTipos, TAMTIPOS, listaServicio, TAMSERVICIO, &contadorIdTrabajo);
                    hayUnTrabajo=1;
                }
                else
                {
                    printf("\nNo se han ingresados notebooks al sistema...\n\n");
                }
                break;
            case 9:
                if(hayUnNotebook==1 && hayUnTrabajo==1)
                {
                    mostrarTrabajos(listaTrabajos, TAMTRABAJOS, listaNotebook, TAMNOTEBOOK, listaMarcas, TAMMARCAS, listaTipos, TAMTIPOS, listaServicio, TAMSERVICIO);
                }
                else
                {
                    printf("\nNo se han ingresados notebooks al sistema y ni trabajos...\n\n");
                }
                break;
            case 10:
                if(hayUnNotebook==1)
                {
                    informesNotebooks(listaNotebook, TAMNOTEBOOK, listaMarcas, TAMMARCAS, listaTipos, TAMTIPOS);
                }
                else
                {
                    printf("\nNo se han ingresados notebooks al sistema...\n\n");
                }
                break;
            case 11:
                if(hayUnNotebook==1 && hayUnTrabajo==1)
                {
                    informesTrabajo(listaTrabajos, TAMTRABAJOS, listaNotebook, TAMNOTEBOOK, listaMarcas, TAMMARCAS, listaTipos, TAMTIPOS, listaServicio, TAMSERVICIO);
                }
                else
                {
                    printf("\nNo se han ingresados notebooks al sistema y ni trabajos...\n\n");
                }
                break;
            case 12:
                ingresoChar(&salir, "\nPrsione s para salir del menu (s/n): ");
                break;
             default:
                printf("\nError. Ingrese una opcion (1-10): \n\n");
                break;

        }

    }while(salir!='s');

    return 0;
}
























//Real Agustin 1°A, 11/5/2022

//Real Agustin 1°A, 23/5/2022
