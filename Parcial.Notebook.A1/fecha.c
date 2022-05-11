#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

int fechaPedirVerificarFecha(eFecha* fecha)
{
	int error=-1;

    printf("\nIngrese la fecha (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);

    while(error==-1)
    {
        if(fecha->anio>=2000 && fecha->anio<=2022)
        {
            if(fecha->mes>=1 && fecha->mes<=12)
            {
                switch(fecha->mes)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        if(fecha->dia<1 || fecha->dia>31)
                        {
                            printf("Dia invalido para el mes %0d. Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                            fflush(stdin);
                            scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                        }
                        else
                        {
                            error=0;
                        }
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if(fecha->dia<1 || fecha->dia>30)
                        {
                            printf("Dia invalido para el mes %0d. Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                            fflush(stdin);
                            scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                        }
                        else
                        {
                            error=0;
                        }
                        break;
                    case 2:
                        if(fecha->anio%4==0 || (fecha->anio%100!=0 && fecha->anio%400==0))
                        {
                            if(fecha->dia<1 || fecha->dia>29)
                            {
                               printf("Dia invalido para el mes %0d. Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                               fflush(stdin);
                               scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                            }
                            else
                            {
                                error=0;
                            }
                        }
                        else
                        {
                            if(fecha->dia<1 || fecha->dia>28)
                            {
                               printf("Dia invalido para el mes %0d. Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                               fflush(stdin);
                               scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                            }
                            else
                            {
                                error=0;
                            }
                        }
                        break;
                }
            }
            else
            {
                printf("Mes invalido. Ingrese la fecha (DD/MM/AAAA): ");
                fflush(stdin);
                scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
            }
        }
        else
        {
            printf("Anio invalido. Ingrese la fecha (DD/MM/AAAA): ");
            fflush(stdin);
            scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
        }
    }
    return error;

}
