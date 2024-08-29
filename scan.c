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

static int skip(void) {
    int c;

    c = next();
    while(' '==c||'\t'==c || '\n'==c || '\r' == c || '\r' ==c) {
        c = next();
    }
    return(c);
}

int scan(struct token *t) {
    int c;

    c = skip();

    switch(c) {
        case EOF:
            return (0);
        case '+':
            t->token=T_PLUS; 
            break;
        case '-';
            t->token = T_MINUS;
            break;
        case '*':
            t->token=T_STAR;
            break;
        case '/':
            t->token=T_SLASH;
            break;
        default:
    }
    return (1);
}