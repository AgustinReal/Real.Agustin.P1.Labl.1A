#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

#endif // FECHA_H_INCLUDED

/** \brief Esta funcion permite el ingreso de una fecha y verifica los meses, dias y añanios con el calendario.
 *
 * \param fecha eFecha*: La fecha ingresada por el usuario a validar.
 * \return int: Esto retorna 2 posibles casos -1 o 0: 0 si pudo realiazar la funcion o -1 si no pudo realizarlo.
 *
 */
int fechaPedirVerificarFecha(eFecha* fecha);
