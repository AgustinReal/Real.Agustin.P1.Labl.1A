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
 * \param tamServicio int:Es size del array servicios (Longitud de la lista servicios).
 * \param idServicio int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionServicio(eServicio* listaServicio, int tamServicio, int idServicio, char descripcion[]);
/** \brief
 *
 * \param listaServicio eServicio*
 * \param tamServicio int
 * \return int
 *
 */
int mostrarServicios(eServicio* listaServicio, int tamServicio);
/** \brief
 *
 * \param listaServicio eServicio*
 * \param tamServicio int
 * \param idServicio int
 * \return int
 *
 */
int buscarServicioPorId(eServicio* listaServicio, int tamServicio, int idServicio);


















































//Real Agustin 1°A, 11/5/2022
