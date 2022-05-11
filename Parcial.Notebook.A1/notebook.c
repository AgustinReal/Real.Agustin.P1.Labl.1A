#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "notebook.h"
#include "inputs.h"
#include "marca.h"
#include "tipo.h"


int menu()
{
    int opcion;

       printf(" __________________________________ \n"
                "|                                  |\n"
                "|          MENU PRINCIPAL          |\n"
                "|       SERVICIO DE NOTEBOOK       |\n"
                "|__________________________________|\n"
                "|                                  |\n"
                "|1-ALTA NOTEBOOK                   |\n"
                "|2-MODIFICAR NOTEBOOK              |\n"
                "|3-BAJA NOTEBOOK                   |\n"
                "|4-LISTAR NOTEBOOK                 |\n"
                "|5-LISTAR MARCAS                   |\n"
                "|6-LISTAR TIPOS                    |\n"
                "|7-LISTAR SERVICIOS                |\n"
                "|8-ALTA TRABAJO                    |\n"
                "|9-LISTAR TRABAJOS                 |\n"
                "|10-SALIR                          |\n"
                "|__________________________________|\n");

        printf("Usted eligio: ");
        scanf("%d", &opcion);

  return  opcion;
}

int menuModificacion()
{
   int opcion;

   printf(" __________________________________ \n"
            "|                                  |\n"
            "|          MENU PRINCIPAL          |\n"
            "|       SERVICIO DE NOTEBOOK       |\n"
            "|__________________________________|\n"
            "|                                  |\n"
            "|1-MODIFICAR PRECIO                |\n"
            "|2-MODIFICAR TIPO                  |\n"
            "|3-SALIR                           |\n"
            "|__________________________________|\n");

    printf("Usted eligio: ");
    scanf("%d", &opcion);

  return  opcion;
}
int inicializarNotebook(eNotebook* listaNotebook, int tamNotebook)
{
    int todoOk=-1;

    if(listaNotebook!=NULL && tamNotebook>0)
    {
        for(int i=0;i<tamNotebook;i++)
        {
            listaNotebook[i].isEmpty=1;
        }
        todoOk=0;
    }

    return todoOk;
}
int buscarNotebookLibre(eNotebook* listaNotebook, int tamNotebook)
{
    int index=-1;

    if(listaNotebook!=NULL && tamNotebook>0)
    {
        for(int i=0;i<tamNotebook;i++)
        {
            if(listaNotebook[i].isEmpty==1)
            {
                index=i;
                break;
            }
        }
    }

    return index;
}
int buscarNotebookPorId(eNotebook* listaNotebook, int tamNotebook, int idEncontrado)
{
    int index=-1;

    if(listaNotebook!=NULL && tamNotebook>0)
    {
        for(int i=0;i<tamNotebook;i++)
        {
            if(listaNotebook[i].isEmpty==0 && listaNotebook[i].id==idEncontrado)
            {
                index=i;
                break;
            }
        }
    }

    return index;
}
int altaNotebook(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, int* pContadorId)
{
   int todoOk=-1;
   int index;
   char afirmacion;
   eNotebook auxNotebook;


   if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0 && pContadorId!=NULL)
   {
     index=buscarNotebookLibre(listaNotebook, tamNotebook);

     if(index!=-1)
     {
        system("cls");
        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |                                 ***Alta de Notebook***                             |\n");
        printf("  |____________________________________________________________________________________|\n\n");


        auxNotebook.id=*pContadorId;
        (*pContadorId)++;

        ingresoCadena(auxNotebook.modelo, "Ingrese el modelo de la notebook (max 20 letras): ", "Error. Ingrese el modelo de la notebook (max 20 letras): ", 20);

        mostrarMarcas(listaMarca, tamMarca);
        ingresoEntero(&auxNotebook.idMarca, "Ingrese la marca de la notebook (1000-1003): ", "Error.Ingrese la marca de la notebook (1000-1003): ", 1000, 1003);

        mostrarTipos(listaTipo, tamTipo);
        ingresoEntero(&auxNotebook.idTipo, "Ingrese el tipo de notebook (5000-5003): ", "Error. Ingrese el tipo de notebook (5000-5003):", 5000, 5003);

        ingresoFlotante(&auxNotebook.precio ,"Ingrese el precio de la notebook (50000-150000): ", "Error. Ingrese el precio de la notebook (50000-150000): ",50000.00, 150000.00);

        auxNotebook.isEmpty=0;

        printf(" ______________________________________________________________________________ \n");
        printf("|                                                                              |\n");
        printf("|                              ***Lista Notebooks***                           |\n");
        printf("|______________________________________________________________________________|\n");
        printf("|                                                                              |\n");
        printf("|        **                 **               **           **          **       |\n");
        printf("|   idNotebook            Modelo            Marca        Tipo        Precio    |\n");
        printf("|______________________________________________________________________________|\n");
        mostrarNotebook(auxNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
        printf("|___________________|________________|___________|_____________|_______________|\n");

        ingresoChar(&afirmacion, "\nPresione s para confirmar el alta de Notebook: ");
        if(afirmacion=='s' || afirmacion=='S')
        {
            printf("Se ha dado de alta correctamente...\n");
            listaNotebook[index]=auxNotebook;
        }
        else
        {
           (*pContadorId)--;
           auxNotebook.isEmpty=1;
           printf("\nSe cancelo el alta de la Notebook...\n\n");
        }
        todoOk=0;
     }
     else
     {
         printf("\nNo hay espacio en el sistema...\n\n");
     }

   }

   return todoOk;
}
int modificarNotebook(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
    int todoOk=-1;
    int buscarId;
    char confirmar;
    int indexEncontrado;
    int opcionMenu;

    if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
    {
       mostrarNotebooks(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
       ingresoEntero(&buscarId, "Ingrese el id que desea modificar: ", "Error. Ingrese el id que desea modificar: ", 1, 100);
       indexEncontrado=buscarNotebookPorId(listaNotebook, tamNotebook, buscarId);
       if(indexEncontrado>=0 && indexEncontrado<tamNotebook && listaNotebook[indexEncontrado].isEmpty==0)
       {
            printf(" ______________________________________________________________________________ \n");
            printf("|                                                                              |\n");
            printf("|                              ***Lista Notebooks***                           |\n");
            printf("|______________________________________________________________________________|\n");
            printf("|                                                                              |\n");
            printf("|        **                 **               **           **          **       |\n");
            printf("|   idNotebook            Modelo            Marca        Tipo        Precio    |\n");
            printf("|______________________________________________________________________________|\n");
            mostrarNotebook(listaNotebook[indexEncontrado], tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
            printf("|___________________|________________|___________|_____________|_______________|\n");

           ingresoChar(&confirmar, "\nPresione s para confirmar la modificacion (s/n): ");

           if(confirmar=='s' || confirmar=='S')
           {
              do
              {
                  opcionMenu=menuModificacion();
                  switch(opcionMenu)
                  {
                    case 1:
                        ingresoFlotante(&listaNotebook[indexEncontrado].precio ,"Ingrese el precio de la notebook (50000-150000): ", "Error. Ingrese el precio de la notebook (50000-150000): ",50000.00, 150000.00);
                        break;
                    case 2:
                        mostrarTipos(listaTipo, tamTipo);
                        ingresoEntero(&listaNotebook[indexEncontrado].idTipo, "Ingrese el tipo de notebook (5000-5003): ", "Error. Ingrese el tipo de notebook (5000-5003):", 5000, 5003);
                        break;
                    case 3:
                        printf("\nSaliendo del menu de modificaciones\n\n");
                        break;
                    default:
                        printf("Error. Ingrese una opcion (1-3): \n");
                        break;
                  }
              }while(opcionMenu!=3);
              if(opcionMenu<1 || opcionMenu>2)
              {
                printf(" ______________________________________________________________________________ \n");
                printf("|                                                                              |\n");
                printf("|                              ***Lista Notebooks***                           |\n");
                printf("|______________________________________________________________________________|\n");
                printf("|                                                                              |\n");
                printf("|        **                 **               **           **          **       |\n");
                printf("|   idNotebook            Modelo            Marca        Tipo        Precio    |\n");
                printf("|______________________________________________________________________________|\n");
                mostrarNotebook(listaNotebook[indexEncontrado], tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                printf("|___________________|________________|___________|_____________|_______________|\n");

                printf("\nEl Id de la notebook %d fue modificado...\n\n", buscarId);
              }
           }
           else
           {
               printf("\nSe cancelo la modificacion de la notebook...\n\n");
           }
           todoOk=0;
       }
       else
       {
            printf("\nNo se ha encontrado ese Id en el sistema...\n\n");
       }
    }

    return todoOk;
}
int BajaNotebook(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
    int todoOk=-1;
    int buscarId;
    char confirmar;
    int indexEncontrado;

    if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
    {
       mostrarNotebooks(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
       ingresoEntero(&buscarId, "Ingrese el id que desea dar de baja: ", "Error. Ingrese el id que desea dar de baja: ", 1, 100);
       indexEncontrado=buscarNotebookPorId(listaNotebook, tamNotebook, buscarId);
       if(indexEncontrado>=0 && indexEncontrado<tamNotebook && listaNotebook[indexEncontrado].isEmpty==0)
       {
            printf(" ______________________________________________________________________________ \n");
            printf("|                                                                              |\n");
            printf("|                              ***Lista Notebooks***                           |\n");
            printf("|______________________________________________________________________________|\n");
            printf("|                                                                              |\n");
            printf("|        **                 **               **           **          **       |\n");
            printf("|   idNotebook            Modelo            Marca        Tipo        Precio    |\n");
            printf("|______________________________________________________________________________|\n");
            mostrarNotebook(listaNotebook[indexEncontrado], tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
            printf("|___________________|________________|___________|_____________|_______________|\n");

           ingresoChar(&confirmar, "\nPresione s para confirmar la baja del sistema (s/n): ");

           if(confirmar=='s' || confirmar=='S')
           {
               printf("\nSe ha dado de baja correctamente el id: %d\n\n", buscarId);
               listaNotebook[indexEncontrado].isEmpty=1;
           }
           else
           {
               printf("\nSe cancelo la baja de la notebook...\n\n");
           }
           todoOk=0;
       }
       else
       {
            printf("\nNo se ha encontrado ese Id en el sistema...\n\n");
       }
    }

    return todoOk;
}
int mostrarNotebook(eNotebook unNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
    int todoOk=-1;
    char descripcionMarca[20];
    char descripcionTipo[20];

    if(tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
    {
        cargarDescripcionMarca(listaMarca, tamMarca, unNotebook.idMarca, descripcionMarca);
        cargarDescripcionTipo(listaTipo, tamTipo, unNotebook.idTipo, descripcionTipo);

        printf("|   %4d            |  %-13s |  %-8s |  %-10s |   %-9.2f   |\n",
                                unNotebook.id,
                                unNotebook.modelo,
                                descripcionMarca,
                                descripcionTipo,
                                unNotebook.precio);
        todoOk=0;
    }

    return todoOk;
}
int mostrarNotebooks(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
    int todoOk=-1;

    if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
    {
        printf(" ______________________________________________________________________________ \n");
        printf("|                                                                              |\n");
        printf("|                              ***Lista Notebooks***                           |\n");
        printf("|______________________________________________________________________________|\n");
        printf("|                                                                              |\n");
        printf("|        **                 **            **           **            **        |\n");
        printf("|   idNotebook            Modelo         Marca        Tipo          Precio     |\n");
        printf("|______________________________________________________________________________|\n");
        for(int i=0;i<tamNotebook;i++)
        {
            if(listaNotebook[i].isEmpty==0)
            {
                mostrarNotebook(listaNotebook[i], tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
            }
        }
        printf("|___________________|________________|___________|_____________|_______________|\n");
        todoOk=0;
    }

    return todoOk;
}




































//Real Agustin 1°A, 11/5/2022
