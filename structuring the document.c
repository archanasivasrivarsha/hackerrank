#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n){
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m){
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k){
    return Doc.data[k-1];
}

struct document get_document(char* text) {
    struct document Doc;
    Doc.paragraph_count = 0;
    Doc.data = malloc(MAX_PARAGRAPHS * sizeof(struct paragraph));

    int i = 0;

    while (text[i] != '\0') {

        /* Allocate a new paragraph */
        struct paragraph para;
        para.sentence_count = 0;
        para.data = malloc(100 * sizeof(struct sentence));

        while (text[i] != '\n' && text[i] != '\0') {

            /* Allocate a new sentence */
            struct sentence sen;
            sen.word_count = 0;
            sen.data = malloc(100 * sizeof(struct word));

            while (text[i] != '.' && text[i] != '\n' && text[i] != '\0') {

                /* Read a word: sequence of non-space characters */
                char buffer[1005];
                int bi = 0;

                while (text[i] == ' ')
                    i++;

                while (text[i] != ' ' && text[i] != '.' && text[i] != '\n' && text[i] != '\0') {
                    buffer[bi++] = text[i++];
                }
                buffer[bi] = '\0';

                /* Store the word */
                sen.data[sen.word_count].data = malloc(strlen(buffer) + 1);
                strcpy(sen.data[sen.word_count].data, buffer);
                sen.word_count++;
            }

            /* End of sentence '.' */
            if (text[i] == '.')
                i++;

            para.data[para.sentence_count] = sen;
            para.sentence_count++;
        }

        /* End of paragraph '\n' */
        if (text[i] == '\n')
            i++;

        Doc.data[Doc.paragraph_count] = para;
        Doc.paragraph_count++;
    }

    return Doc;
}

