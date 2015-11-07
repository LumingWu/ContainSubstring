#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ContainSubstring.h"

/**
 * This main is just a format for testing the method.
 **/
int main(int argc, char** argv) {
    char* string1 = "ADSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "DDSADASDASDASDSADSADSADASDAS"
                    "CBABACBCBA";
    char* string2 = "CBABACBCBA";
    /*printf("%s\n", GIVE_A_NAME(string1)? "true" : "false");*/
    /*printf("%zu, %zu, %zu\n", strlen(HEADER1), strlen(HEADER2), strlen(HEADER3));*/
    /*print_containString_DFA("abc", "abc", "contain_abc");*/
    
    char* string = make_containSubstring_DFA(string2, UPPER_CASE_ALPHABET_SYMBOLS, NULL);
    printf("%s\n", string);
    printf("String length: %zu\n", strlen(string));
    free(string);
    //printf("String: %s\nContains substring: %s.\t%s\n", string1, string2, GIVE_A_NAME(string1)? "true" : "false");
    //printf("%s\n", containSubstring_Dummy(string1, string2)? "true" : "false");
    return (EXIT_SUCCESS);
}

