# ContainSubstring
A implementation of using a DFA to search for substring.

I found there is no way to have a function that can implement DFA and find many different substrings.
So I decided to write a code that can write code for a DFA that can search for only one specific substring.

It should be the fastest contain() function that specific substring.

/* I think i am confused here */
It is useful when a user often search for a specific substring. Similar to the idea of a cache, just have a set of substrings that the user searched. For a certain requirments, create such DFA and run it for next run. And the DFA can be store in a hashtable.

IDE - Netbean, Compiler - Cygwin
