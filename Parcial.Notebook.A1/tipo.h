#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief Esta funcion: Recorre la lista tipo mediante un for y carga la descripcion de la estructura tipo que coincida con el id recibido como parametro.
 *
 * \param listaTipo eTipo*:Es el array tipos (Lista tipos).
 * \param tamTipo int:Es size del array tipo (Longitud de la lista tipo).
 * \param idTipo int: Es el ID que va comparar o buscar si coincide con el.
 * \param descripcion[] char: Es el array de chars donde se va copiar el contenido de la cadena
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int cargarDescripcionTipo(eTipo* listaTipo, int tamTipo, int idTipo, char descripcion[]);
/** \brief Esta funcion: Recorre la lista tipo mediante un for y muestra todas las tipos disponibles para que el usuario elija uno atravez de su id.
 *
 * \param listaTipo eTipo*:Es el array tipos (Lista tipos).
 * \param tamTipo int:Es size del array tipo (Longitud de la lista tipo).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int mostrarTipos(eTipo* listaTipo, int tamTipo);
