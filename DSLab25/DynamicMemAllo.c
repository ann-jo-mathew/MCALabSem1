#include <stdio.h>
#include <stdlib.h>  //header for malloc, calloc, free
// Function to demonstrate malloc()
void demoMalloc(int n) {
    int i,*ptr;
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory Aloocation not successful(malloc)\n");
        return;
    }
    printf("Memory successfully allocated(malloc)\n");
    // Assign values
    for (i = 0; i < n; i++) {
        ptr[i] = i + 1;
    }
	// Display values
    printf("Elements of the array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(ptr);
    printf("Memory freed for malloc block.\n\n");
}
// Function to demonstrate calloc()
void demoCalloc(int n) {
    int i,*ptr;
    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation unsuccessful(calloc)\n");
        return;
    }
    printf("Memory successfully allocated(calloc)\n");
    // Display initial values (should be 0)
    printf("Elements of the array (initialized to 0): ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    // Assign new values
    for (i = 0; i < n; i++) {
        ptr[i] = (i + 1) * 10;
    }
    // Display new values
    printf("Updated array elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    // Free allocated memory
    free(ptr);
    printf("Memory freed for calloc block.\n\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    demoMalloc(n);
    demoCalloc(n);
    return 0;
}

