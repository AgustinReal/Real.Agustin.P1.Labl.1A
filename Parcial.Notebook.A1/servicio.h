#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
  int id;
  char descripcion[20];
  float precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief Esta funcion: Recorre la lista servicio mediante un for y carga la descripcion de la estructura servicio que coincida con el id recibido como parametro.
 *
 * \param listaServicio eServicio*:Es el array servicio (Lista servicios).
 * \param tamServicio int: Es size del array servicios (Longitud de la lista servicios).
 * \param idServicio int: Es el ID que va comparar o buscar si coincide con el.
 * \param descripcion[] char: Es el array de chars donde se va copiar el contenido de la cadena
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int cargarDescripcionServicio(eServicio* listaServicio, int tamServicio, int idServicio, char descripcion[]);
/** \brief Esta funcion: Recorre la lista Servicios mediante un for y muestra todas los Servicios disponibles para que el usuario elija uno atravez de su id.
 *
 * \param listaServicio eServicio*:Es el array servicio (Lista servicios).
 * \param tamServicio int: Es size del array servicios (Longitud de la lista servicios).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int mostrarServicios(eServicio* listaServicio, int tamServicio);
/** \brief Esta funcion: Busca mediante un for si el ID pasado por parametro se encuentra en el array servicio y esta activo. Si lo encuentra retorna
 *  el Indice de ese Id (Posicion actual) y mediante un break para la busqueda.
 *
 * \param listaServicio eServicio*: Es el array servicio (Lista servicios).
 * \param tamServicio int: Es size del array servicios (Longitud de la lista servicios).
 * \param idServicio int
 * \return int : Esto retorna 2 posibles casos -1 o el Indice encontrado: "Indice encontrado" Si Id pasado por parametro se encuentra en el array servicios
 *  o -1 si no pudo encontar un lugar.
 *
 */
int buscarServicioPorId(eServicio* listaServicio, int tamServicio, int idServicio);


















































//Real Agustin 1°A, 11/5/2022
