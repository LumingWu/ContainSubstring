#ifndef CONTAINSUBSTRING_H
#define	CONTAINSUBSTRING_H

#define BINARY_STRING_SYMBOLS "01"
#define ARABIC_NUMBER_SYMBOLS "0123456789"
#define LOWER_CASE_ALPHABET_SYMBOLS "abcdefghijklmnopqrstuvwxyz"
#define UPPER_CASE_ALPHABET_SYMBOLS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define HEADER "bool GIVE_A_NAME(char string[]){\n\tsize_t icap = strlen(string);\n\tchar c;\n\tint i = 0;\n\tint state = 0;\n\twhile(i < icap){\n\t\tswitch(state){\n\t\t\t"

#define START_NOT_ACCEPT_1 "case 0:\n\t\t\t\tc = string[i];\n\t\t\t\tif(c == '"
#define START_NOT_ACCEPT_2 "'){\n\t\t\t\t\tstate = state + 1;\n\t\t\t\t}\n\t\t\t\tbreak;\n\t\t\t"

#define TRANSITION1 "case "
#define TRANSITION2 ":\n\t\t\t\tc = string[i];\n\t\t\t\tif(c == '"
#define TRANSITION3 "'){\n\t\t\t\t\tstate = state + 1;\n\t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\tswitch(c){"

#define BEST_STATE_OPEN "\n\t\t\t\t\t\tcase '"
#define BEST_STATE_FOUND_1 "':\n\t\t\t\t\t\t\tstate = "
#define BEST_STATE_FOUND_2 ";"
#define BEST_STATE_NOT_FOUND "':\n\t\t\t\t\t\t\tstate = 0;"

#define TRANSITION_END "\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tbreak;\n\t\t\t"

#define ACCEPT_STATE_TRANSITION_3 "'){\n\t\t\t\t\treturn true;\n\t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\tswitch(c){"

#define FOOTER "\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tbreak;\n\t\t}\n\t\ti = i + 1;\n\t}\n\treturn false;\n}"
/**
 * This ContainSubstring uses dummy method.
 * @param main_string
 * @param substring
 * @return true if the main string contains the substring. Otherwise, false.
 */
bool containSubstring_Dummy(char main_string[], char substring[]);
bool containSubstringP_Dummy(char* main_string, char* substring);
/**
 * This function makes a DFA 
 * @param main_string
 * @param substring
 * @return true if the main string contains the substring. Otherwise, false.
 */
void make_DFA(char substring[], char symbols[]);
void makeP_DFA(char* substring);

/**
 * This function will be define by the console output for testing.
 **/
bool GIVE_A_NAME(char string[]);

/**
 * A helper method that finds the size of a pointer that points to the beginning of a string.
 * This function expects the string is null temrinated
 * @param string
 * @return the size of the string.
 */
size_t pointer_sizeof(char* string);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONTAINSUBSTRING_H */

