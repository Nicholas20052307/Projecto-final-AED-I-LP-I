/**
 * @file tf.h
 * @brief Declaraciones del módulo.
 */

#ifndef TF_H
#define TF_H

#include "matrix_int.h"

/**
 * @brief Calcula el TF a partir de una lista de IDs de tokens
 * @param token_ids MATRIX_INT con una fila de token IDs
 * @param vocab_size número total de tokens
 * @return MATRIX_INT con pares (tokenID, frecuencia)
 */
MATRIX_INT* compute_tf(MATRIX_INT *token_ids, int vocab_size);

#endif
