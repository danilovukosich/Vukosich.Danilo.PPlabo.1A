/*
 * informes.h
 *
 *  Created on: 26 oct. 2022
 *      Author: danil
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "eBicicleta.h"

void InformarBicicletasColorSeleccionado(eColor listaColores[], int sizeColores, eBicicleta listaBicicleta[], int sizeBicicleta, eTipo listaTipos[], int sizeTipos, eCliente listaClientes[], int sizeClientes);

void InformarBicicletasTipoSeleccionado(eColor listaColores[], int sizeColores, eBicicleta listaBicicleta[], int sizeBicicleta, eTipo listaTipos[], int sizeTipos, eCliente listaClientes[], int sizeClientes);

void InformarCantidadMasMaterial(eColor listaColores[], int sizeColores, eBicicleta listaBicicleta[], int sizeBicicleta, eTipo listaTipos[], int sizeTipos, eCliente listaClientes[], int sizeClientes);

int OrdenarBicicletasPorTipo(eBicicleta listaBicicletas[], int size);

void InformarCantidadColorTipo(eColor listaColores[], int sizeColores, eBicicleta listaBicicleta[], int sizeBicicleta, eTipo listaTipos[], int sizeTipos, eCliente listaClientes[], int sizeClientes);
#endif /* INFORMES_H_ */
