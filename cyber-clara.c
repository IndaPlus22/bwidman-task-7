#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "khash.h"

KHASH_SET_INIT_STR(str)

int main() {
    int n;
    scanf("%d", &n);

    // Allocate n strings with space for two 20 character names
    // seperated by a space and ending with a null character each
    char** names = malloc(n * (20 * 2 + 2));

    // Store all first names
    for (int i = 0; i < n; i++) {
        char* first_name = malloc(21);
        scanf( "%s", first_name);
        names[i] = first_name;
    }

    // Initialize hashtable
    khash_t(str)* hashtable = kh_init(str);
    unsigned int k;
    int absent;

    // Receive last names, 
    for (int i = 0; i < n; i++) {
        char* surname = malloc(21);
        scanf("%s", surname);

        strcat(names[i], " ");
        strcat(names[i], surname);

        kh_put(str, hashtable, names[i], &absent);
    }

    printf("%d", kh_size(hashtable));

    free(names);
    kh_destroy(str, hashtable);

    return 0;
}