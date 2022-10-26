/*
 * informes.c
 *
 *  Created on: 26 oct. 2022
 *      Author: danil
 */

#ifndef INFORMES_C_
#define INFORMES_C_

#include "informes.h"

void InformarBicicletasColorSeleccionado(eColor listaColores[], int sizeColores, eBicicleta listaBicicleta[], int sizeBicicleta, eTipo listaTipos[], int sizeTipos, eCliente listaClientes[], int sizeClientes)
{
	int idColores;

	if(listaColores!=NULL && sizeColores>0 && listaBicicleta!=NULL && sizeBicicleta>0 && listaTipos!=NULL && sizeTipos>0 && listaClientes!=NULL && sizeColores>0)
	{
		MostrarColores(listaColores, sizeColores);
		Utn_GetInt(&idColores, "Ingrese un ID: \n", "Ingrese un ID valido: \n", 5000, 5004);

		printf("           -------LISTA BICICLETAS POR COLOR-------\n");
		printf("  ID    |    MARCA      |    TIPO    |   COLOR   |   MATERIAL  | CLIENTE |\n");
		for(int i=0; i<sizeBicicleta; i++)
		{
			if(listaBicicleta[i].idColor==idColores && listaBicicleta[i].isEmpty==0)
			{
				MostrarBicicleta(listaBicicleta[i], listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
			}
		}
	}

}

void InformarBicicletasTipoSeleccionado(eColor listaColores[], int sizeColores, eBicicleta listaBicicleta[], int sizeBicicleta, eTipo listaTipos[], int sizeTipos, eCliente listaClientes[], int sizeClientes)
{
	int idTipos;

	if(listaColores!=NULL && sizeColores>0 && listaBicicleta!=NULL && sizeBicicleta>0 && listaTipos!=NULL && sizeTipos>0 && listaClientes!=NULL && sizeColores>0)
	{
		MostrarTipos(listaTipos, sizeTipos);
		Utn_GetInt(&idTipos, "Ingrese un ID: \n", "Ingrese un ID valido: \n", 1000, 1003);

		printf("           -------LISTA BICICLETAS POR TIPO-------\n");
		printf("  ID    |    MARCA      |    TIPO    |   COLOR   |   MATERIAL  | CLIENTE |\n");
		for(int i=0; i<sizeBicicleta; i++)
		{
			if(listaBicicleta[i].idTipo==idTipos && listaBicicleta[i].isEmpty==0)
			{
				MostrarBicicleta(listaBicicleta[i], listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
			}
		}
	}

}

void InformarCantidadMasMaterial(eColor listaColores[], int sizeColores, eBicicleta listaBicicleta[], int sizeBicicleta, eTipo listaTipos[], int sizeTipos, eCliente listaClientes[], int sizeClientes)
{
	int contadorCarbono=0;
	int contadorAluminio=0;
	if(listaColores!=NULL && sizeColores>0 && listaBicicleta!=NULL && sizeBicicleta>0 && listaTipos!=NULL && sizeTipos>0 && listaClientes!=NULL && sizeColores>0)
	{
		for(int i=0; i<sizeBicicleta; i++)
		{
			if(listaBicicleta[i].isEmpty==0 && listaBicicleta[i].material=='c')
			{
				contadorCarbono++;
			}
			else
			{
				if(listaBicicleta[i].isEmpty==0 && listaBicicleta[i].material=='a')
				{
					contadorAluminio++;
				}
			}
		}

		if(contadorAluminio>contadorCarbono)
		{
			printf("\nHay mas bicicletas de Aluminio, en total son %d\n", contadorAluminio);
		}
		else
		{
			if(contadorCarbono>contadorAluminio)
			{
				printf("\nHay mas bicicletas de Carbono, en total son %d\n", contadorCarbono);
			}
			else
			{
				printf("\n La cantidad de bicicletas de carbono y alumini es la misma.\n");
			}
		}
	}

}

int OrdenarBicicletasPorTipo(eBicicleta listaBicicletas[], int size)
{
	eBicicleta auxBici;
	int retorno=0;

	if(listaBicicletas!=NULL && size>0)
	{
		for(int i=0;i<size -1;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(listaBicicletas[i].isEmpty==0 && (listaBicicletas[i].idTipo>listaBicicletas[j].idTipo))
				{
					auxBici=listaBicicletas[i];
					listaBicicletas[i]=listaBicicletas[j];
					listaBicicletas[j]=auxBici;

				}
			}
		}
		retorno=1;
	}
	 return retorno;
}
//5- Elegir un color y un tipo y contar cuantas bicicletas hay de ese color y ese tipo.
void InformarCantidadColorTipo(eColor listaColores[], int sizeColores, eBicicleta listaBicicleta[], int sizeBicicleta, eTipo listaTipos[], int sizeTipos, eCliente listaClientes[], int sizeClientes)
{
	int idTipos;
	int idColores;
	int contadorBici=0;


	if(listaColores!=NULL && sizeColores>0 && listaBicicleta!=NULL && sizeBicicleta>0 && listaTipos!=NULL && sizeTipos>0 && listaClientes!=NULL && sizeColores>0)
	{
		MostrarTipos(listaTipos, sizeTipos);
		Utn_GetInt(&idTipos, "Ingrese un ID: \n", "Ingrese un ID valido: \n", 1000, 1003);
		MostrarColores(listaColores, sizeColores);
		Utn_GetInt(&idColores, "Ingrese un ID: \n", "Ingrese un ID valido: \n", 5000, 5004);


		for(int i=0; i<sizeBicicleta; i++)
		{
			if(listaBicicleta[i].isEmpty==0 && listaBicicleta[i].idTipo==idTipos && listaBicicleta[i].idColor==idColores)
			{
				contadorBici++;
			}

		}

		printf("\nHay %d bicilcetas de ese color y tipo.\n", contadorBici);
	}

}

//6- Mostrar el o los colores más elegidos por los clientes.
/*
int localidadMenosHabitada(eBicicleta listaBicicleta[],int sizeBicicleta,eColor listaColor[],int sizeColor)
{

	int contadores[]={0,0,0,0,0};


}
*///SIN TERMINAR

#endif /* INFORMES_C_ */
