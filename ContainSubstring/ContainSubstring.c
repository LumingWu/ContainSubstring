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

bool ContainSubstring_Dummy(char main_string[], char substring[]){
    /* This is similar to the pointer version, much shorter and simpler */
    size_t sub_length = strlen(substring);
    int i, j, icap;
    icap = strlen(main_string) - sub_length + 2;
    bool result;
    for(i = 0; i < icap; i++){
        if(main_string[i] == substring[0]){
            result = true;
            for(j = 0; j < sub_length; j++){
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

bool ContainSubstringP_Dummy(char* main_string, char* substring){
    /* I find it is better to find the size first when substring can also be O(n) length */
    size_t sub_length = pointer_sizeof(substring);
    int i, j, icap;
    /* There is no point in searching when the rest of the main_string is not long enough */
    icap = pointer_sizeof(main_string) - sub_length + 2;
    bool result;
    for(i = 0; i < icap; i++){
        if(*(main_string + i) == *substring){
            result = true;
            for(j = 0; j < sub_length; j++){
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

/* The algorithm is pretty simple. The number of cases is same as the length of the substring
 * The start state is going to be the first character and accept state is going to be the last character.(Substring, of course)
 * If the character match, go to next state. If not, use dummy method to find the closest state.
 * This is not clear unless you know DFA and actually attempted to draw a DFA for a given language.
 * I chose to print in console because it is easier for me. Return string is great, but there will be a lot of memory allocation.
 */
void make_DFA(char substring[]){
    size_t length = strlen(substring);
    printf("bool GIVE_A_NAME(char string[]){\n\tsize_t icap = strlen(string) - "
            "%zu;\n\tint i = 0;\n\tint state = 0;\n\twhile(i < cap){\n\t\t"
            "switch(state){\n\t\t\t", length - 1);
    
    /* Start state and accept state needs to be handle differently for performances */
    printf("case %d:\n\t\t\t\tif(string[i] == '%c'){\n\t\t\t\t\t", 0, substring[0]);
    printf("state = state + 1;");
    printf("\n\t\t\t\t}\n\t\t\t\tbreak;\n\t\t\t");
    
    int i = 1;
    int icap = length - 1;
    while(i < icap){
        printf("case %d:\n\t\t\t\tif(string[i] == '%c'){\n\t\t\t\t\t", i, substring[i]);
        
        printf("\n\t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\t");
        
        printf("\n\t\t\t\t}\n\t\t\t\tbreak;\n\t\t\t");
        i = i + 1;
    }
    
    /* Accept state */
    printf("case %d:\n\t\t\t\tif(string[i] == '%c'){\n\t\t\t\t\t", icap, substring[icap]);
    printf("return true;\n\t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\t");
    
    printf("\n\t\t\t\t}\n\t\t\t\tbreak;");
    
    printf("\n\t\t}\n\t\ti = i + 1;\n\t}\n\treturn false;\n}");
}  

bool GIVE_A_NAME(char string[]){
	size_t cap = strlen(string) - 2 + 1;
	int i = 0;
	int state = 0;
	while(i < cap){
		switch(state){
			case 0:
				if(string[i] == 'z'){
					state = state + 1;
				}
				else{
                                    int closeststate = 0;
                                    int j = state;
                                    while(j > 0){
                                        j = j - 1;
                                    }
				}
				break;
			case 1:
				if(string[i] == 'd'){
					return true;
				}
				else{
					
				}
				break;
			
		}
		i = i + 1;
	}
	return false;
}

