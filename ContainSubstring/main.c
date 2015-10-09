#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * This main is just a format for testing the method.
 **/
int main(int argc, char** argv) {
    char* string1 = "saskdjaskdjaskdjasdmasos";
    char* string2 = "zsasad";
    printf("The first string is: %s\nThe second string is: %s\nThe answer is %s\n", string1, string2, 
            ContainSubstring_Dummy(string1,string2)? "true" : "false");
    make_DFA(string2);
    return (EXIT_SUCCESS);
}

