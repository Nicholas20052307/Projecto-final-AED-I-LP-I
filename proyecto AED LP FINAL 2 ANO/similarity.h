/**
 * @file similarity.h
 * @brief Declaraciones del módulo.
 */

#ifndef SIMILARITY_H
#define SIMILARITY_H

#include "matrix_int.h"

/**
 * @brief Calcula la similaridad coseno entre dos TFs
 * @param tf1 MATRIX_INT con pares (tokenID, freq)
 * @param tf2 MATRIX_INT con pares (tokenID, freq)
 * @return valor de similaridad coseno
 */
double cosine_similarity(MATRIX_INT *tf1, MATRIX_INT *tf2);

#endif
