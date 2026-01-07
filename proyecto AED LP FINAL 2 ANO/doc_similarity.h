/**
 * @file doc_similarity.h
 * @brief Declaraciones del módulo.
 */

#ifndef DOC_SIMILARITY_H
#define DOC_SIMILARITY_H

#include "doc.h"

/**
 * @brief Similaridade coseno entre dois documentos
 * @param d1 documento 1
 * @param d2 documento 2
 * @param num_tokens número total de tokens
 */
double doc_similarity(DOC *d1, DOC *d2, int num_tokens);

#endif
