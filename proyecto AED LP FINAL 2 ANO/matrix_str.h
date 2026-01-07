/**
 * @file matrix_str.h
 * @brief Declaraciones del módulo.
 */

#ifndef MATRIX_STR_H
#define MATRIX_STR_H

typedef struct {
    char **data;   /**< matriz dinámica de strings */
    int rows;      /**< capacidad total */
    int used;      /**< número de strings usadas */
} MATRIX_STR;

/**
 * @brief Crea e inicializa una matriz dinámica de strings.
 * @param rows número inicial de filas (capacidad)
 * @return puntero a la matriz creada
 */
MATRIX_STR* matrix_str_create(int rows);

/**
 * @brief Redimensiona la matriz cuando la capacidad no es suficiente.
 * @param m matriz a redimensionar
 * @param new_size nueva capacidad
 */
void matrix_str_resize(MATRIX_STR *m, int new_size);

/**
 * @brief Inserta una nueva string en la matriz.
 *
 * Si la matriz está llena, se aumenta automáticamente su tamaño.
 */
int matrix_str_insert(MATRIX_STR *m, const char *str);

/**
 * @brief Elimina una string de la matriz usando su índice.
 *
 * Libera la memoria de la string y reorganiza el contenido.
 */
int matrix_str_remove(MATRIX_STR *m, int index);

/**
 * @brief Busca un patrón de texto dentro de la matriz.
 *
 * Muestra todas las strings que contienen el patrón indicado.
 */
void matrix_str_search(MATRIX_STR *m, const char *pattern);

/**
 * @brief Imprime todas las strings almacenadas en la matriz.
 */
void matrix_str_print(MATRIX_STR *m);

/**
 * @brief Libera toda la memoria asociada a la matriz.
 */
void matrix_str_free(MATRIX_STR *m);

#endif
