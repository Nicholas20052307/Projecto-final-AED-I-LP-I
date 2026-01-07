#include <stdio.h>
#include "matrix_str.h"
#include "tokens.h"

int main() {
    MATRIX_STR *text = matrix_str_create(1);
    MATRIX_STR *tokens = matrix_str_create(20);

    matrix_str_insert(text, "bar par");

    build_tokens(text, tokens, 7);

    printf("Tokens:\n");
    matrix_str_print(tokens);

    matrix_str_free(tokens);
    matrix_str_free(text);
    return 0;
}
