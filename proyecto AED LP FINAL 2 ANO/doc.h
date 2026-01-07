/**
 * @file doc.h
 * @brief Declaraciones del módulo.
 */

#ifndef DOC_H
#define DOC_H

#include "ll_tk_tf.h"

/* Documento */
typedef struct {
    int doc_id;
    int num_sentences;
    LL_TK_TF *list;
} DOC;

/**
 * @brief Crea un documento vacío
 */
DOC* doc_create(int doc_id);

/**
 * @brief Añade una frase (ids + tf) al documento
 */
void doc_add_sentence(DOC *doc, MATRIX_INT *ids, MATRIX_INT *tf);

/**
 * @brief Libera toda la memoria del documento
 */
void doc_free(DOC *doc);

#endif
