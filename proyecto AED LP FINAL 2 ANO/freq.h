/**
 * @file freq.h
 * @brief Declaraciones del módulo.
 */

#ifndef FREQ_H
#define FREQ_H

#include "matrix_str.h"

typedef struct {
    char *token;
    int count;
} FREQ;

/**
 * @brief Cuenta las frecuencias de los tokens
 *
 * @param tokens matriz de tokens
 * @param freq array de frecuencias
 * @param size tamanho máximo del aray
 * @return número de entradas usadas
 */
int count_frequencies(MATRIX_STR *tokens, FREQ *freq, int size);

/**
 * @brief Muestras las frecuencias
 */
void print_frequencies(FREQ *freq, int used);

#endif
