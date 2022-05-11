#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eMarca;

#endif // MARCA_H_INCLUDED

/** \brief : Recorre la lista marca mediante un for y carga la descripcion de la estructura marca que coincida con el id recibido como parametro.
 *
 * \param listaMarca eMarca*:Es el array Marcas (Lista Marcas).
 * \param tamMarca int:Es size del array Marcas (Longitud de la lista Marcas).
 * \param idMarca int: Es el ID que va comparar o buscar si coincide con el.
 * \param descripcion[] char: Es el array de chars donde se va copiar el contenido de la cadena
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int cargarDescripcionMarca(eMarca* listaMarca, int tamMarca, int idMarca, char descripcion[]);

/** \brief Esta funcion: Recorre la lista Marcas mediante un for y muestra todas las Marcas disponibles para que el usuario elija uno atravez de su id.
 *
 * \param listaMarca eMarca*:Es el array Marcas (Lista Marcas).
 * \param tamMarca int:Es size del array Marcas (Longitud de la lista Marcas).
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int mostrarMarcas(eMarca* listaMarca, int tamMarca);















































//Real Agustin 1°A, 11/5/2022
