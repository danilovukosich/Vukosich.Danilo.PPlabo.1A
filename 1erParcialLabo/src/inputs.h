/*
 * inputs.h
 *
 *  Created on: 19 oct. 2022
 *      Author: danil
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>

int Utn_GetInt(int* numero, char mensaje[], char mensajeError[], int minimo, int maximo);

int Utn_GetFloat(float* numero, char mensaje[], char mensajeError[], int minimo, int maximo);

int Utn_GetString(char string[], char mensaje[], char mensajeError[], int size);
#endif /* INPUTS_H_ */
