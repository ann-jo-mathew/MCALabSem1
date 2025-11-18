#include<stdio.h>
void swap(int a[],int i,int j){
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void heapify(int a[],int n,int i){
	int m=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n&&a[m]<a[l])
		m=l;
	if(r<n&&a[m]<a[r])
		m=r;
	if(m!=i){
		swap(a,i,m);
		heapify(a,n,m);
	}
}
int insert(int a[],int n,int e){
	n++;
	a[n]=e;
	int i=n;
	while(i>0&&a[i]>a[(i-1)/2]){
		swap(a,i,(i-1)/2);
		i=(i-1)/2;		
	}
	return n;
}
int delet(int a[],int n){
	printf("\nPriority: %d",a[0]);
	a[0]=a[n--];
	heapify(a,n,0);
	return n;
}
int main(){
	int i,a[10],n=-1;
	n=insert(a,n,10);
	n=insert(a,n,20);
	n=insert(a,n,5);
	n=insert(a,n,6);
	n=insert(a,n,1);
	n=insert(a,n,8);
	n=delet(a,n);
	n=delet(a,n);
	/*printf("Enter elemenets ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);*/
	/*printf("Max heap:\n");
	for(i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);*/
	/*printf("Heap Sort\n");
	for(i=n-1;i>0;i--){
		swap(a,0,i);
		heapify(a,i,0);
	}
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);*/
	return 0;
}
