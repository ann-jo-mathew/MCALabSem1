/* Read and Display of polynomial
@Ann Jo Mathew
Roll No: 12
Date: 26/09/2025 */

#include<stdio.h>
int read(int a[], int n){         
	int i;
	printf("Enter the degree of polynomial: ");   
	scanf("%d",&n);
	for(i=n;i>=0;i--){
		printf("Enter coefficient for x^%d: ",i);
		scanf("%d",&a[i]);
	}
	return n;
}
void disp(int a[], int n){       
	int i;
	printf("Polynomial is:\n");
	for(i=n;i>=0;i--){
		if(i==0)
			printf("%d",a[i]);
		else if(i==1)
			printf("%dx +",a[i]);
		else
			printf("%dx^%d + ",a[i],i);
	}
}
int main(){
	int a[10],n,i;
	n=read(a,n);
	disp(a,n);
	return 0;
}
