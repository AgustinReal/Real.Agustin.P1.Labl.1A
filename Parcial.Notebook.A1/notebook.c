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
                "|10-INFORMES NOTEBOOKS             |\n"
                "|11-INFORMES TRABAJOS              |\n"
                "|12-SALIR                          |\n"
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
int ordenamientoPorMarcaPrecio(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
    int todoOk=-1;
    eNotebook auxSwap;
    char descripcionA[20];
    char descripcionB[20];

    if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
    {

        for(int i=0;i<tamNotebook;i++)
        {
            for(int j=i+1;j<tamNotebook;j++)
            {

                cargarDescripcionMarca(listaMarca, tamMarca, listaNotebook[i].idMarca, descripcionA);
                cargarDescripcionMarca(listaMarca, tamMarca, listaNotebook[j].idMarca, descripcionB);

                if(strcmp(descripcionA, descripcionB)>0)
                {
                    auxSwap=listaNotebook[i];
                    listaNotebook[i]=listaNotebook[j];
                    listaNotebook[j]=auxSwap;
                }
                else if(strcmp(descripcionA, descripcionB)==0 && listaNotebook[i].precio < listaNotebook[j].precio)
                {
                    auxSwap=listaNotebook[i];
                    listaNotebook[i]=listaNotebook[j];
                    listaNotebook[j]=auxSwap;
                }
            }
        }

        todoOk=0;
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
        ordenamientoPorMarcaPrecio(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
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
int menuInformesNotebook()
{
    int opcion;

    printf(" ________________________________________________________________________________________________ \n"
           "|                                                                                                |\n"
           "|                                   MENU PRINCIPAL INFORMES                                      |\n"
           "|                                    SERVICIO DE NOTEBOOKS                                       |\n"
           "|________________________________________________________________________________________________|\n"
           "|                                                                                                |\n"
           "|1-INFORME MOSTRAR NOTEBOOKS DEL TIPO SELECIONADO POR EL USUARIO.                                |\n"
           "|2-INFORME MOSTRAR NOTEBOOKS DE LA MARCA SELECIONADO.                                            |\n"
           "|3-INFORME MOSTRAR LA O LAS NOTEBOOKS MAS BARATA.                                                |\n"
           "|4-INFORME MOSTRAR UN LISTADO DE NOTEBOOKS SEPARADO POR MARCA.                                   |\n"
           "|5-INFORME ELEGIR UN TIPO Y MARCA Y CONTAR CUANTAS NOTEBOOKS HAY DE ESE TIPO Y ESA MARCA.        |\n"
           "|6-INFORME MOSTRAR LA O LAS MARCAS MAS ELEGIDA POR LOS CLIENTES.                                 |\n"
           "|7-SALIR                                                                                         |\n"
           "|________________________________________________________________________________________________|\n");

    printf("Usted eligio: ");
    scanf("%d", &opcion);

    return opcion;
}
int informeMostrarTipoNotebookSeleccionadoPorElUsuario(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
    int todoOk=-1;
    int idTipoSeleccionada;
    char descripcionTipo[20];
    int flagHayEseTipo=0;

    if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
    {
        system("cls");
        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |                     ***Informe Tipo notebook selecionado***                        |\n");
        printf("  |____________________________________________________________________________________|\n\n");

        mostrarTipos(listaTipo, tamTipo);
        ingresoEntero(&idTipoSeleccionada, "\nIngrese el tipo de notebook (5000-5003): ", "Error. Ingrese el tipo de notebook (5000-5003):", 5000, 5003);
        cargarDescripcionTipo(listaTipo, tamTipo, idTipoSeleccionada, descripcionTipo);

        printf(" ______________________________________________________________________________ \n");
        printf("|                                                                              |\n");
        printf("|                     ***Lista Notebooks con el tipo %-9s***              |\n", descripcionTipo);
        printf("|______________________________________________________________________________|\n");
        printf("|                                                                              |\n");
        printf("|        **                 **            **           **            **        |\n");
        printf("|   idNotebook            Modelo         Marca        Tipo          Precio     |\n");
        printf("|______________________________________________________________________________|\n");

        for(int i=0;i<tamNotebook;i++)
        {
            if(listaNotebook[i].isEmpty==0 && listaNotebook[i].idTipo==idTipoSeleccionada)
            {
                mostrarNotebook(listaNotebook[i], tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                flagHayEseTipo=1;
            }
        }

        if(flagHayEseTipo!=1)
        {
            printf("No se ham ingresado notebooks de ese tipo %s\n", descripcionTipo);
        }
        printf("|___________________|________________|___________|_____________|_______________|\n");

        todoOk=0;
    }

    return todoOk;
}
int informeMostrarMarcaNotebookSeleccionadoPorElUsuario(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
    int todoOk=-1;
    int idMarcaSeleccionada;
    char descripcionMarca[20];
    int flagHayEsaMarca=0;

    if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
    {
        system("cls");
        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |                    ***Informe Marca notebook selecionado***                        |\n");
        printf("  |____________________________________________________________________________________|\n\n");

        mostrarMarcas(listaMarca, tamMarca);
        ingresoEntero(&idMarcaSeleccionada, "\nIngrese la marca de la notebook (1000-1003): ", "Error.Ingrese la marca de la notebook (1000-1003): ", 1000, 1003);
        cargarDescripcionMarca(listaMarca, tamMarca, idMarcaSeleccionada, descripcionMarca);

        printf(" ______________________________________________________________________________ \n");
        printf("|                                                                              |\n");
        printf("|                     ***Lista Notebooks con la marca %-6s***                |\n", descripcionMarca);
        printf("|______________________________________________________________________________|\n");
        printf("|                                                                              |\n");
        printf("|        **                 **            **           **            **        |\n");
        printf("|   idNotebook            Modelo         Marca        Tipo          Precio     |\n");
        printf("|______________________________________________________________________________|\n");

        for(int i=0;i<tamNotebook;i++)
        {
            if(listaNotebook[i].isEmpty==0 && listaNotebook[i].idMarca==idMarcaSeleccionada)
            {
                mostrarNotebook(listaNotebook[i], tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                flagHayEsaMarca=1;
            }
        }

        if(flagHayEsaMarca!=1)
        {
            printf("No se ham ingresado notebooks de la marca %s\n", descripcionMarca);
        }
        printf("|___________________|________________|___________|_____________|_______________|\n");

        todoOk=0;
    }

    return todoOk;
}
int informeMostrarNotebooksMasBaratas(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
   int todoOk=-1;
   float menorPrecio;
   int flagMenorPrecio=0;

   if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
   {
        system("cls");
        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |                        ***Informe notebooks mas baratas***                         |\n");
        printf("  |____________________________________________________________________________________|\n\n");

        for(int i=0;i<tamNotebook;i++)
        {
           if(listaNotebook[i].isEmpty==0)
           {
                if(flagMenorPrecio==0 || listaNotebook[i].precio<menorPrecio)
                {
                    menorPrecio=listaNotebook[i].precio;
                    flagMenorPrecio=1;
                }
           }
        }

        printf("El menor precio es $%.2f y la notebook es:\n\n", menorPrecio);

        printf(" ______________________________________________________________________________ \n");
        printf("|                                                                              |\n");
        printf("|                       ***Lista Notebook mas baratas***                       |\n");
        printf("|______________________________________________________________________________|\n");
        printf("|                                                                              |\n");
        printf("|        **                 **            **           **            **        |\n");
        printf("|   idNotebook            Modelo         Marca        Tipo          Precio     |\n");
        printf("|______________________________________________________________________________|\n");

        for(int i=0;i<tamNotebook;i++)
        {
            if(listaNotebook[i].precio==menorPrecio && listaNotebook[i].isEmpty==0)
            {
                mostrarNotebook(listaNotebook[i], tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
            }
        }
        printf("|___________________|________________|___________|_____________|_______________|\n");

        todoOk=0;
   }
   return todoOk;
}
int informeListadoNotebookSeparadasPorMarca(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
   int todoOk=-1;
   int flagHayMarca;

   if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
   {
       system("cls");
       printf("\n   ____________________________________________________________________________________ \n");
       printf("  |                                                                                    |\n");
       printf("  |                 ***Informe Listado notebooks separadas marcas***                   |\n");
       printf("  |____________________________________________________________________________________|\n\n");

       for(int i=0;i<tamMarca;i++)
       {
            printf("La marca notebook: %s\n\n", listaMarca[i].descripcion);

            printf(" ______________________________________________________________________________ \n");
            printf("|                                                                              |\n");
            printf("|                 ***Lista Notebooks con la marca %-6s***                    |\n", listaMarca[i].descripcion);
            printf("|______________________________________________________________________________|\n");
            printf("|                                                                              |\n");
            printf("|        **                 **            **           **            **        |\n");
            printf("|   idNotebook            Modelo         Marca        Tipo          Precio     |\n");
            printf("|______________________________________________________________________________|\n");
            flagHayMarca=1;
           for(int n=0;n<tamNotebook;n++)
           {
              if(listaNotebook[n].isEmpty==0 && listaNotebook[n].idMarca==listaMarca[i].id)
              {
                  mostrarNotebook(listaNotebook[n], tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                  flagHayMarca=0;
              }
           }

           if(flagHayMarca!=0)
           {
                printf("\nNo se han ingresado notebooks con la Marca: %s \n\n", listaMarca[i].descripcion);
           }

           printf("|___________________|________________|___________|_____________|_______________|\n\n");


       }
       todoOk=0;
   }

   return todoOk;
}
int informeCantidadNotebookPorTipoMarcaElegida(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
   int todoOk=-1;
   int idTipoSeleccionada;
   int idMarcaSeleccionada;
   char descripcionTipo[20];
   char descripcionMarca[20];
   int cantidadNotebooks=0;
   int flagHayNotebook=0;

   if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
   {
        system("cls");
        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |         ***Informe cantidad de notebooks de una marca y tipo selecionado***        |\n");
        printf("  |____________________________________________________________________________________|\n\n");

        mostrarNotebooks(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
        printf("\n\n");

        mostrarTipos(listaTipo, tamTipo);
        ingresoEntero(&idTipoSeleccionada, "Ingrese el tipo de notebook (5000-5003): ", "Error. Ingrese el tipo de notebook (5000-5003):", 5000, 5003);
        cargarDescripcionTipo(listaTipo, tamTipo, idTipoSeleccionada, descripcionTipo);

        mostrarMarcas(listaMarca, tamMarca);
        ingresoEntero(&idMarcaSeleccionada, "Ingrese la marca de la notebook (1000-1003): ", "Error.Ingrese la marca de la notebook (1000-1003): ", 1000, 1003);
        cargarDescripcionMarca(listaMarca, tamMarca, idMarcaSeleccionada, descripcionMarca);


        printf(" ______________________________________________________________________________ \n");
        printf("|                                                                              |\n");
        printf("|           ***Lista Notebooks con la tipo %s y con la marca %-6s***       |\n", descripcionTipo, descripcionMarca);
        printf("|______________________________________________________________________________|\n");
        printf("|                                                                              |\n");
        printf("|        **                 **            **           **            **        |\n");
        printf("|   idNotebook            Modelo         Marca        Tipo          Precio     |\n");
        printf("|______________________________________________________________________________|\n");
        for(int i=0;i<tamNotebook;i++)
        {
            if(listaNotebook[i].idMarca==idMarcaSeleccionada && listaNotebook[i].idTipo==idTipoSeleccionada && listaNotebook[i].isEmpty==0)
            {
                cantidadNotebooks++;
                mostrarNotebook(listaNotebook[i], tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                flagHayNotebook=1;
            }
        }

        printf("|___________________|________________|___________|_____________|_______________|\n\n");

        if(flagHayNotebook==1)
        {
            printf("\nLa cantidad de notebooks del tipo %s y de la marca %s son: %d\n\n", descripcionTipo, descripcionMarca, cantidadNotebooks);
        }
        else
        {
            printf("No se ham ingresado notebooks del tipo %s y de la marca %s selecionado:..\n", descripcionTipo, descripcionMarca);
        }

        todoOk=0;
   }

   return todoOk;
}
int informeMarcaMasElegida(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
    int todoOk=-1;
    int arrayContadoresMarca[4]={0, 0, 0, 0};
    int marcaMasElegida;
    int flagMarcaMasElegida=0;

    if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
   {
        system("cls");
        printf("\n   ____________________________________________________________________________________ \n");
        printf("  |                                                                                    |\n");
        printf("  |                     ***Informe marca de notebook mas elegida***                    |\n");
        printf("  |____________________________________________________________________________________|\n\n");

        mostrarNotebooks(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);

        for(int m=0;m<tamMarca;m++)
        {
            for(int n=0;n<tamNotebook;n++)
            {
                if(listaNotebook[n].isEmpty==0 && listaMarca[m].id==listaNotebook[n].idMarca)
                {
                    arrayContadoresMarca[m]++;
                }
            }
        }

        for(int m=0;m<tamMarca;m++)
        {
            if(flagMarcaMasElegida==0 || arrayContadoresMarca[m]>marcaMasElegida)
            {
                marcaMasElegida=arrayContadoresMarca[m];
                flagMarcaMasElegida=1;
            }
        }

        for(int i=0; i<tamMarca; i++)
        {
            if(arrayContadoresMarca[i]==marcaMasElegida)
            {
                printf("\n\nLa marca de notebook mas elegida es: %s\n", listaMarca[i].descripcion);
            }
        }
        todoOk=0;
    }

    return todoOk;
}
int informesNotebooks(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo)
{
    int todoOk=-1;
    char afirmacion;

    if(listaNotebook!=NULL && tamNotebook>0 && listaMarca!=NULL && tamMarca>0 && listaTipo!=NULL && tamTipo>0)
    {
        do
        {
            switch(menuInformesNotebook())
            {
                case 1:
                    informeMostrarTipoNotebookSeleccionadoPorElUsuario(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                    break;
                case 2:
                    informeMostrarMarcaNotebookSeleccionadoPorElUsuario(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                    break;
                case 3:
                    informeMostrarNotebooksMasBaratas(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                    break;
                case 4:
                    informeListadoNotebookSeparadasPorMarca(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                    break;
                case 5:
                    informeCantidadNotebookPorTipoMarcaElegida(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                    break;
                case 6:
                    informeMarcaMasElegida(listaNotebook, tamNotebook, listaMarca, tamMarca, listaTipo, tamTipo);
                    break;
                case 7:
                    ingresoChar(&afirmacion, "\nPresione S para salir del menu de informes notebooks (s/n): ");
                    break;
                default:
                    printf("\nError. Ingrese una opcion (1-7): \n\n");
                    break;
            }
        }while(afirmacion!='s');

        todoOk=0;
    }

    return todoOk;
}



































//Real Agustin 1°A, 11/5/2022

//Real Agustin 1°A, 23/5/2022
