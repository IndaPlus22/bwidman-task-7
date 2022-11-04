#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

struct NameHash {
	char* name;
	int data;
	UT_hash_handle hh;
};

int main() {
    FILE* file = fopen("test.txt", "r");
    int n;
    fscanf(file, "%d", &n);
    // scanf("%d", &n);
    
    // Allocate n strings with space for two 20 character names
    // seperated by a space and ending with a null character each
    char** names = malloc(n * sizeof(char*));

    // Store all first names
    for (int i = 0; i < n; i++) {
        char* first_name = malloc(22);
        fscanf(file, "%s", first_name);
        // scanf("%s", first_name);
        names[i] = first_name;
    }

	struct NameHash* hashtable = NULL;
    
    // Receive last names
    for (int i = 0; i < n; i++) {
        char* surname = malloc(21);
        fscanf(file, "%s", surname);
        // scanf("%s", surname);

        strcat(names[i], " ");
        strcat(names[i], surname);

		struct NameHash* nameHash;
		HASH_FIND_STR(hashtable, names[i], nameHash);
		if (nameHash == NULL) {
			nameHash = malloc(sizeof(struct NameHash));
			nameHash->name = names[i];
			// nameHash->name = i;
			nameHash->data = 0;
			HASH_ADD_KEYPTR(hh, hashtable, nameHash->name, strlen(nameHash->name), nameHash);
			// HASH_ADD_INT(hashtable, name, nameHash);
		}
    }
	// Test: does not duplicate keys
	// struct NameHash* nameHash;
	// int a = 1;
	// HASH_FIND_INT(hashtable, &a, nameHash);
	// if (nameHash == NULL) {
	// 	nameHash = malloc(sizeof(struct NameHash));
	// 	nameHash->name = 1;
	// 	nameHash->data = 0;
	// 	HASH_ADD_INT(hashtable, name, nameHash);
	// }

    printf("%u", HASH_COUNT(hashtable));

    free(names);
    return 0;
}