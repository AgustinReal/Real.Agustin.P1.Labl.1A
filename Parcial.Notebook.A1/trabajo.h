#ifndef TRABAJO_H_INCLUDED
#include "notebook.h"
#include "servicio.h"
#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

//ALTA
int inicializarTrabajo(eTrabajo* listaTrabajo, int tamTrabajo);
int buscarTrabajoLibre(eTrabajo* listaTrabajo, int tamTrabajo);
int altaTrabajo(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio, int* contadorIdTrabajo);


//Mostrar
int mostrarTrabajo(eTrabajo unTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio);
int mostrarTrabajos(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio);


















































//Real Agustin 1°A, 11/5/2022
