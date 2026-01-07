/**
 * @file binario.h
 * @brief Declaraciones del módulo.
 */

#ifndef BINARIO_H
#define BINARIO_H

#include <stdio.h>
#include "ll_tk_tf.h"
#include "doc.h"

/**
 * @brief Guarda un documento completo en un fichero binario.
 * @param filename Nombre del fichero binario.
 * @param doc Documento a guardar.
 * @return 1 si tuvo éxito, 0 si hubo error.
 */
int guardar_documento_bin(const char *filename, DOC *doc);

/**
 * @brief Carga un documento completo desde un fichero binario.
 * @param filename Nombre del fichero binario.
 * @return Documento reconstruido desde el fichero.
 */
DOC *cargar_documento_bin(const char *filename);

/**
 * @brief Guarda una lista LL_TK_TF en binario.
 * @param f Fichero ya abierto en modo binario.
 * @param lista Lista a guardar.
 */
void guardar_ll_tk_tf_bin(FILE *f, LL_TK_TF *lista);

/**
 * @brief Carga una lista LL_TK_TF desde binario.
 * @param f Fichero ya abierto en modo binario.
 * @return Lista reconstruida.
 */
LL_TK_TF *cargar_ll_tk_tf_bin(FILE *f);

#endif
