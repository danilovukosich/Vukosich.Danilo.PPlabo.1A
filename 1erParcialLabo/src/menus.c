/*
 * menus.c
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef MENUS_C_
#define MENUS_C_
#include "menus.h"

void MenuPrincipal(void)
{
	printf("\n       <MENU PRINCIPAL>\n\n"
			"1)ALTA BICICLETA. \n"
			"2)MODIFICAR BICICLETA. \n"
			"3)BAJA BICICLETA. \n"
			"4)LISTAR BICICLETAS. \n"
			"5)LISTAR TIPOS\n"
			"6)LISTAR COLORES\n"
			"7)LISTAR SERVICIOS\n"
			"8)ALTA TRABAJO\n"
			"9)LISTA TARABAJOS\n"
			"10)SALIR/n");
}


void MenuModificaciones(void)
{
	printf("\n       <MENU MODIFICACIONES>\n\n"
			"1)Modificar MARCA. \n"
			"2)Modificar TIPO. \n"
			"3)Modificar COLOR. \n"
			"4)Modificar Material\n"
			"5)VOLVER\n");
}

#endif /* MENUS_C_ */
