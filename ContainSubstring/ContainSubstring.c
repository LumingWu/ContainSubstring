#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ContainSubstring.h"

size_t pointer_sizeof(char* string){
    size_t size = 0;
    while(*string != '\0'){
        size = size + 1;
        string = string + 1;
    }
    return size;
}

bool ContainSubstring_Brute(char main_string[], char substring[]){
    /* This is similar to the pointer version, much shorter and simpler */
    size_t main_size = strlen(main_string);
    size_t sub_size = strlen(substring);
    int i, j, icap;
    icap = main_size - sub_size + 2;
    bool result;
    for(i = 0; i < icap; i++){
        if(main_string[i] == substring[0]){
            result = true;
            for(j = 0; j < sub_size; j++){
                if(main_string[i + j] != substring[j]){
                    result = false;
                    break;
                }
            }
            if(result){
                return true;
            }
        }
    }
    return false;
}

bool ContainSubstringP_Brute(char* main_string, char* substring){
    /* I find it is better to find the size first when substring can also be O(n) length */
    size_t sub_size = pointer_sizeof(substring);
    int i, j, icap;
    /* There is no point in searching when the rest of the main_string is not long enough */
    icap = pointer_sizeof(main_string) - sub_size + 2;
    bool result;
    for(i = 0; i < icap; i++){
        if(*(main_string + i) == *substring){
            result = true;
            for(j = 0; j < sub_size; j++){
                if(*(main_string + i + j) != *(substring + j)){
                    result = false;
                    break;
                }
            }
            if(result){
                return true;
            }
        }
    }
    return false;
}

