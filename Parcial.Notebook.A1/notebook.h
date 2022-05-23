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

//Ordenamiento por Marca y precio
/** \brief Esta funcion: Ordena el listado de las notebooks por Marca. Si las marcas son iguales esta ordenara por el Precio del producto de manera Ascendente.
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
int ordenamientoPorMarcaPrecio(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);

//Mostrar
/** \brief Esta funcion: Muestra los datos de un trabajo con sus despectivos campos.
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
/** \brief Esta funcion: Realiza un recorrido de la lista trabajos mediante un for, se verifica mediante un if si los trabajos estan activos
 *   (isEmpty==0) y imprime cada una de los trabajos activas del array trabajo (La lista de trabajos).
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

//Informes
/** \brief Esta funcion: Es el menu principal de informes Notebook.
 *
 * \return int: Esto retorna la opcion del menu informes elegida.
 *
 */
int menuInformesNotebook();

/** \brief Esta funciom: El usuario pide un Tipo: ("Gamer", "Disenio", "UltraBook", "Normalita") y le mostramos todas las notebook de esa categoria del tipo
 *  seleccionado por el usuario y si no se ha ingresado ese Tipo, se lo comunicamos al usuario mediante un printf.
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
int informeMostrarTipoNotebookSeleccionadoPorElUsuario(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);

/** \brief Esta funciom: El usuario pide una Marca: ("Compaq", "Asus", "Acer", "HP") y le mostramos todas las notebook de esa categoria de la marca
 *  seleccionado por el usuario y si no se ha ingresado esa Marca, se lo comunicamos al usuario mediante un printf.
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
int informeMostrarMarcaNotebookSeleccionadoPorElUsuario(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);

/** \brief Esta funcion: Recorre la lista Notebooks y mediante una bandera se queda con el precio mas barato y luego volvemos a recorre la lista y nos quedamos
 *  con todas las notebook que tenga el menor precio encontrado anteriormente y se muestra tal notebooks.
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
int informeMostrarNotebooksMasBaratas(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);

/** \brief Esta funcion: Realiza un listado de notebooks activas (isEmpty==0), y por las Marcas: ("Compaq", "Asus", "Acer", "HP") y separandolas cada una
 *   con su Marca despectivamente.
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
int informeListadoNotebookSeparadasPorMarca(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);

/** \brief Esta funcion: Se encarga de contar la cantidad de notebooks que hay cuando el usuario ingresa un Tipo: ("Gamer", "Disenio", "UltraBook", "Normalita") y
 *  una Marca: ("Compaq", "Asus", "Acer", "HP"), solo contando si las 2 cosas solicitadas al usurio coinciden. Si usurio elije un tipo y marca y no se encuentra activo
 *  (En la lista de notebooks), se le informara mediante un printf que no se ha ingresado lo que el solicito.
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
int informeCantidadNotebookPorTipoMarcaElegida(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);

/** \brief Esta funcion: Recorro la lista Marcas y ademas la lista notebooks y por cada marca cuento la cantidad de notebook ingresadas, despues vuelvo a recorrer la lista
 *  Marcas: ("Compaq", "Asus", "Acer", "HP") y comparo el array de contadores de cada Marca y mediante una bandera me quedo con la cantidad mayor. Finalmente vuelvo a recorer la lista
 *  de Marcas y me quedo con las marcas que tiene la misca cantidad que "la variable de bandera (cantidad mayor)" y lo muestro.
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
int informeMarcaMasElegida(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);

/** \brief Esta funcion: Es parte del menu de informes, tiene un switch con todas las opciones de los informes notebooks (cada opcion con su funcion pedida).
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
int informesNotebooks(eNotebook* listaNotebook, int tamNotebook, eMarca* listaMarca, int tamMarca, eTipo* listaTipo, int tamTipo);



































//Real Agustin 1°A, 11/5/2022

//Real Agustin 1°A, 23/5/2022
