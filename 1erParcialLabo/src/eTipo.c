/*
 * eTipo.c
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef ETIPO_C_
#define ETIPO_C_
#include "eTipo.h"

int MostrarTipos(eTipo listaTipos[], int size)
{

	 int retorno = 0;

	 if(listaTipos != NULL && size > 0)
	 {

		printf("---- Lista de Tipos ----\n\n");
		printf("| Id |  Descripcion  |\n");

		for(int i = 0 ; i < size ; i++)
		{

			printf(" %4d %10s\n", listaTipos[i].id, listaTipos[i].descripcion);

		}

	 }

	 return retorno;
}


int CargarDescripcionTipo(eTipo tipos[], int sizeTipos, int idTipo, char descripcion[])
{
	int retorno=0;
	if(tipos!=NULL && sizeTipos>0 && descripcion!=NULL)
	{
		for(int i=0;i<sizeTipos;i++)
		{
			if(tipos[i].id==idTipo)
			{
				strcpy(descripcion,tipos[i].descripcion);
				break;

			}
		}
		retorno=1;
	}
	return retorno;
}

#endif /* ETIPO_C_ */
