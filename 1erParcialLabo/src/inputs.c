/*
 * inputs.c
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef INPUTS_C_
#define INPUTS_C_
#include "inputs.h"


int Utn_GetInt(int* numero, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int NumEntero;
	int retorno;

	if(numero != NULL && minimo<=maximo)
	{
		printf("%s", mensaje);
		scanf("%d",&NumEntero);
		while(NumEntero<minimo || NumEntero>maximo)
		{
			printf("%s", mensajeError);
			scanf("%d",&NumEntero);
		}

		*numero=NumEntero;
		retorno=1;
	}
	else
	{
		retorno=-1;
	}

	return retorno;
}

int Utn_GetFloat(float* numero, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	float NumEntero;
	int retorno;
	if(numero != NULL && minimo<=maximo)
	{
		printf("%s", mensaje);
		scanf("%f",&NumEntero);
		while(NumEntero<minimo || NumEntero>maximo)
		{
			printf("%s", mensajeError);
			scanf("%f",&NumEntero);
		}

		*numero=NumEntero;
		retorno=1;
	}
	else
	{
		retorno=-1;
	}

	return retorno;
}

int Utn_GetString(char string[], char mensaje[], char mensajeError[], int size)
{
	int retorno=0;
	char cadena[size];
	int x;

	if(string!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{

		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);
		x=strlen(cadena);
		strcpy(string,cadena);

		while(x>size)
		{

			printf("%s", mensajeError);
			fflush(stdin);
			gets(cadena);
			x=strlen(cadena);
			strcpy(string,cadena);
		}

		retorno=1;
	}

	return retorno;

}

#endif /* INPUTS_C_ */
