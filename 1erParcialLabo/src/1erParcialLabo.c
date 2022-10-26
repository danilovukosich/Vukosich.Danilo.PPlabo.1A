/*
 ============================================================================
 Name        : 1erParcialLabo.c
 Author      : danilo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 arrays harcodeados tipos colores y se
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "inputs.h"
#include "eTipo.h"
#include "eColor.h"
#include "eServicio.h"
#include "eBicicleta.h"
#include "eTrabajo.h"
#include "informes.h"


#define VACIO 1
#define OCUPADO 0
#define TAM 100


int main(void) {
	setbuf(stdout,NULL);

	int respuesta;
	int idBici = 100;
	int idTrabajo = 2000;
	int aux;

	eTipo tipos[4]={{1000, "Rutera"},
				{1001, "Carrera"},
				{1002, "Mountain"},
				{1003, "BMX"}};

	eColor colores[5]={{5000,"Gris"},
					{5001,"Blanco"},
					{5002,"Azul"},
					{5003,"Negro"},
					{5004,"Rojo"}};

	eServicio servicios[4]={{20000, "Limpieza", 30},
						 {20001, "Parche", 400},
						 {20002, "Centrado", 500},
						 {20003, "Cadena", 450}};

	eCliente listaCLientes[10] ={{10, "Danilo",'m'},
								{11, "Joaquin",'m'},
								{12, "Nicolas",'m'},
								{13, "Daniela", 'f'},
								{14, "Juan", 'm'},
								{15, "Milena", 'f'},
								{16, "Victoria", 'f'},
								{17, "Marta", 'f'},
								{18, "Elias", 'm'},
								{19, "Luca", 'm'}};

	eBicicleta listaBicicletas[TAM];
	eTrabajo listaTrabajos[TAM];
	eCliente listaClientes[10];

	InicializarBicicletas(listaBicicletas, TAM);
	InicializarTrabajos(listaTrabajos, TAM);

	hardcodearBicicletas(&idBici, listaBicicletas, TAM, 10);



	do
	{
		MenuPrincipal();
		Utn_GetInt(&respuesta, "\nIngrese una opcion: ", "\nIngrese una opcion valida", 1, 15);

		switch(respuesta)
		{
		case 1:
			aux = AltaBicicleta(&idBici, listaBicicletas, TAM, tipos, colores);
			break;

		case 2:
			ModificarBicicleta(listaBicicletas, TAM, tipos, 4, colores, 5, listaClientes, 10);
			break;
		case 3:
			BajaBicicleta(listaBicicletas, TAM, tipos, 4, colores, 5, listaClientes, 10);
			break;
		case 4:
			OrdenarBicicletas(listaBicicletas, TAM);
			MostrarBicicletas(listaBicicletas, TAM, tipos, 4, colores, 5, listaClientes, 10);
			break;
		case 5:
			MostrarTipos(tipos, 4);
			break;
		case 6:
			MostrarColores(colores, 5);
			break;
		case 7:
			MostrarServicios(servicios, 4);
			break;
		case 8:
			AltaTrabajos(&idTrabajo, listaTrabajos, TAM, listaBicicletas, TAM, servicios, 4, tipos, 4, colores, 5, listaClientes, 10);
			break;
		case 9:
			MostrarTrabajos(listaTrabajos, TAM, servicios, 4);
			break;
		case 10:
			InformarBicicletasColorSeleccionado(colores, 5, listaBicicletas, TAM, tipos, 4, listaClientes, 10);
			break;
		case 11:
			InformarBicicletasTipoSeleccionado(colores, 5, listaBicicletas, TAM, tipos, 4, listaClientes, 10);
			break;
		case 12:
			InformarCantidadMasMaterial(colores, 5, listaBicicletas, TAM, tipos, 4, listaClientes, 10);
			break;
		case 13:
			OrdenarBicicletasPorTipo(listaBicicletas, TAM);
			MostrarBicicletas(listaBicicletas, TAM, tipos, 4, colores, 5, listaClientes, 10);
			break;
		case 14:
			InformarCantidadColorTipo(colores, 5, listaBicicletas, TAM, tipos, 4, listaClientes, 10);
			break;
		}

	}while(respuesta!=15);

	return EXIT_SUCCESS;
}
