#ifndef CONTAINSUBSTRING_H
#define	CONTAINSUBSTRING_H
/**
 * This ContainSubstring uses dummy method.
 * @param main_string
 * @param substring
 * @return true if the main string contains the substring. Otherwise, false.
 */
bool ContainSubstring_Brute(char main_string[], char substring[]);
bool ContainSubstringP_Brute(char* main_string, char* substring);
/**
 * This ContainSubstring uses DFA method.
 * @param main_string
 * @param substring
 * @return true if the main string contains the substring. Otherwise, false.
 */
bool ContainSubstring_DFA(char* main_string, char* substring);

/**
 * This ContainSubstring uses recursion that is a little smarter than dummy.
 * @param main_string
 * @param substring
 * @return true if the main string contains the substring. Otherwise, false.
 */
bool ContainSubstring_Recursion(char* main_string, char* substring);

/**
 * A helper method that finds the size of a pointer that points to the beginning of a string.
 * This function expects the string is null temrinated
 * @param string
 * @return the size of the string not including the null terminator. 
 */
size_t pointer_sizeof(char* string);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONTAINSUBSTRING_H */

