cmake_minimum_required(VERSION 3.16)
project(Projeto_C C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Librería común R1
add_library(core_r1
        matrix_str.c
        matrix_int.c
        tokens.c
        tokenizer.c
        tf.c
        similarity.c
)

# Tests R1
add_executable(test_r1_1 test_r1_1.c)
target_link_libraries(test_r1_1 core_r1)

add_executable(test_r1_2 test_r1_2.c)
target_link_libraries(test_r1_2 core_r1)

add_executable(test_r1_3 test_r1_3.c)
target_link_libraries(test_r1_3 core_r1)

add_executable(test_r1_4 test_r1_4.c)
target_link_libraries(test_r1_4 core_r1)

add_executable(test_r1_5 test_r1_5.c)
target_link_libraries(test_r1_5 core_r1)

add_executable(test_r1_6 test_r1_6.c)
target_link_libraries(test_r1_6 core_r1)

# Librería común R2
add_library(core_r2
        ll_tk_tf.c
)

add_executable(test_r2_1 test_r2_1.c)
target_link_libraries(test_r2_1 core_r1 core_r2)
add_library(core_r2_doc
        doc.c
)

# core_r2_doc DEPENDE de core_r2
target_link_libraries(core_r2_doc core_r2)

add_executable(test_r2_2 test_r2_2.c)
target_link_libraries(test_r2_2 core_r1 core_r2 core_r2_doc)

add_library(core_r2_sim
        doc_similarity.c
)

target_link_libraries(core_r2_sim core_r2_doc core_r2 core_r1)

add_executable(test_r2_3 test_r2_3.c)
target_link_libraries(test_r2_3 core_r1 core_r2 core_r2_doc core_r2_sim)
