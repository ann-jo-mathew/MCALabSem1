#include <stdio.h>
#include <stdlib.h>

char* readString() {
    int capacity = 5;      // initial size
    int length = 0;
    char *str = (char*) malloc(capacity * sizeof(char));
    if (str == NULL) {
        printf("Memory not allocated.\n");
        exit(1);
    }
    char ch;
    printf("Enter string: ");
    while ((ch = getchar()) != '\n') {		// Read characters one by one
        str[length++] = ch;
        if (length == capacity) {	// If length reaches capacity, expand memory
            capacity *= 2; 		 // double the size
            str = (char*) realloc(str, capacity * sizeof(char));
            if (str == NULL) {
                printf("Memory reallocation failed.\n");
                exit(1);
            }
        }
    }
    str[length] = '\0';  // add null terminator at end of string
    return str;
}
void displayVarchar(char *str) {		// Function to display the string
    printf("You entered: %s\n", str);
}
int main() {
    char *varchar;
    varchar = readString();   //Read dynamic string
    displayVarchar(varchar);   
    free(varchar);             //Frees the allocated memory
    printf("Memory freed successfully.\n");
    return 0;
}

