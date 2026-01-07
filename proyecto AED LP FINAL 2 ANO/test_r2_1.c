#include <stdio.h>
#include "matrix_str.h"
#include "tokenizer.h"
#include "tf.h"
#include "ll_tk_tf.h"

int main() {
    MATRIX_STR *tokens = matrix_str_create(10);

    matrix_str_insert(tokens, "b");
    matrix_str_insert(tokens, "a");
    matrix_str_insert(tokens, "r");
    matrix_str_insert(tokens, " ");
    matrix_str_insert(tokens, "p");
    matrix_str_insert(tokens, "ar");
    matrix_str_insert(tokens, "bar");

    LL_TK_TF *list = ll_tk_tf_create();

    const char *sentences[] = {
        "bar par",
        "bar bar",
        "par bar"
    };

    for (int i = 0; i < 3; i++) {
        MATRIX_INT *ids = tokenize_sentence(sentences[i], tokens);
        MATRIX_INT *tf  = compute_tf(ids, tokens->used);
        ll_tk_tf_append(list, ids, tf);
    }

    printf("Numero de frases na lista: %d\n", list->size);

    ll_tk_tf_free(list);
    matrix_str_free(tokens);
    return 0;
}
