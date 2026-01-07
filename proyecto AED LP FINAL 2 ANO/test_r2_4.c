#include <stdio.h>
#include "binario.h"

int main() {
    DOC *doc = crear_doc(1);

    insertar_frase_doc(doc, (int[]){0,2,3}, 3);
    insertar_frase_doc(doc, (int[]){1,3}, 2);

    guardar_documento_bin("doc.bin", doc);

    DOC *doc_cargado = cargar_documento_bin("doc.bin");

    printf("Documento cargado ID: %d\n", doc_cargado->id);
    imprimir_doc(doc_cargado);

    return 0;
}
