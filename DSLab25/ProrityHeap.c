#include <stdio.h>
// Swap function
void swap(int a[], int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
// Heapify subtree rooted at i for heap size n
void heapify(int a[], int n, int i){
    int m = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l <= n && a[l] > a[m])
        m = l;
    if(r <= n && a[r] > a[m])
        m = r;
    if(m != i){
        swap(a, i, m);
        heapify(a, n, m);
    }
}
// Priority Queue: Insert element (percolate up)
int insert(int a[], int n, int e){
	n++;
    a[n] = e; // add at end
    int i = n;
    while(i > 0 && a[(i-1)/2] < a[i]){ // compare with parent
        swap(a, i, (i-1)/2);
        i = (i-1)/2; // move up
    }
    return n; // new size
}
// Priority Queue: Delete highest priority (root)
int deleteHighest(int a[], int n){
    if(n==-1){
        printf("Queue is empty!\n");
        return n;
    }
    printf("Deleted highest priority: %d\n", a[0]);   
    a[0]=a[n]; // replace root with last
    n--;
    heapify(a, n, 0); // fix heap
    return n;
}
// Display Priority Queue
void display(int a[], int n){
	int i;
    if(n == -1){
        printf("Queue is empty!\n");
        return;
    }
    for(i = 0; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main(){
    int arr[50], n = -1, choice, val;

    while(1){
        printf("\n1. Insert into Priority Queue\n2. Delete Highest Priority\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                n = insert(arr, n, val);
                break;
            case 2:
                n = deleteHighest(arr, n);
                break;
            case 3:
                printf("Priority Queue: ");
                display(arr, n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

