#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Devuelve el ID del token más largo que encaja en la posición */
static int find_longest_token(
    const char *s,
    MATRIX_STR *tokens,
    int *length_out
) {
    int best_id = -1;
    int best_len = 0;

    for (int i = 0; i < tokens->used; i++) {
        int len = strlen(tokens->data[i]);
        if (len > best_len && strncmp(s, tokens->data[i], len) == 0) {
            best_id = i;
            best_len = len;
        }
    }

    *length_out = best_len;
    return best_id;
}

MATRIX_INT* tokenize_sentence(const char *sentence, MATRIX_STR *tokens) {
    MATRIX_INT *ids = matrix_int_create(8);
    int i = 0;

    while (sentence[i] != '\0') {
        int len = 0;
        int token_id = find_longest_token(&sentence[i], tokens, &len);

        if (token_id >= 0) {
            ids->data[ids->used] = (int*) malloc(2 * sizeof(int));
            ids->data[ids->used][0] = token_id;
            ids->data[ids->used][1] = -1;   // fin de fila
            ids->used++;
            i += len;
        } else {
            /* símbolo desconocido → se ignora 1 carácter */
            i++;
        }
    }

    return ids;
}
