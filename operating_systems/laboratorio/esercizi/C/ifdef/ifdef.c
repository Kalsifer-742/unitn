#include <stdio.h>
#define ITER 5
#define POW(A) A*A

int main(int argc, char **argv) {
    #ifdef DEBUG
        printf("%d\n", argc);
        printf("%s\n", argv[0]);
    #endif
    
    int res = 1;
    for (int i = 0; i < ITER; i++)
    {
        res *= POW(argc);
    }
    return res;
}