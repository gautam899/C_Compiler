#ifndef _extern
    #define _extern extern
#endif

#define TEXTLEN     512

_extern int Line;
_extern int Putback;
_extern FILE *Infile;
_extern char Text[TEXTLEN + 1]; // Global buffer to store identifiers.
