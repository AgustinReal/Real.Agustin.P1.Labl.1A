#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"
#include "servicio.h"
#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#include "inputs.h"


int inicializarTrabajo(eTrabajo* listaTrabajo, int tamTrabajo)
{
   int todoOk=-1;

   if(listaTrabajo!=NULL && tamTrabajo>0)
   {
       for(int i=0;i<tamTrabajo;i++)
       {
           listaTrabajo[i].isEmpty=1;
       }
       todoOk=1;
   }

   return todoOk;
}
int buscarTrabajoLibre(eTrabajo* listaTrabajo, int tamTrabajo)
{
   int index=-1;

   if(listaTrabajo!=NULL && tamTrabajo>0)
   {
       for(int i=0;i<tamTrabajo;i++)
       {
           if(listaTrabajo[i].isEmpty==1)
           {
               index=i;
               break;
           }
       }
   }

   return index;
}
int altaTrabajo(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio, int* contadorIdTrabajo)
{
    int todoOk=-1;
    int index;
    char afirmacion;
    eTrabajo auxTrabajo;


    if(listaTrabajo!=NULL && tamTrabajo>0 && listaNotebook!=NULL && tamNotebook>0 && listaTipo>0 && tamTipo>0 && listaMarca!=NULL && tamMarca>0 && listaServicio!=NULL && tamServicio>0 && contadorIdTrabajo!=NULL)
    {
        index=buscarTrabajoLibre(listaTrabajo, tamTrabajo);

        if(index!=-1)
        {

            printf("\n   ____________________________________________________________________________________\n");
            printf(" |                                                                                    |\n");
            printf(" |                              ***Alta de Trabajo***                                 |\n");
            printf(" |____________________________________________________________________________________|\n\n");

            auxTrabajo.id=*contadorIdTrabajo;
            (*contadorIdTrabajo)++;

            mostrarNotebooks(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);

            printf("Ingrese el id de la notebook: ");
            scanf("%d", &auxTrabajo.idNotebook);
            while(buscarNotebookPorId(listaNotebook, tamNotebook, auxTrabajo.idNotebook)<0)
            {
                printf("Error Id, Ingrese el id del notebook: ");
                scanf("%d", &auxTrabajo.idNotebook);
            }

            mostrarServicios(listaServicio, tamServicio);

            ingresoEntero(&auxTrabajo.idServicio, "Ingrese el id del servicio (20000-20003): ", "Error.Ingrese el id del servicio (20000-20003): ", 20000, 20003);

            fechaPedirVerificarFecha(&auxTrabajo.fecha);

            auxTrabajo.isEmpty=0;

            printf(" ______________________________________________________________________________________________________________________________________________________\n");
            printf("|                                                                                                                                                      |\n");
            printf("|                                                        ****Servicio de notebooks****                                                                 |\n");
            printf("|                                                           **Listado de Trabajos**                                                                    |\n");
            printf("|______________________________________________________________________________________________________________________________________________________|\n");
            printf("|     Id     |                              ***Notebooks***                              |                    *Datos Trabajos*                         |\n");
            printf("|  Trabajos  |  *ids* |     *MODELO*     |     *Marcas*    |    *Tipos*    |   precios   |   *Servicios*  |  *Precios servicios*  | *Fechas servicios* |\n");
            printf("|____________|________|__________________|_________________|_______________|_____________|________________|_______________________|____________________|\n");
            mostrarTrabajo(auxTrabajo, tamTrabajo, listaNotebook,  tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);
            printf("|____________|________|__________________|_________________|_______________|_____________|________________|_______________________|____________________|\n");

            ingresoChar(&afirmacion, "Presione s para dar de alta el trabajo (s/n): ");

            if(afirmacion=='s' || afirmacion=='S')
            {
                listaTrabajo[index]=auxTrabajo;
                printf("Se ha agregado con exitos...\n");
            }
            else
            {
               auxTrabajo.isEmpty=1;
               (*contadorIdTrabajo)--;
               printf("\nSe cancelo el alta del trabajo...\n\n");
            }

        }
        else
        {
            printf("\nNo hay espacio en el sistema...\n\n");
        }
    }

    return todoOk;

}
int mostrarTrabajo(eTrabajo unTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio)
{
    int todoOk=-1;
    char descripciontipo[20];
    char descripcionMarca[20];
    char descripcionServicio[25];
    int indiceNotebook;
    int indiceServicio;

    if(tamTrabajo>0 && listaNotebook!=NULL && tamNotebook>0 && listaTipo>0 && tamTipo>0 && listaMarca!=NULL && tamMarca>0 && listaServicio!=NULL && tamServicio>0)
    {
        indiceNotebook=buscarNotebookPorId(listaNotebook, tamNotebook, unTrabajo.idNotebook);
        indiceServicio=buscarServicioPorId(listaServicio, tamServicio, unTrabajo.idServicio);

        cargarDescripcionTipo(listaTipo, tamTipo, listaNotebook[indiceNotebook].idTipo, descripciontipo);
        cargarDescripcionMarca(listaMarca, tamMarca, listaNotebook[indiceNotebook].idMarca, descripcionMarca);
        cargarDescripcionServicio(listaServicio, tamServicio , unTrabajo.idServicio, descripcionServicio);

        printf("|     %3d    | %4d   |   %-13s  |      %-10s |   %-10s  |  $%-9.2f   |   %-14s  |        $%-9.2f     |      %02d/%02d/%d    |\n",
               unTrabajo.id,
               listaNotebook[indiceNotebook].id,
               listaNotebook[indiceNotebook].modelo,
               descripcionMarca,
               descripciontipo,
               listaNotebook[indiceNotebook].precio,
               descripcionServicio,
               listaServicio[indiceServicio].precio,
               unTrabajo.fecha.dia,
               unTrabajo.fecha.mes,
               unTrabajo.fecha.anio
               );
        todoOk=0;

    }

    return todoOk;
}
int mostrarTrabajos(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio)
{
    int todoOk=-1;

    if(listaTrabajo!=NULL && tamTrabajo>0 && listaNotebook!=NULL && tamNotebook>0 && listaTipo>0 && tamTipo>0 && listaMarca!=NULL && tamMarca>0 && listaServicio!=NULL && tamServicio>0)
    {
        printf(" ___________________________________________________________________________________________________________________________________________________________\n");
        printf("|                                                                                                                                                           |\n");
        printf("|                                                        ****Servicio de notebooks****                                                                      |\n");
        printf("|                                                           **Listado de Trabajos**                                                                         |\n");
        printf("|___________________________________________________________________________________________________________________________________________________________|\n");
        printf("|     Id     |                              ***Notebooks***                                |                       *Datos Trabajos*                         |\n");
        printf("|  Trabajos  |  *ids* |     *MODELO*     |     *Marcas*    |    *Tipos*    |    precios    |     *Servicios*   |  *Precios servicios*  | *Fechas servicios* |\n");
        printf("|____________|________|__________________|_________________|_______________|_______________|___________________|_______________________|____________________|\n");
        for(int i=0;i<tamTrabajo;i++)
        {
            if(listaNotebook[i].isEmpty==0 && listaTrabajo[i].isEmpty==0)
            {
                mostrarTrabajo(listaTrabajo[i], tamTrabajo, listaNotebook,  tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);
            }
        }
        printf("|____________|________|__________________|_________________|_______________|_______________|___________________|_______________________|____________________|\n");
        todoOk=1;
    }

    return todoOk;
}





































//Real Agustin 1°A, 11/5/2022
