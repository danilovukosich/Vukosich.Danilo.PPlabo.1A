/*
 * eTrabajo.h
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef ETRABAJO_H_
#define ETRABAJO_H_

#include "eFecha.h"
#include "eBicicleta.h"
#include "eServicio.h"


typedef struct
{
	int id;
	int idBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajo;

int InicializarTrabajos(eTrabajo listaTrabajos[], int size);

void CargarTrabajo(eTrabajo trabajo[], eBicicleta listaBici[], int sizeBicicletas, eTipo listaTipos[], int sizeTipos,eColor listaColores[], int sizeColores, eServicio listaServicios[], int sizeServicios, eCliente listaClientes[], int sizeClientes);

int BuscarLibreTrabajos(int* pIndice, eTrabajo listaTrabajos[], int size);

int AltaTrabajos(int* pIdTrabajos, eTrabajo listaTrabajo[], int size, eBicicleta listaBici[], int sizeBicicletas, eServicio listaServicios[], int sizeServicios, eTipo listaTipos[], int sizeTipos,eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

void MostrarTrabajo(eTrabajo listaTrabajos, eServicio listaServicios[], int sizeServicio);

void MostrarTrabajos(eTrabajo listaTrabajos[], int size, eServicio listaServicios[], int sizeServicio);

#endif /* ETRABAJO_H_ */
