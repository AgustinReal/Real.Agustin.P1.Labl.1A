#ifndef HARDCODEO_H_INCLUDED
#include "notebook.h"
#include "trabajo.h"
#define HARDCODEO_H_INCLUDED



#endif // HARDCODEO_H_INCLUDED

/** \brief Esta funcion: Realiza el hardcodeo de las notebook ingresando datos.
 *
 * \param arrayNotebook[] eNotebook:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array Notebook(Longitud de la lista).
 * \param cantidadACargar int: Es la cantidad de Ids que se van a cagar.
 * \param pIdNotebook int*: Incrementador de los ids.
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int harcodearNotebooks(eNotebook arrayNotebook[], int tamNotebook, int cantidadACargar, int* pIdNotebook);

/** \brief Esta funcion: Realiza el hardcodeo de los trabajos ingresando datos.
 *
 * \param listaTrabajo[] eTrabajo:Es el array trabajos (Lista).
 * \param tamTrabajo int: Es size del array trabajos(Longitud de la lista).
 * \param cantidad int: Es la cantidad de Ids que se van a cagar.
 * \param contadorIdTrabajos int*: Incrementador de los ids.
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int hardcodearTrabajos(eTrabajo listaTrabajo[], int tamTrabajo, int cantidad, int* contadorIdTrabajos);
