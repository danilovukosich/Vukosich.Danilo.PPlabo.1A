/*
 * eCliente.c
 *
 *  Created on: 26 oct. 2022
 *      Author: danil
 */

#ifndef ECLIENTE_C_
#define ECLIENTE_C_

#include "eCliente.h"


int CargarDescripcionCliente(eCliente clientes[], int sizeClientes, int idCliente, char nombreCliente[])
{
	int retorno=0;
	if(clientes!=NULL && sizeClientes>0 && nombreCliente!=NULL)
	{
		for(int i=0;i<sizeClientes;i++)
		{
			if(clientes[i].id==idCliente)
			{
				strcpy(nombreCliente,clientes[i].nombreCliente);
				break;

			}
		}
		retorno=1;
	}
	return retorno;
}

#endif /* ECLIENTE_C_ */
