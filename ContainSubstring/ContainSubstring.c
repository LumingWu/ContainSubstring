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

bool containSubstring_Dummy(char main_string[], char substring[]){
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

bool containSubstringP_Dummy(char* main_string, char* substring){
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
void make_DFA(char substring[], char symbols[]){
    size_t length = strlen(substring);
    size_t jcap = strlen(symbols);
    char temp[length];
    strcpy(temp, substring);
    printf("%s", HEADER);
    
    /* Start state and accept state needs to be handle differently for performances */
    if(length > 1){
        printf("%s", START_NOT_ACCEPT_1);
        printf("%c", substring[0]);
        printf("%s", START_NOT_ACCEPT_2);
    }
    
    int i = 1, j, k;
    int icap = length - 1;
    /* i and icap loops through all states except start state and accept state. */
    while(i < icap){
        printf("%s", TRANSITION1);
        printf("%d", i);
        printf("%s", TRANSITION2);
        printf("%c", substring[i]);
        printf("%s", TRANSITION3);
        j = 0;
        /* j and jcap loops through the set of symbols */
        while(j < jcap){
            if(substring[i] == symbols[j]){
                j = j + 1;
                continue;
            }
            temp[i] = symbols[j];
            k = 0;
            /* k loops through all the cases  */
            while(k < i){
                if(memcmp(temp + k + 1, substring, i - k) == 0){
                    printf("%s", BEST_STATE_OPEN);
                    printf("%c", symbols[j]);
                    printf("%s", BEST_STATE_FOUND_1);
                    printf("%d", i - k);
                    printf("%s", BEST_STATE_FOUND_2);
                    break;
                }
                k = k + 1;
            }
            if(k == i){
                printf("%s", BEST_STATE_OPEN);
                printf("%c", symbols[j]);
                printf("%s", BEST_STATE_NOT_FOUND);
            }
            temp[i] = substring[i];
            j = j + 1;
        }
        printf("%s", TRANSITION_END);
        i = i + 1;
    }
    
    /* Accept state. Also treated as transition state.*/
    printf("%s", TRANSITION1);
    printf("%d", icap);
    printf("%s", TRANSITION2);
    printf("%c", substring[icap]);
    printf("%s", ACCEPT_STATE_TRANSITION_3);
    j = 0;
    /* j and jcap loops through the set of symbols */
    while(j < jcap){
        if(substring[i] == symbols[j]){
            j = j + 1;
            continue;
        }
        temp[i] = symbols[j];
        k = 0;
        /* k loops through all the cases  */
        while(k < i){
            if(memcmp(temp + k + 1, substring, i - k) == 0){
                printf("%s", BEST_STATE_OPEN);
                printf("%c", symbols[j]);
                printf("%s", BEST_STATE_FOUND_1);
                printf("%d", i - k);
                printf("%s", BEST_STATE_FOUND_2);
                break;
            }
            k = k + 1;
        }
        if(k == i){
            printf("%s", BEST_STATE_OPEN);
            printf("%c", symbols[j]);
            printf("%s", BEST_STATE_NOT_FOUND);
        }
        temp[i] = substring[i];
        j = j + 1;
    }
    printf("%s", FOOTER);
}

bool GIVE_A_NAME(char string[]){
	size_t icap = strlen(string);
	char c;
	int i = 0;
	int state = 0;
	while(i < icap){
		switch(state){
			case 0:
				c = string[i];
				if(c == '0'){
					state = state + 1;
				}
				break;
			case 1:
				c = string[i];
				if(c == '1'){
					state = state + 1;
				}
				else{
					switch(c){
						case '0':
							state = 1;
					}
				}
				break;
			case 2:
				c = string[i];
				if(c == '0'){
					state = state + 1;
				}
				else{
					switch(c){
						case '1':
							state = 0;
					}
				}
				break;
			case 3:
				c = string[i];
				if(c == '1'){
					state = state + 1;
				}
				else{
					switch(c){
						case '0':
							state = 1;
					}
				}
				break;
			case 4:
				c = string[i];
				if(c == '0'){
					state = state + 1;
				}
				else{
					switch(c){
						case '1':
							state = 0;
					}
				}
				break;
			case 5:
				c = string[i];
				if(c == '0'){
					state = state + 1;
				}
				else{
					switch(c){
						case '1':
							state = 4;
					}
				}
				break;
			case 6:
				c = string[i];
				if(c == '1'){
					return true;
				}
				else{
					switch(c){
						case '0':
							state = 1;
					}
				}
				break;
		}
		i = i + 1;
	}
	return false;
}