/**
 * @file matrix_int.h
 * @brief Declaraciones del módulo.
 */

#ifndef MATRIX_INT_H
#define MATRIX_INT_H

/**
 * @brief Estructura para matriz dinamica de enteros
 */
typedef struct {
    int **data;   /**< matriz de inteiros */
    int rows;     /**< tamanho total */
    int used;     /**< linhas ocupadas */
} MATRIX_INT;

/**
 * @brief Crea una matriz dinamica de enteros
 * @param rows número inicial de lineas
 * @return ponteiro para MATRIX_INT
 */
MATRIX_INT* matrix_int_create(int rows);

/**
 * @brief Redimensiona la matriz
 * @param m matriz
 * @param new_size nuevo tamano
 */
void matrix_int_resize(MATRIX_INT *m, int new_size);

/**
 * @brief Muestra la matriz
 * @param m matriz
 */
void matrix_int_print(MATRIX_INT *m);

/**
 * @brief Libera la memória de la matriz
 * @param m matriz
 */
void matrix_int_free(MATRIX_INT *m);

#endif
