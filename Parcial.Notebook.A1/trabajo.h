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
/** \brief Esta funcion: Inicializa la lista de trabajo (Array trabajos) en 1, es decir recorre la lista mediante
 *   un for limpia el array por si tiene basura.
 *
 * \param listaTrabajo eTrabajo*:Es el array trabajo (Lista trabajos).
 * \param tamTrabajo int: Es size del array trabajo (Longitud de la lista).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int inicializarTrabajo(eTrabajo* listaTrabajo, int tamTrabajo);
/** \brief Esta funcion: Realiza la busqueda del primer espacio libre de un trabajo mediante un for, esto se queda con la primer posicion libre  y
 *   mediante un break termina la busqueda y retorna la posicion libre.
 *
 * \param listaTrabajo eTrabajo*:Es el array trabajo (Lista trabajos).
 * \param tamTrabajo int: Es size del array trabajo (Longitud de la lista).
 * \return int: Esto retorna 2 posibles casos -1 o la posicion libre: "la posicion libre" si pudo encontar un lugar o -1 si no pudo encontar un lugar.
 *
 */
int buscarTrabajoLibre(eTrabajo* listaTrabajo, int tamTrabajo);
/** \brief Esta funcion: Da de alta una Trabajo, primero busca un espacio libre en el sistema (Array Trabajos) mediante la funcion "buscarTrabajoLibre",
 *   Si hay lugar se ingresaran todos los campos de la struct en una varaible tipo "struct eTrabajo auxTrabajo" primero de le mostraremos la lista de notebooks le pedimos que elija  una
 *   notebook y si esta coincide con el id solicitada se dara de alta esa misma con una fecha y um servico con sus validaciones respectivas una vez cargado
 *   Se lo mostramos al usuario mediante la funcion "mostrarTrabajo" y luego le pediremos una confirmacion (s/n): si pone S se dara de Alta y cambiara de estado
 *   el isEmpty=0 y el contador de Id aumentara un lugar (++) y pero si pone algo diferenre a S, se descartara el alta (isEmpty=1) y el contador id se descontara un lugar(--).
 *
 * \param listaTrabajo eTrabajo*:Es el array trabajo (Lista trabajos).
 * \param tamTrabajo int: Es size del array trabajo (Longitud de la lista).
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \param listaServicio eServicio*: Es el array servicio (Lista servicios).
 * \param tamServicio int: Es size del array servicio (Longitud de la lista servicio).
 * \param contadorIdTrabajo int*: Es la variable de control que se encarga de llevar contador de los Ids (aumenta/disminuye).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int altaTrabajo(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio, int* contadorIdTrabajo);


//Mostrar
/** \brief
 *
 * \param unTrabajo eTrabajo: Es un trabajo que se imprimera todos sus campos.
 * \param tamTrabajo int: Es size del array trabajo (Longitud de la lista).
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \param listaServicio eServicio*: Es el array servicio (Lista servicios).
 * \param tamServicio int: Es size del array servicio (Longitud de la lista servicio).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int mostrarTrabajo(eTrabajo unTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio);
/** \brief
 *
 * \param listaTrabajo eTrabajo*:Es el array trabajo (Lista trabajos).
 * \param tamTrabajo int: Es size del array trabajo (Longitud de la lista).
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \param listaServicio eServicio*: Es el array servicio (Lista servicios).
 * \param tamServicio int: Es size del array servicio (Longitud de la lista servicio).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int mostrarTrabajos(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio);

//Informes
/** \brief Esta funcion: Es el menu principal de informes trabajo.
 *
 * \return int: Esto retorna la opcion del menu informes elegida.
 *
 */
int menuInformesTrabajo();

/** \brief Esta funcion: Le solicitamos al usuario que ingrese una notebook que este activa y le mostramos una lista de todas las notebooks y el usuario elige cual de ellas
 *  quiere mostrar los trabajo de esa notebook. Si esta activa y esa notebook posee trabajos cargados, se le mostrara en pantalla. Pero si no posee ningun trabajo cargado
 *  se le informara al usuario con un printf.
 *
 * \param listaTrabajo eTrabajo*:Es el array trabajo (Lista trabajos).
 * \param tamTrabajo int: Es size del array trabajo (Longitud de la lista).
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \param listaServicio eServicio*: Es el array servicio (Lista servicios).
 * \param tamServicio int: Es size del array servicio (Longitud de la lista servicio).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int informePedirUnaNotebookMostrarTrabajos(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio);

/** \brief  Esta funcion: Le solicitamos al usuario que ingrese una notebook que este activa y le mostramos una lista de todas las notebooks y el usuario elige cual de ellas
 *  quiere mostra su acumulacion de importes por los trabajos cargados de dicha notebook. Si esta activa y esa notebook posee trabajos cargados, se le mostrara en pantalla con la cantidad de
 * importes totales. Pero si no posee ningun trabajo cargado se le informara al usuario con un printf.
 *
 * \param listaTrabajo eTrabajo*:Es el array trabajo (Lista trabajos).
 * \param tamTrabajo int: Es size del array trabajo (Longitud de la lista).
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \param listaServicio eServicio*: Es el array servicio (Lista servicios).
 * \param tamServicio int: Es size del array servicio (Longitud de la lista servicio).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int informePedirUnaNotebookSumarImporteServicio(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio);

/** \brief Esta funcion: Le solicitamos al usuario que ingrese un servicio: (Bateria, Display, Mantenimiento, Fuente) y le mostraremos un listado de notebooks activas con dicho servicio
 *  y ademas le mostraremos la fecha de cada servicio de la notebook que se cargo en el alta trabajo.
 *
 * \param listaTrabajo eTrabajo*:Es el array trabajo (Lista trabajos).
 * \param tamTrabajo int: Es size del array trabajo (Longitud de la lista).
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \param listaServicio eServicio*: Es el array servicio (Lista servicios).
 * \param tamServicio int: Es size del array servicio (Longitud de la lista servicio).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int informePedirUnServicioMostrarNotebookDeEseServicioFecha(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio);

/** \brief Esta funcion: Le solicitaremos una fecha al usuario y verificamos que ese trabajo este activo y mediante un for recorremos la lista trabajos y con un if comparamos los dd/mm/anio
 *   de la fecha ingresada y si coincide con un servicio ingresado y esta activo en la lista trabajo. Este se le mostrara todos los servicios de dicha fecha y si no hay ningun servicio este
 *   se le imformara al usuario mediante un printf.
 *
 * \param listaTrabajo eTrabajo*
 * \param tamTrabajo int
 * \param listaNotebook eNotebook*
 * \param tamNotebook int
 * \param listaMarca eMarca*
 * \param tamMarca int
 * \param listaTipo eTipo*
 * \param tamTipo int
 * \param listaServicio eServicio*
 * \param tamServicio int
 * \return int
 *
 */
int informePedirUnaFechaMostrarLosServicioDeEsaFecha(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio);

/** \brief Esta funcion: Es parte del menu de informes trabajos, tiene un switch con todas las opciones de los informes trabajos (cada opcion con su funcion pedida).
 *
 * \param listaTrabajo eTrabajo*:Es el array trabajo (Lista trabajos).
 * \param tamTrabajo int: Es size del array trabajo (Longitud de la lista).
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \param listaServicio eServicio*: Es el array servicio (Lista servicios).
 * \param tamServicio int: Es size del array servicio (Longitud de la lista servicio).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int informesTrabajo(eTrabajo* listaTrabajo, int tamTrabajo, eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, eServicio* listaServicio, int tamServicio);



















































//Real Agustin 1°A, 11/5/2022

//Real Agustin 1°A, 23/5/2022
