#include <stdio.h>
#include <stdlib.h>                             
int* readNumbers(int n) {
	int i;		// Function to read n numbers using calloc
    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        exit(1);			//terminate program if memory allocation fails
    }
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    return arr;
}                                                              
int mode(int *arr, int n) {		// Function to find the mode
    int i,j,mode = arr[0], maxCount = 0;
    for (i = 0; i < n; i++) {
        int count = 0;
        for (j = 0; j < n; j++) {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    return mode;
}                                                                
int main() {
    int n, m;
    int *numbers;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    numbers = readNumbers(n);      
    m = mode(numbers, n);   
    printf("Mode = %d\n",m);
    free(numbers);        //frees the memory allocated 
    return 0;
}

