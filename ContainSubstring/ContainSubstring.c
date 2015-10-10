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
    printf("bool GIVE_A_NAME(char string[], char substring[]){\n\tsize_t icap ="
            " strlen(string) - %zu;\n\tint i = 0, j;\n\tint state = 0;\n\twhile(i "
            "< icap){\n\t\tswitch(state){\n\t\t\t", length - 1);
    
    /* Start state and accept state needs to be handle differently for performances */
    if(length > 1){
        printf("case %d:\n\t\t\t\tif(string[i] == '%c'){\n\t\t\t\t\tstate = state"
                " + 1;\n\t\t\t\t}\n\t\t\t\tbreak;\n\t\t\t", 0, substring[0]);
    }
    
    int i = 1;
    int icap = length - 1;
    while(i < icap){
        printf("case %d:\n\t\t\t\tif(string[i] == '%c'){\n\t\t\t\t\tstate "
                "= state + 1;\n\t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\t", i, substring[i]);
        printf("j = state;\n\t\t\t\t\twhile(j > 0){\n\t\t\t\t\t\tif(memcmp"
                "(string[i - j + 1], substring, j) == 0){\n\t\t\t\t\t\t\tstate = j;"
                "\n\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t}\n\t\t\t\t\t\tj = j - 1;"
                "\n\t\t\t\t\t}\n\t\t\t\t\tif(j == 0){\n\t\t\t\t\t\tstate = 0;"
                "\n\t\t\t\t\t}");
        printf("\n\t\t\t\t}\n\t\t\t\tbreak;\n\t\t\t");
        i = i + 1;
    }
    
    /* Accept state */
    printf("case %d:\n\t\t\t\tif(string[i] == '%c'){\n\t\t\t\t\treturn true;"
            "\n\t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\t", icap, substring[icap]);
    printf("j = state;\n\t\t\t\t\twhile(j > 0){\n\t\t\t\t\t\tif(memcmp"
                "(string[i - j + 1], substring, j) == 0){\n\t\t\t\t\t\t\tstate = j;"
                "\n\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t}\n\t\t\t\t\t\tj = j - 1;"
                "\n\t\t\t\t\t}\n\t\t\t\t\tif(j == 0){\n\t\t\t\t\t\tstate = 0;"
                "\n\t\t\t\t\t}");
    printf("\n\t\t\t\t}\n\t\t\t\tbreak;\n\t\t}\n\t\ti = i + 1;\n\t}\n\treturn "
            "false;\n}");
}  

bool GIVE_A_NAME(char string[], char substring[]){
	size_t icap = strlen(string) - 2;
	int i = 0, j;
	int state = 0;
	while(i < icap){
		switch(state){
			case 0:
				if(string[i] == 'd'){
					state = state + 1;
				}
				break;
			case 1:
				if(string[i] == 's'){
					state = state + 1;
				}
				else{
					j = state;
					while(j > 0){
						if(memcmp(string[i - j + 1], substring, j) == 0){
							state = j;
							break;
						}
						j = j - 1;
					}
					if(j == 0){
						state = 0;
					}
				}
				break;
			case 2:
				if(string[i] == 's'){
					return true;
				}
				else{
					j = state;
					while(j > 0){
						if(memcmp(string[i - j + 1], substring, j) == 0){
							state = j;
							break;
						}
						j = j - 1;
					}
					if(j == 0){
						state = 0;
					}
				}
				break;
		}
		i = i + 1;
	}
	return false;
}