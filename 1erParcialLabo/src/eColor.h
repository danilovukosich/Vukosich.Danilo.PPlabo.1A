/*
 * eColor.h
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef ECOLOR_H_
#define ECOLOR_H_
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
	int id;
	char nombre[20];

}eColor;

int MostrarColores(eColor listaColores[], int size);


int CargarNombreColor(eColor listaColores[], int sizeColores, int idColor, char nombre[]);

#endif /* ECOLOR_H_ */
