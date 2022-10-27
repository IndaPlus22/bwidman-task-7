#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    // Allocate n strings with 20 characters each
    char** names = malloc(n * 20);

    // Name count without duplicates
    int count = 0;

    // Go through every string and check if it already exists in the array
    for (int i = 0; i < n; i++) {
        char* name = malloc(20);
        scanf("%s", name);
        names[i] = name;

        _Bool isNew = 1;
        for (int j = 0; j < i; j++)
            if (strcmp(names[j], name) == 0) // Already exists in array
                isNew = 0;
        
        if (isNew == 1)
            count++;
    }

    printf("%d", count);

    return 0;
}