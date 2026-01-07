#include <stdlib.h>
#include "tf.h"

MATRIX_INT* compute_tf(MATRIX_INT *token_ids, int vocab_size) {
    int *freq = (int*) calloc(vocab_size, sizeof(int));

    /* Contar frecuencias */
    for (int i = 0; i < token_ids->used; i++) {
        int id = token_ids->data[i][0];
        if (id >= 0 && id < vocab_size)
            freq[id]++;
    }

    /* Contar tokens distintos */
    int count = 0;
    for (int i = 0; i < vocab_size; i++) {
        if (freq[i] > 0)
            count++;
    }

    /* Crear MATRIX_INT con 'count' filas */
    MATRIX_INT *tf = matrix_int_create(count);

    int row = 0;
    for (int i = 0; i < vocab_size; i++) {
        if (freq[i] > 0) {
            tf->data[row] = (int*) malloc(3 * sizeof(int));
            tf->data[row][0] = i;        /* tokenID */
            tf->data[row][1] = freq[i]; /* frecuencia */
            tf->data[row][2] = -1;      /* fin de fila */
            row++;
        }
    }

    tf->used = count;
    free(freq);
    return tf;
}
