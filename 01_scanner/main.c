#include "defs.h"
#define _extern
#include "data.h"
#undef _extern
#include "decl.h"
#include <errno.h> // Defines macros to represent a specific set of errors

// Initialize global variables
static void init() {
    Line = 1; // To keep track of current line number in the input file.
    Putback = '\n'; // Putback character.
}

// Print out the usage if started incorrectly
static void usage(char *prog) {
    fprintf(stderr, "Usage: %s infile\n", prog);
    exit(1);
}

// List of Printable tokens
char *tokstr[] = { 
    "+", 
    "-", 
    "*", 
    "/", 
    "{", 
    "}", 
    "(", 
    ")",
    "intlit",
    "identifier"
};

static void scanfile() {
    struct token T;
    
    // Scan till we keep finding a token.
    while(scan(&T)) {
        if(T.token == T_INTLIT) {
            printf("Token %s",tokstr[T.token]);
            printf(", value %d", T.intval);
        } else if(T.token == T_IDENTIFIER) {
            printf("Token %s",tokstr[T.token]);
            printf(", %s", T.identifierStr);
        } else {
            printf("Token %s",tokstr[T.token]);
        }
        printf("\n");
    }
}

void main(int argc, char *argv[]) {
    // If number of arguments passed to program are not 2
    if(argc != 2){
        usage(argv[0]);
    }

    // Initialize 
    init();

    // Could not open file.
    if((Infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scanfile();
    exit(0); // Success.
}