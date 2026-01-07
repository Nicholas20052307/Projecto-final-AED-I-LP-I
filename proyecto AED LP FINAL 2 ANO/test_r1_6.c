#include <stdio.h>
#include "matrix_str.h"
#include "tokenizer.h"
#include "tf.h"
#include "similarity.h"

int main() {
    MATRIX_STR *tokens = matrix_str_create(10);

    matrix_str_insert(tokens, "b");
    matrix_str_insert(tokens, "a");
    matrix_str_insert(tokens, "r");
    matrix_str_insert(tokens, " ");
    matrix_str_insert(tokens, "p");
    matrix_str_insert(tokens, "ar");
    matrix_str_insert(tokens, "bar");

    const char *s1 = "bar par";
    const char *s2 = "bar bar";

    MATRIX_INT *ids1 = tokenize_sentence(s1, tokens);
    MATRIX_INT *ids2 = tokenize_sentence(s2, tokens);

    MATRIX_INT *tf1 = compute_tf(ids1, tokens->used);
    MATRIX_INT *tf2 = compute_tf(ids2, tokens->used);

    double sim = cosine_similarity(tf1, tf2);

    printf("Similaridade coseno: %.4f\n", sim);

    matrix_int_free(ids1);
    matrix_int_free(ids2);
    matrix_int_free(tf1);
    matrix_int_free(tf2);
    matrix_str_free(tokens);
    return 0;
}
