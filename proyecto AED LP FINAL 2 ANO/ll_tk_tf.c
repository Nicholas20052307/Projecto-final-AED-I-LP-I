#include <stdlib.h>
#include "ll_tk_tf.h"

LL_TK_TF* ll_tk_tf_create(void) {
    LL_TK_TF *list = (LL_TK_TF*) malloc(sizeof(LL_TK_TF));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void ll_tk_tf_append(LL_TK_TF *list, MATRIX_INT *ids, MATRIX_INT *tf) {
    if (!list) return;

    TK_TF_NODE *node = (TK_TF_NODE*) malloc(sizeof(TK_TF_NODE));
    node->ids = ids;
    node->tf = tf;
    node->next = NULL;

    if (list->tail) {
        list->tail->next = node;
    } else {
        list->head = node;
    }

    list->tail = node;
    list->size++;
}

void ll_tk_tf_free(LL_TK_TF *list) {
    if (!list) return;

    TK_TF_NODE *cur = list->head;
    while (cur) {
        TK_TF_NODE *next = cur->next;
        matrix_int_free(cur->ids);
        matrix_int_free(cur->tf);
        free(cur);
        cur = next;
    }
    free(list);
}
