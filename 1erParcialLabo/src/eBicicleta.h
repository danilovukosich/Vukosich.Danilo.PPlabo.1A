/*
 * eBicicleta.h
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef EBICICLETA_H_
#define EBICICLETA_H_
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "string.h"
#include "eTipo.h"
#include "eColor.h"
#include "menus.h"
#include "eCliente.h"

typedef struct
{
	int id;
	char marca[20];
	int idTipo;
	int idColor;
	char material;//c= carbono y a= aluminio
	int idCliente;
	int isEmpty;


}eBicicleta;

/// @brief Funcion que inicializa la lista de bicicletas isEmpty en 1.
///
/// @param listaBici
/// @param size
/// @return retorna 0 en caso de errror y 1 si fue exitoso.
int InicializarBicicletas(eBicicleta listaBici[], int size);

/// @brief Funcion que busca un espacio libre en la lista de bicicletas.
///
/// @param pIndice
/// @param listaBici
/// @param size
/// @return retorna 0 en caso de errror y 1 si fue exitoso.
int buscarLibreBici(int* pIndice, eBicicleta listaBici[], int size);

/// @brief Funcion que carga una unica bicicleta.
///
/// @param bicicleta
/// @param listaTipos
/// @param listaColor
void CargarBicicleta(eBicicleta bicicleta[], eTipo listaTipos[], eColor listaColor[]);

/// @brief Funcion que carga una lista de bicicletas
///
/// @param pId
/// @param listaBici
/// @param size
/// @param listaTipos
/// @param listaColores
/// @return retorna 0 en caso de errror y 1 si fue exitoso.
int AltaBicicleta(int* pId, eBicicleta listaBici[], int size,  eTipo listaTipos[], eColor listaColores[]);

/// @brief Funcion que muestra una unica bicicleta
///
/// @param bici
/// @param listaTipos
/// @param listaColores
void MostrarBicicleta(eBicicleta bici, eTipo listaTipos[],int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClinetes);

/// @brief
///
/// @param listaBicicletas
/// @param sizeBicicletas
/// @param listaTipos
/// @param sizeTipos
/// @param listaColores
/// @param sizeColores
void MostrarBicicletas(eBicicleta listaBicicletas[], int sizeBicicletas, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);

/// @brief
///
/// @param listaBicicleta
/// @param sizeListaBicicleta
/// @param id
/// @return
int BuscarBicicletaPorId(eBicicleta listaBicicleta[], int sizeListaBicicleta, int id);

/// @brief
///
/// @param listaBicicleta
/// @param sizeListaBicicleta
/// @param listaTipos
/// @param sizeTipos
/// @param listaColores
/// @param sizeColores
/// @return
int BajaBicicleta(eBicicleta listaBicicleta[], int sizeListaBicicleta, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[], int sizeClientes);


/// @brief
///
/// @param listaBicicletas
/// @param sizeListaBicicleta
/// @param listaTipos
/// @param sizeTipos
/// @param listaColores
/// @param sizeColores
/// @return
int ModificarBicicleta(eBicicleta listaBicicletas[], int sizeListaBicicleta, eTipo listaTipos[], int sizeTipos, eColor listaColores[], int sizeColores, eCliente listaClientes[],  int sizeClientes);

/// @brief
///
/// @param pId
/// @param vec
/// @param tam
/// @param cant
/// @return
int hardcodearBicicletas(int* pId,eBicicleta vec[], int tam, int cant);

/// @brief
///
/// @param listaBicicletas
/// @param size
/// @return
int OrdenarBicicletas(eBicicleta listaBicicletas[], int size);
#endif /* EBICICLETA_H_ */
