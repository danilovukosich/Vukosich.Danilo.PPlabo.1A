/*
 * eColor.c
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef ECOLOR_C_
#define ECOLOR_C_
#include "eColor.h"

int MostrarColores(eColor listaColores[], int size)
{

	 int retorno = 0;

	 if(listaColores != NULL && size > 0)
	 {

		printf("---- Lista de Colores ----\n\n");
		printf("|  Id  |   Nombre   |\n");

		for(int i = 0 ; i < size ; i++)
		{

			printf(" %4d %10s\n", listaColores[i].id, listaColores[i].nombre);

		}

	 }

	 return retorno;
}

int CargarNombreColor(eColor listaColores[], int sizeColores, int idColor, char nombre[])
{
	int retorno=0;
	if(listaColores!=NULL && sizeColores>0 && nombre!=NULL)
	{
		for(int i=0;i<sizeColores;i++)
		{
			if(listaColores[i].id==idColor)
			{
				strcpy(nombre,listaColores[i].nombre);
				break;

			}
		}
		retorno=1;
	}
	return retorno;
}


#endif /* ECOLOR_C_ */
