#include "defs.h"

static int next(void) {
    int c;

    if(Putback) {
        c=Putback;
        Putback=0;
        return c;
    }

    c=fgetc(Infile);
    if('\n' == c) Line++;
    return c;
}

static void putback(int c){
    Putback = c;
}