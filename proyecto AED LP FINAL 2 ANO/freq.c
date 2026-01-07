#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freq.h"

int count_frequencies(MATRIX_STR *tokens, FREQ *freq, int size) {
    int used = 0;

    for (int i = 0; i < tokens->used; i++) {
        char *current = tokens->data[i];
        int found = 0;

        for (int j = 0; j < used; j++) {
            if (strcmp(freq[j].token, current) == 0) {
                freq[j].count++;
                found = 1;
                break;
            }
        }

        if (!found && used < size) {
            freq[used].token = strdup(current);
            freq[used].count = 1;
            used++;
        }
    }
    return used;
}

void print_frequencies(FREQ *freq, int used) {
    for (int i = 0; i < used; i++) {
        printf("%s -> %d\n", freq[i].token, freq[i].count);
    }
}
