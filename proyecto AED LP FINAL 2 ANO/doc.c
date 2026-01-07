#include <stdlib.h>
#include "doc.h"

DOC* doc_create(int doc_id) {
    DOC *doc = (DOC*) malloc(sizeof(DOC));
    doc->doc_id = doc_id;
    doc->num_sentences = 0;
    doc->list = ll_tk_tf_create();
    return doc;
}

void doc_add_sentence(DOC *doc, MATRIX_INT *ids, MATRIX_INT *tf) {
    if (!doc) return;
    ll_tk_tf_append(doc->list, ids, tf);
    doc->num_sentences++;
}

void doc_free(DOC *doc) {
    if (!doc) return;
    ll_tk_tf_free(doc->list);
    free(doc);
}
