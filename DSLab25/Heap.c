#include <stdio.h>
void swap(int a[],int i,int j){		//swapping array elements passed as addresses *a gives the actual value
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
// heapify subtree rooted at i for heap size n
void heapify(int a[], int n, int i){	//the passed i represents the parent of subtree
    int m = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && a[l] > a[m])
        m = l;
    if(r < n && a[r] > a[m])
        m=r;		//finding largest among l,r and root
    if(m!=i){		//we again heapify to heapify the changed node(root before) 
        swap(a,i,m);
        heapify(a,n,m);//check if the old root's child's are heapified or it needs change
    }
}
int main(){
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) 
		scanf("%d", &a[i]);
    // Heapify every node including leaves   
	//for(i = n/2 - 1; i >= 0; i--){
    for(i = n-1; i>=0; i--){ //heapification starts from below or leaf of a tree
        heapify(a, n, i);
    }
    printf("Heapified array (max-heap):\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    
    for(i=n-1;i>=0;i--){	//Heap sort
    	swap(a,0,i);
    	heapify(a,i,0); //here hepify is done untill i-1 since the condition for if
    					//in heapify is l<n,r<n 
	}
	printf("Sorted array:\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
/*recursively heapify index 4 to ensure its children also follow heap rules.
But index 4 has no children, so recursion stops.
here since elemnt 50 has no children ,
all the if will body will not execute right then 
next iteration of this happens for(i = n/2-1; i>=0; i--){ 
//heapification starts from below or leaf of a tree
    heapify(a, n, i);
    }right now i becomes 0 
*/
