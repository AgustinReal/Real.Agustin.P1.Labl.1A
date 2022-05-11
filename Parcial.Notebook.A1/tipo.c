#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "tipo.h"


int cargarDescripcionTipo(eTipo* listaTipo, int tamTipo, int idTipo, char descripcion[])
{
  int todoOK=-1;

  if(listaTipo!=NULL && tamTipo>0 && descripcion!=NULL)
  {
      for(int i=0;i<tamTipo;i++)
      {
          if(listaTipo[i].id==idTipo)
          {
             strcpy(descripcion, listaTipo[i].descripcion);
             break;
          }
      }
      todoOK=1;
  }

  return todoOK;
}
int mostrarTipos(eTipo* listaTipo, int tamTipo)
{
    int todoOk=-1;

    if(listaTipo!=NULL && tamTipo>0)
    {
           printf(" ____________________ \n");
           printf("|        |           |\n");
           printf("|  *ID*  |  *TIPOS*  |\n");
           printf("|________|___________|\n");
        for(int i=0;i<tamTipo;i++)
        {
           printf("|  %d  | %-10s|\n", listaTipo[i].id, listaTipo[i].descripcion);
        }
            printf("|________|___________|\n");
            todoOk=1;
    }

    return todoOk;
}


























//Real Agustin 1°A, 11/5/2022
