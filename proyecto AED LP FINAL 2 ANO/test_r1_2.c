#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "matrix_str.h"

int main() {
    MATRIX_STR *text = matrix_str_create(2);

    matrix_str_insert(text, "the cat sleeps");
    matrix_str_insert(text, "the dog runs");
    matrix_str_insert(text, "a cat eats");

    printf("Texto inicial:\n");
    matrix_str_print(text);

    printf("\nPesquisa por 'cat':\n");
    matrix_str_search(text, "cat");

    printf("\nRemover indice 1:\n");
    matrix_str_remove(text, 1);
    matrix_str_print(text);

    matrix_str_free(text);
    return 0;
}
