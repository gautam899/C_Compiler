#include<stdlib.h> // Provides functions for memory allocation, process control etc.
#include<stdio.h> // Provides necessary declarations, macros, variables for performing input and output operations
#include<string.h> // Provides builtin functions to manipulate strings
#include<ctype.h> // Provides functionalities to manipulating indivisual characters.

// Tokens
enum {
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_LBRACE, 
    T_RBRACE,
    T_LPAREN,
    T_RPAREN,
    T_INTLIT,
    T_IDENTIFIER,
};

// Token structure
struct token {
    int token;
    // Token value can be either an Integer or a string(identifer or keyword)
    union {
        int intval;
        char identifierStr[20];
    };
};