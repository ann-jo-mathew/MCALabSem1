#include <stdio.h>
#include <string.h>

void sortStrings(char arr[][20], int n) {
    char temp[20];
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int binarySearchString(char arr[][20], int n, char key[]) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(arr[mid], key);

        if(cmp == 0)
            return mid; // found
        else if(cmp < 0)
            low = mid + 1; // search right half
        else
            high = mid - 1; // search left half
    }

    return -1; // not found
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    char arr[n][20];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    // Sort the strings before searching
    sortStrings(arr, n);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    char key[20];
    printf("Enter the string to search: ");
    scanf("%s", key);

    int index = binarySearchString(arr, n, key);
    if(index != -1)
        printf("Element %s found at index %d\n", key, index);
    else
        printf("Element %s not found\n", key);

    return 0;
}

