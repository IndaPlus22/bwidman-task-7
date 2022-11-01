#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    // Allocate n strings with space for two 20 character names seperated by one character each
    char** names = malloc(n * (20 * 2 + 1));

    // Name count without duplicates
    int count = 0;

    // Store all first names
    for (int i = 0; i < n; i++) {
        char* first_name = malloc(20);
        scanf("%s", first_name);
        names[i] = first_name;
    }

    for (int i = 0; i < n; i++) {
        char* surname = malloc(20);
        scanf("%s", surname);
        
        strcat(names[i], ",");
        strcat(names[i], surname);

        // Check every previous full name and say it's new if it doesn't match any
        _Bool isNew = 1;
        for (int j = 0; j < i; j++)
            if (strcmp(names[i], names[j]) == 0) // Already exists in array
                isNew = 0;
        
        if (isNew)
            count++;
    }

    printf("%d", count);

    return 0;
}