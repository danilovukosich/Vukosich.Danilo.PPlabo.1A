/*
 * eServicio.h
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef ESERVICIO_H_
#define ESERVICIO_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char descripcion[25];
	float precio;

}eServicio;

int MostrarServicios(eServicio listaServicios[], int size);

int CargarDescripcionServicio(eServicio servicios[], int sizeServicios, int idServicios, char descripcion[]);

#endif /* ESERVICIO_H_ */
