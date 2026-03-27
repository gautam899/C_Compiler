#include "defs.h"
#include "data.h"
#include "decl.h"

static int char_pos(char *s, int c) {
    char *p;

    // strchr function in c return a pointer to the first 
    // occurrence of c in s. If not found strchr return NULL pointer.
    p = strchr(s, c);

    return p ? p - s : -1;
}

static int next(void) {
    int c;

    // If we ended up reading an extra character last time i.e we 
    // have a character in putback, we use the putback character.
    if(Putback) {
        c = Putback;
        Putback = 0;
        return c;
    }

    // Read character from the input file.
    c = fgetc(Infile);

    // If it's a next line character. Increment the line number.
    if('\n' == c){
        Line++;
    }
    return c;
}

// Scan a integer literal from the input file
static int scanint(int c){
    int k, val = 0;

    // Convert character to integer values.
    while((k = char_pos("0123456789", c)) >= 0) {
        val = val * 10 + k;
        c = next();
    }

    // Since we exited the while loop, we now have a non-integer character.
    // We put it back.
    Putback = c;
    return c;
}

// Putback a unwanter or extra read character for future use.
static void putback(int c){
    Putback = c;
}

static int skip(void) {
    int c;

    c = next();
    while(' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
        c = next();
    }
    return c;
}

// Scan and return the next token found in the input.
int scan(struct token *t) {
    int c;

    // skip the whitespaces, tabs etc
    c = skip();

    // Determine the token based on the input character.
    switch (c) {
        case EOF:
            return 0;
        case '+':
            t->token = T_PLUS;
            break;
        case '-':
            t->token = T_MINUS;
            break;
        case '*':
            t->token = T_STAR;
            break;
        case '/':
            t->token = T_SLASH;
            break;
        default: 
        
            // If it's a digit, scan the integer value.
            if(isdigit(c)) {
                t->intval = scanint(c);
                t->token = T_INTLIT;
                break;
            }
    }
}
