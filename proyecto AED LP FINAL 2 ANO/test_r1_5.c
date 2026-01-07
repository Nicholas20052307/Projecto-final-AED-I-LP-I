#include <stdio.h>
#include "matrix_str.h"
#include "tokenizer.h"
#include "tf.h"

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
    MATRIX_INT *tf = compute_tf(ids, tokens->used);

    printf("TF (tokenID, freq):\n");
    for (int i = 0; i < tf->used; i++) {
        printf("(%d, %d)\n", tf->data[i][0], tf->data[i][1]);
    }

    matrix_int_free(ids);
    matrix_int_free(tf);
    matrix_str_free(tokens);
    return 0;
}
