#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ContainSubstring.h"

/**
 * This main is just a format for testing the method.
 **/
int main(int argc, char** argv) {
    char* string1 = "saskdsskdjaskdjasdmasos";
    char* string2 = "dss";
    //printf("%s\n", memcmp(string1 + 4,"dss", 3) == 0? "true" : "false");
    //printf("The first string is: %s\nThe second string is: %s\nThe answer is %s\n", string1, string2, 
    //        ContainSubstring_Dummy(string1,string2)? "true" : "false");
    make_DFA(string2, LOWER_CASE_ALPHABET_SYMBOLS);
    //printf("%s\n", GIVE_A_NAME(string1, string2)? "true" : "false");
    return (EXIT_SUCCESS);
}

