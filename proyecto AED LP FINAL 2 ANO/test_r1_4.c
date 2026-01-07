#include <stdio.h>
#include "matrix_str.h"
#include "tokenizer.h"

int main() {
    MATRIX_STR *tokens = matrix_str_create(10);

    matrix_str_insert(tokens, "b");
    matrix_str_insert(tokens, "a");
    matrix_str_insert(tokens, "r");
    matrix_str_insert(tokens, " ");
    matrix_str_insert(tokens, "p");
    matrix_str_insert(tokens, "ar");
    matrix_str_insert(tokens, "bar");

    const char *sentence = "bar par";

    MATRIX_INT *ids = tokenize_sentence(sentence, tokens);

    printf("Token IDs:\n");
    for (int i = 0; i < ids->used; i++) {
        printf("%d ", ids->data[i][0]);
    }
    printf("\n");

    matrix_int_free(ids);
    matrix_str_free(tokens);
    return 0;
}
