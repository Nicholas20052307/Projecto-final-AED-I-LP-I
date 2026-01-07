#include <stdio.h>
#include "matrix_str.h"
#include "tokenizer.h"
#include "tf.h"
#include "doc.h"
#include "doc_similarity.h"

int main() {
    MATRIX_STR *tokens = matrix_str_create(10);

    matrix_str_insert(tokens, "b");
    matrix_str_insert(tokens, "a");
    matrix_str_insert(tokens, "r");
    matrix_str_insert(tokens, " ");
    matrix_str_insert(tokens, "p");
    matrix_str_insert(tokens, "ar");
    matrix_str_insert(tokens, "bar");

    int num_tokens = tokens->used;

    DOC *d1 = doc_create(1);
    DOC *d2 = doc_create(2);

    const char *doc1[] = { "bar bar", "bar par" };
    const char *doc2[] = { "bar par", "par bar" };

    for (int i = 0; i < 2; i++) {
        MATRIX_INT *ids = tokenize_sentence(doc1[i], tokens);
        MATRIX_INT *tf  = compute_tf(ids, num_tokens);
        doc_add_sentence(d1, ids, tf);
    }

    for (int i = 0; i < 2; i++) {
        MATRIX_INT *ids = tokenize_sentence(doc2[i], tokens);
        MATRIX_INT *tf  = compute_tf(ids, num_tokens);
        doc_add_sentence(d2, ids, tf);
    }

    double sim = doc_similarity(d1, d2, num_tokens);
    printf("Similaridade entre documentos: %.4f\n", sim);

    doc_free(d1);
    doc_free(d2);
    matrix_str_free(tokens);
    return 0;
}
