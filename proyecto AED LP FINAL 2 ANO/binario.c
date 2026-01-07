#include "binario.h"
#include <stdlib.h>

/**
 * Guarda una lista LL_TK_TF en binario.
 * Complejidad: O(n), siendo n el número de nodos.
 */
void guardar_ll_tk_tf_bin(FILE *f, LL_TK_TF *lista) {
    fwrite(&lista->num_nodos, sizeof(int), 1, f);

    LL_NODE *actual = lista->head;
    while (actual != NULL) {
        /* Guardar número de tokens */
        fwrite(&actual->ids->cols, sizeof(int), 1, f);

        /* Guardar IDs */
        fwrite(actual->ids->data,
               sizeof(int),
               actual->ids->cols,
               f);

        /* Guardar TF */
        fwrite(actual->tf->data,
               sizeof(int),
               actual->tf->cols,
               f);

        actual = actual->next;
    }
}

/**
 * Carga una lista LL_TK_TF desde binario.
 * Complejidad: O(n).
 */
LL_TK_TF *cargar_ll_tk_tf_bin(FILE *f) {
    int num_nodos;
    fread(&num_nodos, sizeof(int), 1, f);

    LL_TK_TF *lista = crear_ll_tk_tf();

    for (int i = 0; i < num_nodos; i++) {
        int num_tokens;
        fread(&num_tokens, sizeof(int), 1, f);

        MATRIX_INT *ids = crear_matrix_int(1, num_tokens);
        MATRIX_INT *tf  = crear_matrix_int(1, num_tokens);

        fread(ids->data, sizeof(int), num_tokens, f);
        fread(tf->data,  sizeof(int), num_tokens, f);

        insertar_nodo_ll(lista, ids, tf);
    }

    return lista;
}

/**
 * Guarda un documento completo en binario.
 * Complejidad: O(n).
 */
int guardar_documento_bin(const char *filename, DOC *doc) {
    FILE *f = fopen(filename, "wb");
    if (!f) return 0;

    fwrite(&doc->id, sizeof(int), 1, f);
    fwrite(&doc->num_frases, sizeof(int), 1, f);

    guardar_ll_tk_tf_bin(f, doc->lista);

    fclose(f);
    return 1;
}

/**
 * Carga un documento desde binario.
 * Complejidad: O(n).
 */
DOC *cargar_documento_bin(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;

    DOC *doc = malloc(sizeof(DOC));

    fread(&doc->id, sizeof(int), 1, f);
    fread(&doc->num_frases, sizeof(int), 1, f);

    doc->lista = cargar_ll_tk_tf_bin(f);

    fclose(f);
    return doc;
}
