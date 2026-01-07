/**
 * @file tokenizer.h
 * @brief Declaraciones del módulo.
 */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "matrix_str.h"
#include "matrix_int.h"

/**
 * @brief Tokeniza una frase usando greedy longest-match
 * @param sentence frase original
 * @param tokens alfabeto de tokens
 * @return MATRIX_INT con IDs de tokens
 */
MATRIX_INT* tokenize_sentence(const char *sentence, MATRIX_STR *tokens);

#endif
