//
// Created by yura on 07.05.2021.
//

#include "Func.h"
#include <string.h>

int getInt(int* a) {
    int n;
    do {
        n = scanf("%d", a);
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (n == 0);
    return 1;
}

char* getstr() {
    char *ptr = (char *) malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';
    do {
        n = scanf("%80[^\n]", buf);

        if (n < 0) {
            free(ptr);
            ptr = NULL;
            continue;
        }
        if (n == 0)
            scanf("%*c");
        else {
            len += strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strcat(ptr, buf);
        }
    } while (n > 0);
    return ptr;
}