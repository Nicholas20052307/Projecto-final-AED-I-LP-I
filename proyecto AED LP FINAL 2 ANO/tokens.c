#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"

/* Inserta caracteres únicos del texto */
static void insert_unique_chars(MATRIX_STR *text, MATRIX_STR *tokens) {
    for (int i = 0; i < text->used; i++) {
        char *s = text->data[i];
        for (int j = 0; s[j]; j++) {
            char c[2] = { s[j], '\0' };
            int found = 0;
            for (int k = 0; k < tokens->used; k++) {
                if (strcmp(tokens->data[k], c) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found)
                matrix_str_insert(tokens, c);
        }
    }
}

/* Cuenta frecuencia de un par */
static int count_pair(MATRIX_STR *text, const char *pair) {
    int count = 0;
    for (int i = 0; i < text->used; i++) {
        char *s = text->data[i];
        char *p = s;
        while ((p = strstr(p, pair)) != NULL) {
            count++;
            p++;
        }
    }
    return count;
}

/* Fusiona un par en todo el texto */
static void merge_pair(MATRIX_STR *text, const char *pair) {
    char buffer[1024];

    for (int i = 0; i < text->used; i++) {
        char *s = text->data[i];
        buffer[0] = '\0';

        for (int j = 0; s[j]; ) {
            if (strncmp(&s[j], pair, strlen(pair)) == 0) {
                strcat(buffer, pair);
                j += strlen(pair);
            } else {
                strncat(buffer, &s[j], 1);
                j++;
            }
        }

        free(text->data[i]);
        text->data[i] = strdup(buffer);
    }
}

void build_token_alphabet(MATRIX_STR *text, MATRIX_STR *tokens, int max_tokens) {
    insert_unique_chars(text, tokens);

    while (tokens->used < max_tokens) {
        char best_pair[64] = "";
        int best_freq = 0;

        for (int i = 0; i < tokens->used; i++) {
            for (int j = 0; j < tokens->used; j++) {
                char pair[64];
                strcpy(pair, tokens->data[i]);
                strcat(pair, tokens->data[j]);

                int freq = count_pair(text, pair);
                if (freq > best_freq) {
                    best_freq = freq;
                    strcpy(best_pair, pair);
                }
            }
        }

        if (best_freq == 0)
            break;

        /* ⬇⬇⬇ COMPROBAR SI EL TOKEN YA EXISTE ⬇⬇⬇ */
        int exists = 0;
        for (int i = 0; i < tokens->used; i++) {
            if (strcmp(tokens->data[i], best_pair) == 0) {
                exists = 1;
                break;
            }
        }

        if (exists)
            break;

        matrix_str_insert(tokens, best_pair);
        merge_pair(text, best_pair);
    }
}


/* Wrapper para mantener compatibilidad con los tests */
void build_tokens(MATRIX_STR *text, MATRIX_STR *tokens, int max_tokens) {
    build_token_alphabet(text, tokens, max_tokens);
}
