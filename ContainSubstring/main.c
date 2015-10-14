#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ContainSubstring.h"

/**
 * This main is just a format for testing the method.
 **/
int main(int argc, char** argv) {
    char* string1 = "10101000101001";
    char* string2 = "0101001";
    //printf("%s\n", containSubstring_Dummy(string1, string2)? "true" : "false");
    //printf("%s\n", GIVE_A_NAME(string1)? "true" : "false");
    char* string = (char*)make_containSubstring_DFA(string2, BINARY_STRING_SYMBOLS, "Muhahaha");
    printf("%s\n", string);
    free(string);
    return (EXIT_SUCCESS);
}

