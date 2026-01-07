#include <stdio.h>
#include <stdlib.h>
#include "matrix_int.h"

MATRIX_INT* matrix_int_create(int rows) {
    MATRIX_INT *m = (MATRIX_INT*) malloc(sizeof(MATRIX_INT));
    if (!m) return NULL;

    m->rows = rows;
    m->used = 0;
    m->data = (int**) malloc(rows * sizeof(int*));

    if (!m->data) {
        free(m);
        return NULL;
    }

    return m;
}

void matrix_int_resize(MATRIX_INT *m, int new_size) {
    if (!m) return;

    int **tmp = (int**) realloc(m->data, new_size * sizeof(int*));
    if (!tmp) return;

    m->data = tmp;
    m->rows = new_size;
}

void matrix_int_print(MATRIX_INT *m) {
    if (!m) return;

    for (int i = 0; i < m->used; i++) {
        printf("[%d]: ", i);
        int j = 0;
        while (m->data[i][j] != -1) {
            printf("%d ", m->data[i][j]);
            j++;
        }
        printf("\n");
    }
}

void matrix_int_free(MATRIX_INT *m) {
    if (!m) return;

    for (int i = 0; i < m->used; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}
