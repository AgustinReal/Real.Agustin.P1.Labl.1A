#ifndef NOTEBOOK_H_INCLUDED
#include "marca.h"
#include "tipo.h"
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;

}eNotebook;

#endif // NOTEBOOK_H_INCLUDED
//Menus
/** \brief Esta funcion: Es el menu principal del Abm Notebook.
 *
 * \return int: Esto retorna la opcion del menu elegida.
 *
 */
int menu();

/** \brief Esta funcion: Es el menu de modificacion de las  Notebooks con las opciones de modificar el precio y el tipo.
 *
 * \return int: Esto retorna la opcion del menu elegida.
 *
 */
int menuModificacion();

//Alta/Modificacion/Baja
/** \brief Esta funcion: Inicializa la lista de notebooks (Array notebooks) en 1, es decir recorre la lista mediante
 *   un for limpia el array por si tiene basura.
 *
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int inicializarNotebook(eNotebook* listaNotebook, int tamNotebook);
/** \brief Esta funcion: Realiza la busqueda del primer espacio libre de una notebook mediante un for, esto se queda con la primer posicion libre  y
 *   mediante un break termina la busqueda y retorna la posicion libre.
 *
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \return int: Esto retorna 2 posibles casos -1 o la posicion libre: "la posicion libre" si pudo encontar un lugar o -1 si no pudo encontar un lugar.
 *
 */
int buscarNotebookLibre(eNotebook* listaNotebook, int tamNotebook);
/** \brief Esta funcion: Busca mediante un for si el ID pasado por parametro se encuentra en el array notebook y esta activo. Si lo encuentra retorna
 *  el Indice de ese Id (Posicion actual) y mediante un break para la busqueda.
 *
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param idEncontrado int: Es el Id que se va buscar si esta activo y si se encuentra en el array notebooks (Lista).
 * \return int: Esto retorna 2 posibles casos -1 o el Indice encontrado: "Indice encontrado" Si Id pasado por parametro se encuentra en el array notebooks
 *  o -1 si no pudo encontar un lugar.
 *
 */
int buscarNotebookPorId(eNotebook* listaNotebook, int tamNotebook, int idEncontrado);
/** \brief Esta funcion: Da de alta una notebook, primero busca un espacio libre en el sistema (Array notebooks) mediante la funcion "buscarNotebookLibre",
 *   Si hay lugar se ingresaran todos los campos de la struct en una varaible tipo "struct eNotebook AuxNotebook", con sus validaciones respectivas una vez cargado
 *   Se lo mostramos al usuario mediante la funcion "mostrarNotebook" y luego le pediremos una confirmacion (s/n): si pone S se dara de Alta y cambiara de estado
 *   el isEmpty=0 y el contador de Id aumentara un lugar (++) y pero si pone algo diferenre a S, se descartara el alta (isEmpty=1) y el contador id se descontara un lugar(--).
 *
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \param pContadorId int*: Es la variable de control que se encarga de llevar contador de los Ids (aumenta/disminuye).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int altaNotebook(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo, int* pContadorId);
/** \brief Esta funcion: Realiza una modificacion de una notebook ingresada. Al usuario le muestra la lista  notebooks mediante la funcion "mostrarNotebooks" y
 *   luego le pedimos al usuario que selecione el Id que desea modificar y mediante la funcion "buscarNotebookPorId" verificamos el id ingresado. Esto parte la funcion en 2 posibles casos.
 *   si no lo encontro se le imforma al usuario con un mensaje que no se encuentra el Id en el sistema o si lo encontro le pedimos una confirmacion si desea modificar es Id (s/n): si pone S,
 *   le mostrara un sudMenu y el usuario elige que modificar y cuando lo modifica se lo mostramos (id moficicado) o si pone algo diferente a S se cancela la modificacion.
 *
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int modificarNotebook(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);
/** \brief Esta funcion: Realiza una baja de una notebook ingresada. Al usuario le muestra la lista notebooks mediante la funcion "mostrarNotebooks" y
 *   luego le pedimos al usuario que selecione el Id que desea dar de baja y mediante la funcion "buscarNotebookPorId" verificamos el id ingresado.
 *   esto parte la funcion en 2 posibles casos. si no lo encontro se le imforma al usuariocon un mensaje que no se encuentra el Id en el sistema o si lo encontro le pedimos una confirmacion
 *   si desea dar de baja es Id (s/n): si pone S, el id cambiara de estado (isEmpty=1) o si no N o otros se descarta la dada de baja.
 *
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int BajaNotebook(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);

//Mostrar
/** \brief Esta funcion: Muestra los datos una notebook con sus despectivos campos.
 *
 * \param unNotebook eNotebook: Es una notebook que se imprimera todos sus campos.
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int mostrarNotebook(eNotebook unNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);
/** \brief Esta funcion: Realiza un recorrido de la lista notebooks mediante un for, se verifica mediante un if si las notebooks estan activas
 *   (isEmpty==0) y imprime cada una de las notebooks activas del array notebook (La lista de notebooks).
 *
 * \param listaNotebook eNotebook*:Es el array notebooks (Lista).
 * \param tamNotebook int: Es size del array notebook (Longitud de la lista).
 * \param listaMarca eMarca*: Es el array marcas (Lista marcas).
 * \param tamMarca int: Es size del array marca (Longitud de la lista marca).
 * \param listaTipo eTipo*: Es el array tipos (Lista tipos).
 * \param tamTipo int: Es size del array tipo (Longitud de la lista tipo).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int mostrarNotebooks(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);







































//Real Agustin 1°A, 11/5/2022
