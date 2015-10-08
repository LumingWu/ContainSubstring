#ifndef CONTAINSUBSTRING_H
#define	CONTAINSUBSTRING_H
/**
 * This ContainSubstring uses dummy method.
 * @param main_string
 * @param substring
 * @return true if the main string contains the substring. Otherwise, false.
 */
bool ContainSubstring_Brute(char* main_string, char* substring);

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
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONTAINSUBSTRING_H */

