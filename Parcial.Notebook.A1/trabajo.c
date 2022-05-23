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

            printf(" ___________________________________________________________________________________________________________________________________________________________\n");
            printf("|                                                                                                                                                           |\n");
            printf("|                                                        ****Servicio de notebooks****                                                                      |\n");
            printf("|                                                           **Listado de Trabajos**                                                                         |\n");
            printf("|___________________________________________________________________________________________________________________________________________________________|\n");
            printf("|     Id     |                              ***Notebooks***                                |                       *Datos Trabajos*                         |\n");
            printf("|  Trabajos  |  *ids* |     *MODELO*     |     *Marcas*    |    *Tipos*    |    precios    |     *Servicios*   |  *Precios servicios*  | *Fechas servicios* |\n");
            printf("|____________|________|__________________|_________________|_______________|_______________|___________________|_______________________|____________________|\n");
            mostrarTrabajo(auxTrabajo, tamTrabajo, listaNotebook,  tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);
            printf("|____________|________|__________________|_________________|_______________|_______________|___________________|_______________________|____________________|\n");

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
            if(listaTrabajo[i].isEmpty==0)
            {
                mostrarTrabajo(listaTrabajo[i], tamTrabajo, listaNotebook,  tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);
            }
        }
        printf("|____________|________|__________________|_________________|_______________|_______________|___________________|_______________________|____________________|\n");
        todoOk=1;
    }

    return todoOk;
}
int menuInformesTrabajo()
{
    int opcion;

    printf(" ____________________________________________________________________________________________________ \n"
           "|                                                                                                    |\n"
           "|                                     MENU PRINCIPAL INFORMES                                        |\n"
           "|                                      TRABAJOS DE NOTEBOOKS                                         |\n"
           "|____________________________________________________________________________________________________|\n"
           "|                                                                                                    |\n"
           "|1-INFORME TRABAJOS PEDIR UNA NOTEBOOK Y MOSTRAR TRABAJOS REALIZADOS DE ESA NOTEBOOK.                |\n"
           "|2-INFORME TRABAJOS PEDIR UNA NOTEBOOK Y INFORMAR LA SUMA DE IMPORTES DE LOS SERVICIOS DE LA MISMA.  |\n"
           "|3-INFORMAR TRABAJO PDEDIR UN SERVICIO Y MOSTRAR NOTEBOOKS DE ESE SERVICIO Y FECHAS.                 |\n"
           "|4-INFORMAR TRABAJO PDEDIR UNA FECHA Y MOSTRAR SERVICIOS REALIZADOS CON ESA FECHA.                   |\n"
           "|5-SALIR                                                                                             |\n"
           "|____________________________________________________________________________________________________|\n");

    printf("Usted eligio: ");
    scanf("%d", &opcion);

    return opcion;
}
int informePedirUnaNotebookMostrarTrabajos(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio)
{
    int todoOk=-1;
    int idNotebook;
    int indiceNotebook;
    int hayUnaNotebook=0;

    if(listaTrabajo!=NULL && tamTrabajo>0 && listaNotebook!=NULL && tamNotebook>0 && listaTipo>0 && tamTipo>0 && listaMarca!=NULL && tamMarca>0 && listaServicio!=NULL && tamServicio>0)
    {

        system("cls");
        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |                 ***Informe trabajos de una notebook selecionado***                 |\n");
        printf("  |____________________________________________________________________________________|\n\n");

        mostrarNotebooks(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);

        printf("\nIngrese el id de la notebook: ");
        scanf("%d", &idNotebook);
        while(buscarNotebookPorId(listaNotebook, tamNotebook, idNotebook)<0)
        {
            printf("Error Id, Ingrese el id del notebook: ");
            scanf("%d", &idNotebook);
        }

        indiceNotebook=buscarNotebookPorId(listaNotebook, tamNotebook, idNotebook);

        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |                  ***Los trabajos de la notebook con el id %-2d***                    |\n", listaNotebook[indiceNotebook].id);
        printf("  |____________________________________________________________________________________|\n\n");

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
            if(listaNotebook[indiceNotebook].isEmpty==0 && listaTrabajo[i].isEmpty==0)
            {
                if(listaTrabajo[i].idNotebook==listaNotebook[indiceNotebook].id)
                {
                    mostrarTrabajo(listaTrabajo[i], tamTrabajo, listaNotebook,  tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);
                    hayUnaNotebook=1;
                }
            }
        }

        if(hayUnaNotebook!=1)
        {
            printf("\nNo se han ingresado trabajos con en el id %d de la notebook \n\n", idNotebook);
        }


        printf("|____________|________|__________________|_________________|_______________|_______________|___________________|_______________________|____________________|\n");

        todoOk=0;
    }

    return todoOk;
}
int informePedirUnaNotebookSumarImporteServicio(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio)
{
    int todoOk=-1;
    int idNotebook;
    int idServicio;
    int indiceNotebook;
    float acumuladorPrecio=0;
    int hayUnaNotebook=0;

    if(listaTrabajo!=NULL && tamTrabajo>0 && listaNotebook!=NULL && tamNotebook>0 && listaTipo>0 && tamTipo>0 && listaMarca!=NULL && tamMarca>0 && listaServicio!=NULL && tamServicio>0)
    {

        system("cls");
        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |         ***Informe importe de un servicio de una notebook selecionado***           |\n");
        printf("  |____________________________________________________________________________________|\n\n");

        mostrarNotebooks(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);

        printf("\nIngrese el id de la notebook: ");
        scanf("%d", &idNotebook);
        while(buscarNotebookPorId(listaNotebook, tamNotebook, idNotebook)<0)
        {
            printf("Error Id, Ingrese el id del notebook: ");
            scanf("%d", &idNotebook);
        }

        indiceNotebook=buscarNotebookPorId(listaNotebook, tamNotebook, idNotebook);

        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |                  ***Los trabajos de la notebook con el id %-2d***                    |\n", listaNotebook[indiceNotebook].id);
        printf("  |____________________________________________________________________________________|\n\n");

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
            if(listaNotebook[indiceNotebook].isEmpty==0 && listaTrabajo[i].isEmpty==0)
            {
                if(listaTrabajo[i].idNotebook==listaNotebook[indiceNotebook].id)
                {
                    idServicio=buscarServicioPorId(listaServicio, tamServicio, listaTrabajo[i].idServicio);
                    acumuladorPrecio+=listaServicio[idServicio].precio;
                    mostrarTrabajo(listaTrabajo[i], tamTrabajo, listaNotebook,  tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);
                    hayUnaNotebook=1;
                }
            }
        }

        printf("|____________|________|__________________|_________________|_______________|_______________|___________________|_______________________|____________________|\n");

        if(hayUnaNotebook==1)
        {
            printf("\nEl importe totol de la notebook seleccionado es: %.2f\n", acumuladorPrecio);
        }
        else
        {
            printf("\nNo se encontro ningun servicio con la id de la notebook %d... \n", listaNotebook[indiceNotebook].id);
        }

        todoOk=0;
    }

    return todoOk;
}
int informePedirUnServicioMostrarNotebookDeEseServicioFecha(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio)
{
    int todoOk=-1;
    int pedirIdServicio;
    char descripcionServicio[25];
    int indiceNotebook;
    int hayUnServicio=0;

    if(listaTrabajo!=NULL && tamTrabajo>0 && listaNotebook!=NULL && tamNotebook>0 && listaTipo>0 && tamTipo>0 && listaMarca!=NULL && tamMarca>0 && listaServicio!=NULL && tamServicio>0)
    {
        system("cls");
        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |           ***Informe trabajo pedir servicio y mostrar notebook y fecha***          |\n");
        printf("  |____________________________________________________________________________________|\n\n");

        mostrarServicios(listaServicio, tamServicio);

        ingresoEntero(&pedirIdServicio, "Ingrese el id del servicio (20000-20003): ", "Error.Ingrese el id del servicio (20000-20003): ", 20000, 20003);

        cargarDescripcionServicio(listaServicio, tamServicio, pedirIdServicio, descripcionServicio);

        printf("\nEl servicio %s y la cantidad de las notebooks es: \n\n", descripcionServicio);

        printf(" _________________________________________________________________________________________________\n");
        printf("|                                                                                                 |\n");
        printf("|                                     ***Lista Notebooks***                                       |\n");
        printf("|_________________________________________________________________________________________________|\n");
        printf("|                                                                                                 |\n");
        printf("|       **                 **                  **            **          **             **        |\n");
        printf("|      fecha           idNotebook            Modelo        Marca        Tipo          Precio      |\n");
        printf("|_________________________________________________________________________________________________|\n");
        for(int i=0;i<tamTrabajo;i++)
        {
            indiceNotebook=buscarNotebookPorId(listaNotebook, tamNotebook, listaTrabajo[i].idNotebook);

            if(listaTrabajo[i].isEmpty==0 && indiceNotebook>=0)
            {
                if(listaTrabajo[i].idServicio==pedirIdServicio)
                {
                    printf("|    %02d/%02d/%d    ", listaTrabajo[i].fecha.dia, listaTrabajo[i].fecha.mes, listaTrabajo[i].fecha.anio);
                    mostrarNotebook(listaNotebook[indiceNotebook], tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                    hayUnServicio=1;
                }
            }
        }

        if(hayUnServicio!=1)
        {
            printf("\nNo hay notebooks con ese servicio...\n\n");
        }

        printf("|__________________|___________________|________________|___________|_____________|_______________|\n");

        todoOk=0;
    }

    return todoOk;
}
int informePedirUnaFechaMostrarLosServicioDeEsaFecha(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio)
{
    int todoOk=-1;
    eFecha auxFecha;
    int flagHayUnServicio=0;
    char descripcionServicio[25];

    if(listaTrabajo!=NULL && tamTrabajo>0 && listaNotebook!=NULL && tamNotebook>0 && listaTipo>0 && tamTipo>0 && listaMarca!=NULL && tamMarca>0 && listaServicio!=NULL && tamServicio>0)
    {
        system("cls");
        mostrarTrabajos(listaTrabajo, tamTrabajo, listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);

        printf("\n   ______________________________________________________________________________________ \n");
        printf("  |                                                                                      |\n");
        printf("  |                  ***Informe trabajo pedir fecha y mostrar servicios***               |\n");
        printf("  |______________________________________________________________________________________|\n\n");

        fechaPedirVerificarFecha(&auxFecha);

        printf("\nLos trabajos que se realizados en la fecha %02d/%02d/%d son:\n", auxFecha.dia, auxFecha.mes, auxFecha.anio);

        printf(" ________________ \n");
        printf("|                |\n");
        printf("|  *Servicios*   |\n");
        printf("|________________|\n");

        for(int i=0;i<tamTrabajo;i++)
        {
            if(listaTrabajo[i].isEmpty==0)
            {
                if(listaTrabajo[i].fecha.dia==auxFecha.dia && listaTrabajo[i].fecha.mes==auxFecha.mes && listaTrabajo[i].fecha.anio==auxFecha.anio)
                {
                   cargarDescripcionServicio(listaServicio, tamServicio, listaTrabajo[i].idServicio, descripcionServicio);
                   printf("| %-14s |\n", descripcionServicio);
                   flagHayUnServicio=1;
                }
            }
        }
        printf("|________________|\n");


        if(flagHayUnServicio!=1)
        {
            printf("\nNo se realizaron servicios con la fecha: %02d/%02d/%d\n", auxFecha.dia, auxFecha.mes, auxFecha.anio);
        }

        todoOk=0;
    }

    return todoOk;
}
int informesTrabajo(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio)
{
    int todoOk=-1;
    char afirmacion;

    if(listaTrabajo!=NULL && tamTrabajo>0 && listaNotebook!=NULL && tamNotebook>0 && listaTipo>0 && tamTipo>0 && listaMarca!=NULL && tamMarca>0 && listaServicio!=NULL && tamServicio>0)
    {
        do
        {
            switch(menuInformesTrabajo())
            {
                case 1:
                    informePedirUnaNotebookMostrarTrabajos(listaTrabajo, tamTrabajo, listaNotebook,  tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);
                    break;
                case 2:
                    informePedirUnaNotebookSumarImporteServicio(listaTrabajo, tamTrabajo, listaNotebook,  tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);
                    break;
                case 3:
                    informePedirUnServicioMostrarNotebookDeEseServicioFecha(listaTrabajo, tamTrabajo, listaNotebook,  tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);
                    break;
                case 4:
                    informePedirUnaFechaMostrarLosServicioDeEsaFecha(listaTrabajo, tamTrabajo, listaNotebook,  tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo, listaServicio, tamServicio);
                    break;
                case 5:
                    ingresoChar(&afirmacion, "\nPresione S para salir del menu de informes trabajos (s/n): ");
                    break;
                default:
                    printf("\nError. Ingrese una opcion (1-5): \n\n");
                    break;
            }

        }while(afirmacion!='s');

        todoOk=0;
    }

    return todoOk;
}




































//Real Agustin 1°A, 11/5/2022

//Real Agustin 1°A, 23/5/2022
