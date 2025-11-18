#include <stdio.h>
#include <stdlib.h>                                            
int* readNumbers(int n) {				// Function to read n integers using malloc
    int *arr = (int*)malloc(n*sizeof(int));		//dynamic memory allocation
    if (arr == NULL) {
        printf("Memory not allocated.\n");	//checking if memory is allocated or not
        exit(1); 
    }
    printf("Enter %d integers:\n", n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr; 
}                                                 
float calculateMean(int *arr, int n) {		// Function to calculate mean
    float sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}                                               
void freeMemory(int *arr) {			// Function to free allocated memory
    free(arr);
    printf("Memory freed successfully.\n");
}
int main() {
    int n;
    float mean;
    int *numbers;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    numbers = readNumbers(n);           
    mean = calculateMean(numbers, n);   
    printf("Mean = %.2f\n", mean);
    freeMemory(numbers);                
    return 0;
}

