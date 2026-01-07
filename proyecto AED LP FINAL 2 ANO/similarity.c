#include <math.h>
#include "similarity.h"

/* Obtiene frecuencia de un token en TF */
static int get_freq(MATRIX_INT *tf, int token_id) {
    for (int i = 0; i < tf->used; i++) {
        if (tf->data[i][0] == token_id)
            return tf->data[i][1];
    }
    return 0;
}

double cosine_similarity(MATRIX_INT *tf1, MATRIX_INT *tf2) {
    double dot = 0.0;
    double norm1 = 0.0;
    double norm2 = 0.0;

    /* Producto escalar y norma de tf1 */
    for (int i = 0; i < tf1->used; i++) {
        int id = tf1->data[i][0];
        int f1 = tf1->data[i][1];
        int f2 = get_freq(tf2, id);

        dot += f1 * f2;
        norm1 += f1 * f1;
    }

    /* Norma de tf2 */
    for (int i = 0; i < tf2->used; i++) {
        int f2 = tf2->data[i][1];
        norm2 += f2 * f2;
    }

    if (norm1 == 0.0 || norm2 == 0.0)
        return 0.0;

    return dot / (sqrt(norm1) * sqrt(norm2));
}
