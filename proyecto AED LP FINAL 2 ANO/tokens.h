/**
 * @file tokens.h
 * @brief Declaraciones del módulo.
 */

#ifndef TOKENS_H
#define TOKENS_H

#include "matrix_str.h"

/**
 * @brief Construye el alfabeto de tokens (R1.3)
 * @param text matriz con las frases
 * @param tokens matriz donde se guardan los tokens
 * @param max_tokens número máximo de tokens
 */
void build_token_alphabet(MATRIX_STR *text, MATRIX_STR *tokens, int max_tokens);

/**
 * @brief Wrapper para compatibilidad con tests (R1.3)
 */
void build_tokens(MATRIX_STR *text, MATRIX_STR *tokens, int max_tokens);

#endif
