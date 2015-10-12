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
    printf("%s\n", GIVE_A_NAME(string1)? "true" : "false");
    //make_DFA(string2, BINARY_STRING_SYMBOLS);
    return (EXIT_SUCCESS);
}

