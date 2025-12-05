#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
char**** get_document(char* text) {

    char**** document = NULL;
    int paragraph_count = 0;

    // --- Split paragraphs on '\n' ---
    char* saveptr_par;
    char* paragraph = strtok_r(text, "\n", &saveptr_par);

    while (paragraph) {

        document = realloc(document, sizeof(char*) * (paragraph_count + 1));

        char*** paragraph_struct = NULL;
        int sentence_count = 0;

        // --- Split sentences on '.' ---
        char* saveptr_sent;
        char* sentence = strtok_r(paragraph, ".", &saveptr_sent);

        while (sentence) {

            paragraph_struct = realloc(paragraph_struct,
                                       sizeof(char**) * (sentence_count + 1));

            char** sentence_struct = NULL;
            int word_count = 0;

            // --- Split words on space ---
            char* saveptr_word;
            char* word = strtok_r(sentence, " ", &saveptr_word);

            while (word) {

                sentence_struct = realloc(sentence_struct,
                                          sizeof(char*) * (word_count + 1));

                sentence_struct[word_count] = malloc(strlen(word) + 1);
                strcpy(sentence_struct[word_count], word);

                word_count++;

                word = strtok_r(NULL, " ", &saveptr_word);
            }

            paragraph_struct[sentence_count] = sentence_struct;
            sentence_count++;

            sentence = strtok_r(NULL, ".", &saveptr_sent);
        }

        document[paragraph_count] = paragraph_struct;
        paragraph_count++;

        paragraph = strtok_r(NULL, "\n", &saveptr_par);
    }

    return document;
}

char*** kth_paragraph(char**** document, int k) {
    return document[k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m - 1][k - 1];
}

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document,
                                                int k, int m, int n) {
    return document[n - 1][m - 1][k - 1];
}


