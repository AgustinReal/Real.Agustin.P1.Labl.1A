#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "marca.h"


int cargarDescripcionMarca(eMarca* listaMarca, int tamMarca, int idMarca, char descripcion[])
{
  int todoOK=-1;

  if(listaMarca!=NULL && tamMarca>0 && descripcion!=NULL)
  {
      for(int i=0;i<tamMarca;i++)
      {
          if(listaMarca[i].id==idMarca)
          {
             strcpy(descripcion, listaMarca[i].descripcion);
             break;
          }
      }
      todoOK=1;
  }

  return todoOK;
}
int mostrarMarcas(eMarca* listaMarca, int tamMarca)
{
    int todoOk=-1;

    if(listaMarca!=NULL && tamMarca>0)
    {
           printf(" ______________________ \n");
           printf("|        |             |\n");
           printf("|  *ID*  |   *MARCAS*  |\n");
           printf("|________|_____________|\n");
        for(int i=0;i<tamMarca;i++)
        {
           printf("|  %d  |    %-7s  |\n", listaMarca[i].id, listaMarca[i].descripcion);
        }
            printf("|________|_____________|\n");
            todoOk=1;
    }

    return todoOk;
}






















//Real Agustin 1°A, 11/5/2022
