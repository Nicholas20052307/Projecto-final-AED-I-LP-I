/**
 * @file ll_tk_tf.h
 * @brief Declaraciones del módulo.
 */

#ifndef LL_TK_TF_H
#define LL_TK_TF_H

#include "matrix_int.h"

/* Nodo de la lista */
typedef struct tk_tf_node {
    MATRIX_INT *ids;
    MATRIX_INT *tf;
    struct tk_tf_node *next;
} TK_TF_NODE;

/* Lista enlazada */
typedef struct {
    TK_TF_NODE *head;
    TK_TF_NODE *tail;
    int size;
} LL_TK_TF;

/**
 * @brief Crea una lista enlazada vacía
 */
LL_TK_TF* ll_tk_tf_create(void);

/**
 * @brief Inserta un nodo al final de la lista
 */
void ll_tk_tf_append(LL_TK_TF *list, MATRIX_INT *ids, MATRIX_INT *tf);

/**
 * @brief Libera toda la lista
 */
void ll_tk_tf_free(LL_TK_TF *list);

#endif
