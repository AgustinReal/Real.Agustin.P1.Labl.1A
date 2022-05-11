#include "hardcodeo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/////////////////////////////////////////////////////Notebook/////////////////////////////////////////////////////////////////

char modelos[10][20]={
    {"Playstation"},
    {"Zoolom"},
    {"Julios"},
    {"Samsung"},
    {"SuperGamer"},
    {"TodoLed"},
    {"Monster"},
    {"UsaUltraGamer"},
    {"ArgentinaPc"},
    {"hyperX"}
    };

int IdMarca[10]={1000, 1001, 1002, 1003, 1003, 1000, 1001, 1002,1002,1002};

int IdTipo[10]={5003, 5001, 5000, 5003, 5002, 5002, 5001, 5002, 5000, 5001};

float precios[10]={132000.00, 75000.00, 111000.00, 105000.00, 85000.00, 110000.00, 100000.00, 92000.00, 68000.00, 72211.00};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////Trabajos/////////////////////////////////////////////////////////////////

int idNotebooks[10]={1,8,4,6,5,9,10,6,5,7};

int idServicios[10]={20001,20003,20002,20001,20001,20003,20002,20003,20002,20003};

eFecha fechas[10]={
            {15,7,2021},
            {16,6,2022},
            {15,7,2021},
            {2,6,2022},
            {20,3,2021},
            {1,6,2020},
            {4,6,2022},
            {15,4,2021},
            {16,6,2021},
            {15,4,2020},
    };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int harcodearNotebooks(eNotebook arrayNotebook[], int tamNotebook, int cantidadACargar, int* pIdNotebook)
{
    int contador=-1;

    if(arrayNotebook!=NULL && tamNotebook>0 && cantidadACargar>=0 && cantidadACargar<=tamNotebook && pIdNotebook!=NULL)
    {
        contador=0;
        for(int i=0; i<cantidadACargar; i++)
        {
            arrayNotebook[i].id= *pIdNotebook;
            (*pIdNotebook)++;
            strcpy(arrayNotebook[i].modelo, modelos[i]);
            arrayNotebook[i].idMarca=IdMarca[i];
            arrayNotebook[i].idTipo=IdTipo[i];
            arrayNotebook[i].precio=precios[i];
            arrayNotebook[i].isEmpty=0;
            contador++;
        }
    }
    return contador;
}

int hardcodearTrabajos(eTrabajo listaTrabajo[], int tamTrabajo, int cantidad, int* contadorIdTrabajos)
{
    int contador=-1;

    if(listaTrabajo!=NULL && tamTrabajo>0 && cantidad>=0 && cantidad<=tamTrabajo && contadorIdTrabajos!=NULL)
    {
        contador=0;
        for(int i=0; i<cantidad; i++)
        {
            listaTrabajo[i].id= *contadorIdTrabajos;
            (*contadorIdTrabajos)++;
            listaTrabajo[i].idNotebook=idNotebooks[i];
            listaTrabajo[i].idServicio=idServicios[i];
            listaTrabajo[i].fecha=fechas[i];
            listaTrabajo[i].isEmpty=0;
            contador++;
        }
    }
    return contador;
}














































//Real Agustin 1°A, 11/5/2022
