#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ContainSubstring.h"


bool ContainSubstring_Brute(char* main_string, char* substring){
    printf("Size of main string: %d\nSize of substring: %d\n",
            strlen(*main_string), strlen(*substring));
    /*
    while(*main_string != '\0'){
        if(*main_string == *substring){
            char* main_temp = main_string + 1;
            char* sub_temp = substring + 1;
            while(){
                
            }
        }
        main_string = main_string + 1;
    }*/
    return false;
}