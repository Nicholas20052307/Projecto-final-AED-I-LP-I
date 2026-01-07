#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_str.h"

int main() {
    MATRIX_STR *text = matrix_str_create(3);

    text->data[text->used++] = strdup("the cat sleeps");
    text->data[text->used++] = strdup("the dog runs");
    text->data[text->used++] = strdup("a cat eats");

    printf("Texto inicial:\n");
    matrix_str_print(text);

    matrix_str_free(text);
    return 0;
}
