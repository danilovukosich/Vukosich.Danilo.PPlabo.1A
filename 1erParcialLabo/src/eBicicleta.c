/*
 * eBicicleta.c
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef EBICICLETA_C_
#define EBICICLETA_C_
#include "eBicicleta.h"



int InicializarBicicletas(eBicicleta listaBici[], int size)
{
	int retorno = 0;

	    if(listaBici != NULL && size > 0)
	    {
	        for(int i = 0 ; i < size ; i++)
	        {
	        	listaBici[i].isEmpty = 1;
	        }

	        retorno = 1;
	    }

	    return retorno;

}

int BuscarLibreBici(int* pIndice, eBicicleta listaBici[], int size)
{


    int retorno = 0;
    int indice = -1;

    if(pIndice != NULL && listaBici != NULL && size > 0)
    {

        for(int i = 0 ; i < size ; i++)
        {
            if( listaBici[i].isEmpty)
            {
                indice = i;
                break;
            }
        }

        *pIndice = indice;

        retorno = 1;
    }

    return retorno;

}

void CargarBicicleta(eBicicleta bicicleta[], eTipo listaTipos[], eColor listaColor[])
{
	char marcaBici[20];
	int aux;

	aux = Utn_GetString(marcaBici, "ingrese marca: ","ingrese marca valida: ", 20);
	strcpy(bicicleta->marca, marcaBici);

	MostrarTipos(listaTipos, 4);
	aux=Utn_GetInt(&bicicleta->idTipo, "ingrese el id del Tipo: ", "ingrese el id del tipo valido: ", 1000, 1003);

	MostrarColores(listaColor, 5);
	aux=Utn_GetInt(&bicicleta->idColor, "ingrese el id del Color: ", "ingrese el id del color valido: ", 5000, 5004);

	printf("\nIngrese el material 'c' para carbono o 'a' para aluminio: ");
	fflush(stdin);
	scanf("%c", &bicicleta->material);

	Utn_GetInt(&bicicleta->idCliente, "Ingrese un ID de Cliente: ", "Ingrese un ID de Cliente valido: ", 10, 100);

	bicicleta->isEmpty=0;

}


int AltaBicicleta(int* pId, eBicicleta listaBici[], int size,  eTipo listaTipos[], eColor listaColores[])
{

    int retorno = 0;
    int indice;
    eBicicleta auxBici;

    if(pId != NULL && listaBici != NULL && size > 0)
    {

        printf("Alta Bicicleta\n\n");

        BuscarLibreBici(&indice, listaBici, size);

        if(indice == -1)
        {

            printf("No hay lugar.\n");

        }
        else
        {
            CargarBicicleta(&auxBici ,listaTipos, listaColores);

            auxBici.id = *pId;

            *pId = *pId + 1;

            listaBici[indice] = auxBici;
            retorno = 1;

        }


    }
    return retorno;
}

void MostrarBicicleta(eBicicleta bici, eTipo listaTipos[],int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	char descripcionTipo[20];
	char nombreColor[20];
	char nombreCliente[20];
	CargarDescripcionTipo(listaTipos, sizeTipos, bici.idTipo, &descripcionTipo);
	CargarNombreColor(listaColores, sizeColores, bici.idColor, &nombreColor);
	CargarDescripcionCliente(listaClientes, sizeClientes, bici.idCliente, &nombreCliente);



	printf("%4d     %10s     %10s   %10s        %c  %10s \n",bici.id, bici.marca, descripcionTipo, nombreColor , bici.material, nombreCliente);


}

void MostrarBicicletas(eBicicleta listaBicicletas[], int sizeBicicletas, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	printf("           -------LISTA BICICLETAS-------\n");
	printf("  ID    |    MARCA      |    TIPO    |   COLOR   |   MATERIAL  | CLIENTE |\n");

	if(listaBicicletas!=NULL && sizeBicicletas>0 && listaTipos!=NULL && sizeTipos>0 && listaColores!=NULL && sizeColores>0)
	{
		for(int i=0; i<sizeBicicletas; i++)
		{
			if(listaBicicletas[i].isEmpty==0)
			{
				MostrarBicicleta(listaBicicletas[i], listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
			}

		}
	}


}

int BuscarBicicletaPorId(eBicicleta listaBicicleta[], int sizeListaBicicleta, int id)
{
	int indiceBici=-1;

	if(listaBicicleta!=NULL && sizeListaBicicleta>0)
	{
		for(int i=0; i<sizeListaBicicleta; i++)
		{
			if(listaBicicleta[i].isEmpty==0 && listaBicicleta[i].id==id)
			{
				indiceBici=i;
				break;
			}
		}
	}

	return indiceBici;
}


int BajaBicicleta(eBicicleta listaBicicleta[], int sizeListaBicicleta, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	int id;
	int indice;
	int respuesta;
	int retorno=0;
	if(listaBicicleta!=NULL && sizeListaBicicleta>0)
	{
		printf("      +++BAJA BICICLETA+++\n");

		MostrarBicicletas(listaBicicleta, sizeListaBicicleta, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
		Utn_GetInt(&id, "Ingrese ID: \n", "Ingrense ID Valido: \n", 100, 200);


		indice=BuscarBicicletaPorId(listaBicicleta, sizeListaBicicleta, id);

		if(indice==-1)
		{
			printf("NO hay bicicleta con el id ingresado...\n");
		}
		else
		{
			MostrarBicicleta(listaBicicleta[indice], listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
			Utn_GetInt(&respuesta, "Confirmar baja:\n 1)SI.\n2)NO.\n", "Ingrese una opcion valida \n 1)SI.\n2)NO.\n", 1, 2);
			if(respuesta==1)
			{
				listaBicicleta[indice].isEmpty=1;
				printf("Baja EXITOSA...");
				retorno=1;
			}
			else
			{
				printf("Baja cancelada");
			}
		}

	}

	return retorno;
}

int ModificarBicicleta(eBicicleta listaBicicletas[], int sizeListaBicicleta, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes)
{
	int retorno;
	int id;
	int indice;
	int respuesta;
	int respuesta2;
	char marcaBici[20];

	printf("     +++MODIFICACION+++\n");
	MostrarBicicletas(listaBicicletas, sizeListaBicicleta, listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
	Utn_GetInt(&id, "Ingrese ID: \n", "Ingrense ID Valido: \n", 100, 200);
	indice=BuscarBicicletaPorId(listaBicicletas, sizeListaBicicleta, id);



	if(indice==-1)
	{
		printf("NO hay bicicleta con el id ingresado...\n");
	}
	else
	{
		MostrarBicicleta(listaBicicletas[indice], listaTipos, sizeTipos, listaColores, sizeColores, listaClientes, sizeClientes);
		Utn_GetInt(&respuesta, "Desea modificar esta Bicicleta?\n 1)SI.\n2)NO.\n", "Ingrese una opcion valida. \n 1)SI.\n2)NO.\n", 1, 2);
		if(respuesta==1)
		{
			do
			{
				MenuModificaciones();
				Utn_GetInt(&respuesta2, "Ingrese una Opcion: \n", "Ingrese una opcion valida: \n", 1, 5);

				switch(respuesta2)
				{
				case 1:
					Utn_GetString(marcaBici, "ingrese marca: ","ingrese marca valida: ", 20);
					strcpy(listaBicicletas[indice].marca, marcaBici);
					break;

				case 2:
					MostrarTipos(listaTipos, 4);
					Utn_GetInt(&listaBicicletas[indice].idTipo, "ingrese el id del Tipo: ", "ingrese el id del tipo valido: ", 1000, 1003);
					break;

				case 3:
					MostrarColores(listaColores, 5);
					Utn_GetInt(&listaBicicletas[indice].idColor, "ingrese el id del Color: ", "ingrese el id del color valido: ", 5000, 5004);
					break;

				case 4:
					printf("\nIngrese el material 'c' para carbono o 'a' para aluminio: ");
					fflush(stdin);
					scanf("%c", &listaBicicletas[indice].material);
					break;

				case 5:
					break;
				}

			}while(respuesta2!=5);

			retorno=1;
		}
		else
		{
			printf("Baja cancelada");
		}
	}

	return retorno;
}

int hardcodearBicicletas(int* pId,eBicicleta vec[], int tam, int cant)
{

    int todoOk = 0;

    eBicicleta auxBicicletas[] ={{3000, "Peugeot", 1003, 5004, 'a', 10, 0},
									{3001, "Venzo", 1001, 5003, 'a', 11, 0},
									{3002, "Raleigh", 1001, 5002, 'a', 12, 0},
									{3003, "Sunn", 1002, 5001, 'c',13, 0},
									{3004, "Venzo", 1001, 5002, 'a', 14, 0},
									{3005, "Look", 1002, 5004, 'a', 15, 0},
									{3006, "Look", 1000, 5001, 'c', 16, 0},
									{3007, "Sunn", 1003, 5004, 'c',17, 0},
									{3008, "Look", 1002, 5000,'a', 18, 0},
									{3009, "Peugeot", 1000, 5003,'c',19, 0}};

    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {

        for(int i = 0 ; i < cant ; i++)
        {
            vec[i] = auxBicicletas[i];
            pId =pId + 1;
        }
        todoOk = 1;
    }
    return todoOk;
}
//s ordenadas por tipo y material
int OrdenarBicicletas(eBicicleta listaBicicletas[], int size)
{
	eBicicleta auxBici;
	int retorno=0;

	if(listaBicicletas!=NULL && size>0)
	{
		for(int i=0;i<size -1;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(listaBicicletas[i].isEmpty==0 &&( (listaBicicletas[i].idTipo==listaBicicletas[j].idTipo && listaBicicletas[i].material>listaBicicletas[j].material)||(listaBicicletas[i].idTipo>listaBicicletas[j].idTipo)))
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




#endif /* EBICICLETA_C_ */
