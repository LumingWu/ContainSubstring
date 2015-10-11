#ifndef CONTAINSUBSTRING_H
#define	CONTAINSUBSTRING_H

#define BINARY_STRING_SYMBOLS "01"
#define ARABIC_NUMBER_SYMBOLS "0123456789"
#define LOWER_CASE_ALPHABET_SYMBOLS "abcdefghijklmnopqrstuvwxyz"
#define UPPER_CASE_ALPHABET_SYMBOLS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
/**
 * This ContainSubstring uses dummy method.
 * @param main_string
 * @param substring
 * @return true if the main string contains the substring. Otherwise, false.
 */
bool ContainSubstring_Dummy(char main_string[], char substring[]);
bool ContainSubstringP_Dummy(char* main_string, char* substring);
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

