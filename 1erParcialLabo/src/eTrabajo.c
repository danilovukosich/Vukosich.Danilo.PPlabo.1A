/*
 * eTrabajo.c
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef ETRABAJO_C_
#define ETRABAJO_C_
#include "eTrabajo.h"



int InicializarTrabajos(eTrabajo listaTrabajos[], int size)
{
	int retorno = 0;

	    if(listaTrabajos != NULL && size > 0)
	    {
	        for(int i = 0 ; i < size ; i++)
	        {
	        	listaTrabajos[i].isEmpty = 1;
	        }

	        retorno = 1;
	    }

	    return retorno;

}



void CargarTrabajo(eTrabajo trabajo[], eBicicleta listaBici[], int sizeBicicletas, eTipo listaTipos[], int sizeTipos,eColor listaColores[], int sizeColores, eServicio listaServicios[], int sizeServicios, eCliente listaClientes[], int sizeClientes)
{


	MostrarBicicletas(listaBici, sizeBicicletas, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
	Utn_GetInt(&trabajo->idBicicleta, "Ingrese un id de bicicleta: \n", "Ingrese un id de bicicleta valido: \n", 100, 200);

	MostrarServicios(listaServicios, sizeServicios);
	Utn_GetInt(&trabajo->idServicio, "Ingrese un id de servicios: \n", "Ingrese un id de servicios valido: \n", 20000, 20003);

	printf("Ingrese la fecha.\n");
	Utn_GetInt(&trabajo->fecha.dia, "Ingrese el dia: \n", "Ingrese un dia valido: \n", 1, 31);
	Utn_GetInt(&trabajo->fecha.mes, "Ingrese el mes: \n", "Ingrese un mes valido: \n", 1, 12);
	Utn_GetInt(&trabajo->fecha.anio, "Ingrese el anio: \n", "Ingrese un anio valido: \n", 2021, 2030);

	trabajo->isEmpty=0;

}

int BuscarLibreTrabajos(int* pIndice, eTrabajo listaTrabajos[], int size)
{

    int retorno = 0;
    int indice = -1;

    if(pIndice != NULL && listaTrabajos != NULL && size > 0)
    {

        for(int i = 0 ; i < size ; i++)
        {
            if( listaTrabajos[i].isEmpty)
            {
                indice = i;
                break;
            }
        }

        *pIndice = indice;

        retorno = 1;
    }

    return retorno;

}

int AltaTrabajos(int* pIdTrabajos, eTrabajo listaTrabajo[], int size, eBicicleta listaBici[], int sizeBicicletas, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos,eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{

    int retorno = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(pIdTrabajos != NULL && listaTrabajo != NULL && size > 0)
    {

        printf("Alta Trabajos\n\n");

        BuscarLibreTrabajos(&indice, listaTrabajo, size);

        if(indice == -1)
        {

            printf("No hay lugar.\n");

        }
        else
        {

            CargarTrabajo(&auxTrabajo, listaBici, sizeBicicletas, listaTipos, sizeTipos, listaColores, sizeColores, listaServicios, sizeServicios, listaClientes, sizeClientes);

            auxTrabajo.id = *pIdTrabajos;

            *pIdTrabajos = *pIdTrabajos + 1;

            listaTrabajo[indice] = auxTrabajo;
            retorno = 1;

        }


    }
    return retorno;
}




void MostrarTrabajo(eTrabajo listaTrabajos, eServicio listaServicios[], int sizeServicio)
{
	char descripcionServicio[20];

	CargarDescripcionServicio(listaServicios, sizeServicio, listaTrabajos.idServicio, descripcionServicio);
	printf("%5d        %4d            %10s     %2d/%2d/%4d\n", listaTrabajos.id, listaTrabajos.idBicicleta, descripcionServicio, listaTrabajos.fecha.dia, listaTrabajos.fecha.mes, listaTrabajos.fecha.anio);
}


void MostrarTrabajos(eTrabajo listaTrabajos[], int size, eServicio listaServicios[], int sizeServicio)
{
	printf("           -------LISTA TRABAJOS-------\n");
	printf("ID    |   ID-BICICLETA     |   SERVICIO   |  FECHA\n");
	printf("-----------------------------------------------------");

	if(listaTrabajos!=NULL && size>0 && listaServicios!=NULL && sizeServicio>0)
	{
		for(int i=0; i<size; i++)
		{
			if(listaTrabajos[i].isEmpty==0)
			{
				MostrarTrabajo(*listaTrabajos, listaServicios, sizeServicio);
			}
		}
	}
}

#endif /* ETRABAJO_C_ */
