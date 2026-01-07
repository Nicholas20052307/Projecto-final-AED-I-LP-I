#include <math.h>
#include <stdlib.h>
#include "doc_similarity.h"
#include "doc.h"

/* acumula TF de todas las frases del documento */
static void accumulate_tf(double *vec, LL_TK_TF *list) {
    TK_TF_NODE *cur = list->head;

    while (cur) {
        int n = cur->ids->used;

        for (int i = 0; i < n; i++) {
            int token_id = cur->ids->data[0][i];
            int freq     = cur->tf->data[0][i];

            vec[token_id] += freq;
        }
        cur = cur->next;
    }
}

double doc_similarity(DOC *d1, DOC *d2, int num_tokens) {
    if (!d1 || !d2) return 0.0;

    double *v1 = (double*) calloc(num_tokens, sizeof(double));
    double *v2 = (double*) calloc(num_tokens, sizeof(double));

    accumulate_tf(v1, d1->list);
    accumulate_tf(v2, d2->list);

    double dot = 0.0, n1 = 0.0, n2 = 0.0;

    for (int i = 0; i < num_tokens; i++) {
        dot += v1[i] * v2[i];
        n1  += v1[i] * v1[i];
        n2  += v2[i] * v2[i];
    }

    free(v1);
    free(v2);

    if (n1 == 0.0 || n2 == 0.0) return 0.0;

    return dot / (sqrt(n1) * sqrt(n2));
}
