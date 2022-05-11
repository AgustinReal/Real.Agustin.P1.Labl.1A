#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicio.h"

int cargarDescripcionServicio(eServicio* listaServicio, int tamServicio, int idServicio, char descripcion[])
{
    int todoOk=-1;

    if(listaServicio!=NULL && tamServicio>0 && descripcion!=NULL)
    {
        for(int i=0;i<tamServicio;i++)
        {
            if(listaServicio[i].id==idServicio)
            {
                strcpy(descripcion, listaServicio[i].descripcion);
                break;
            }
        }
        todoOk=1;
    }

    return todoOk;
}
int mostrarServicios(eServicio* listaServicio, int tamServicio)
{
    int todoOk;

    if(listaServicio!=NULL && tamServicio>0)
    {
            printf("\n _______ ________________ ___________ \n");
            printf("|       |                |           |\n");
            printf("| *ID*  |   *SERVICIO*   | *PRECIO*  |\n");
            printf("|_______|________________|___________|\n");
        for(int i=0;i<tamServicio;i++)
        {
            printf("| %-3d | %-14s | $%-8.2f |\n", listaServicio[i].id, listaServicio[i].descripcion, listaServicio[i].precio);
        }
            printf("|_______|________________|___________|\n\n");
        todoOk=1;
    }

    return todoOk;
}
int buscarServicioPorId(eServicio* listaServicio, int tamServicio, int idServicio)
{
    int indiceEncontrado=-1;

    if(listaServicio!=NULL && tamServicio>0)
    {
        for(int i=0;i<tamServicio;i++)
        {
            if(listaServicio[i].id==idServicio)
            {
               indiceEncontrado=i;
               break;
            }
        }
    }

    return indiceEncontrado;
}




























//Real Agustin 1°A, 11/5/2022
