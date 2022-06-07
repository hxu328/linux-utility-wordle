/* Copyright (C) 2022 Hong Xu */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX 500

// remove new line characters
void trim_newline(char *trimed, char *src) {
    int length = strlen(src);
    for (int i = 0; i < length; i++) {
        char c = src[i];
        if (c != '\n') {
            char new_c[2];
            new_c[0] = c;
            new_c[1] = '\0';
            strncat(trimed, new_c, 1);
        }
    }
}

// check whether "hasnot" 0 if hasnot, 1 if has
int is_hasnot(char* trimed, char* hasnot) {
    int len_trimed = strlen(trimed);
    int len_hasnot = strlen(hasnot);
    for (int i = 0; i < len_trimed; i++) {
        for (int j = 0; j < len_hasnot; j++) {
            if (trimed[i] == hasnot[j]) {
                return 1;
            } else {
                continue;
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {  // invalid numver of arguments
        printf("wordle: invalid number of args\n");
        exit(1);
    }

    char *file_path = argv[1];  // path to the file
    char *hasnot = argv[2];     // string hasnot
    char buffer[MAX];        // store text line

    // open file
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("wordle: cannot open file\n");
        exit(1);
    }

    while (fgets(buffer, MAX, fp) != NULL) {
        char trimed[MAX] = "";
        trim_newline(trimed, buffer);  // trim new line character
        if (strlen(trimed) != 5) {
            continue;
        } else {
            if (is_hasnot(trimed, hasnot) == 0) {
                printf("%s", buffer);
            } else {
                continue;
            }
        }
    }

    // close file
    if (fclose(fp) != 0) {
        printf("wordle: cannot close file");
        exit(1);
    } else {
        exit(0);
    }

    exit(0);
}
