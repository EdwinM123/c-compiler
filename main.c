void main(int argc, char *argv[]) { 
    int(); 
    Infile = fopen(argv[1], "r"); 
    scanfile();
    exit(0);
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