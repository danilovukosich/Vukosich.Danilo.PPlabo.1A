/*
 * eCliente.h
 *
 *  Created on: 26 oct. 2022
 *      Author: danil
 */

#ifndef ECLIENTE_H_
#define ECLIENTE_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char nombreCliente[20];
	char sexo;


}eCliente;


int CargarDescripcionCliente(eCliente clientes[], int sizeClientes, int idCliente, char nombreCliente[]);
#endif /* ECLIENTE_H_ */
