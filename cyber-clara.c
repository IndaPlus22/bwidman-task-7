#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    // Allocate n strings with 20 characters
    char** names = malloc(n * 20 * sizeof(char));

    // Name count without duplicates
    int count = 0;

    // Go through every string and check if it already exists in the array
    for (int i = 0; i < n; i++) {
        char* name;
        scanf("%c", &name);

        _Bool isNew = 1;
        for (int j = 0; j < i; j++)
            if (names[j] == name) // Already exists in array
                isNew = 0;
        
        if (isNew)
            count++;
    }

    printf("%d", count);

    return 0;
}