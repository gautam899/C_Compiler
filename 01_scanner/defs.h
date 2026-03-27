#include<stdlib.h> // Provides functions for memory allocation, process control etc.
#include<stdio.h> // Provides necessary declarations, macros, variables for performing input and output operations
#include<string.h> // Provides builtin functions to manipulate strings
#include<ctype.h> // Provides functionalities to manipulating indivisual characters.

// Tokens
enum {
    T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};

// Token structure
struct token {
    int token;
    int intval;
};