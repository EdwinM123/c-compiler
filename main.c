#include "defs.h"
#define extern_ 
#include "data.h"
#undef extern_
#include "decl.h"
#include <errno.h>

static void init() {
    Line =1;
    Putback ='\n';
}

static void usage(char *prog) {
    fprintf(stderr, "Usage: %s infile\n", prog);
    exit(1);
}

char *tokstr[] = { "+", "-", "*", "/", "intlit"};

static void scanfile() {
    struct token T;

    while(scan(&T)) {
        printf("Token %s", tokstr[T.token]);
        if(T.token == T_INTLIT) printf(", value %d", T.intvalue);
        printf("\n");
    }
}

void main(int argc, char *argv[]) { 
    if(argc!=2) usage(argv[0]);
    init(); 
    Infile = fopen(argv[1], "r"); 
    scanfile();
    scan(&Token);
    n=binexpr();
    printf("%d\n", interpretAST(n));
    exit(0);
}