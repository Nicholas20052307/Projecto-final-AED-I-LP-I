#include <stdio.h>
#include "matrix_str.h"
#include "tokenizer.h"
#include "tf.h"
#include "doc.h"

int main() {
    MATRIX_STR *tokens = matrix_str_create(10);

    matrix_str_insert(tokens, "b");
    matrix_str_insert(tokens, "a");
    matrix_str_insert(tokens, "r");
    matrix_str_insert(tokens, " ");
    matrix_str_insert(tokens, "p");
    matrix_str_insert(tokens, "ar");
    matrix_str_insert(tokens, "bar");

    DOC *doc = doc_create(1);

    const char *sentences[] = {
        "bar par",
        "bar bar",
        "par bar"
    };

    for (int i = 0; i < 3; i++) {
        MATRIX_INT *ids = tokenize_sentence(sentences[i], tokens);
        MATRIX_INT *tf  = compute_tf(ids, tokens->used);
        doc_add_sentence(doc, ids, tf);
    }

    printf("Documento ID: %d\n", doc->doc_id);
    printf("Numero de frases: %d\n", doc->num_sentences);

    doc_free(doc);
    matrix_str_free(tokens);
    return 0;
}
