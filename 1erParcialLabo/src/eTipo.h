/*
 * eTipo.h
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef ETIPO_H_
#define ETIPO_H_
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
	int id;
	char descripcion[20];

}eTipo;

int MostrarTipos(eTipo listaTipos[], int size);

int CargarDescripcionTipo(eTipo tipos[], int sizeTipos, int idTipo, char descripcion[]);

#endif /* ETIPO_H_ */
