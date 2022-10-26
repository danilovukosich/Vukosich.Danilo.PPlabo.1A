/*
 * eServicio.c
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef ESERVICIO_C_
#define ESERVICIO_C_
#include "eServicio.h"

int MostrarServicios(eServicio listaServicios[], int size)
{

	 int retorno = 0;

	 if(listaServicios != NULL && size > 0)
	 {

		printf("---- Lista de Servicios ----\n\n");
		printf("| Id |  Descripcion  |  Precio |\n");

		for(int i = 0 ; i < size ; i++)
		{

			printf("%5d %10s        %.2f\n", listaServicios[i].id, listaServicios[i].descripcion, listaServicios[i].precio);

		}

	 }

	 return retorno;
}

int CargarDescripcionServicio(eServicio servicios[], int sizeServicios, int idServicios, char descripcion[])
{
	int retorno=0;

	if(servicios!=NULL && sizeServicios>0 && descripcion!=NULL)
	{
		for(int i =0;i<sizeServicios;i++)
		{
			if(servicios[i].id==idServicios)
			{
				strcpy(descripcion,servicios[i].descripcion);
				break;
			}
		}
		retorno=1;
	}
	return retorno;
}

#endif /* ESERVICIO_C_ */
