#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_str.h"

MATRIX_STR* matrix_str_create(int rows) {
    // Reserva memoria para la estructura MATRIX_STR
    MATRIX_STR *m = (MATRIX_STR*) malloc(sizeof(MATRIX_STR));
    if (!m) return NULL;

    // Inicializa los campos de la estructura
    m->rows = rows;
    m->used = 0;

    // Reserva memoria para el array de punteros a strings
    m->data = (char**) malloc(rows * sizeof(char*));
    if (!m->data) {
        free(m);
        return NULL;
    }

    return m;
}

void matrix_str_resize(MATRIX_STR *m, int new_size) {
    if (!m || new_size <= m->rows) return;

    // Redimensiona el array de strings manteniendo su contenido
    char **tmp = (char**) realloc(m->data, new_size * sizeof(char*));
    if (!tmp) return;

    m->data = tmp;
    m->rows = new_size;
}

int matrix_str_insert(MATRIX_STR *m, const char *str) {
    if (!m || !str) return 0;

    // Si la matriz está llena, se duplica la capacidad
    if (m->used == m->rows) {
        matrix_str_resize(m, m->rows * 2);
    }

    // Copia la string a memoria dinámica
    m->data[m->used] = strdup(str);
    if (!m->data[m->used]) return 0;

    m->used++;
    return 1;
}

int matrix_str_remove(MATRIX_STR *m, int index) {
    if (!m || index < 0 || index >= m->used) return 0;

    // Libera la memoria de la string que se elimina
    free(m->data[index]);

    // Desplaza las strings siguientes una posición hacia atrás
    for (int i = index; i < m->used - 1; i++) {
        m->data[i] = m->data[i + 1];
    }

    m->used--;
    return 1;
}

void matrix_str_search(MATRIX_STR *m, const char *pattern) {
    if (!m || !pattern) return;

    printf("Buscar: \"%s\"\n", pattern);

    // Recorre todas las strings y comprueba si contienen el patrón
    for (int i = 0; i < m->used; i++) {
        if (strstr(m->data[i], pattern)) {
            printf("[%d] %s\n", i, m->data[i]);
        }
    }
}

void matrix_str_print(MATRIX_STR *m) {
    if (!m) return;

    // Muestra por consola todas las strings almacenadas
    for (int i = 0; i < m->used; i++) {
        printf("[%d] %s\n", i, m->data[i]);
    }
}

void matrix_str_free(MATRIX_STR *m) {
    if (!m) return;

    // Libera cada string individual
    for (int i = 0; i < m->used; i++) {
        free(m->data[i]);
    }

    // Libera el array y la estructura principal
    free(m->data);
    free(m);
}
