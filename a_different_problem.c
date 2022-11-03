#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long int a, b;
    while (scanf("%lu %lu", &a, &b) != EOF) {
        printf("%lu\n", labs(a - b));
    }
    return 0;
}