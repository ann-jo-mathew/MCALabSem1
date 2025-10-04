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
	printf("\nPolynomial is:\n");
	for(i=n;i>=0;i--){
		if(i==0)
			printf("%d",a[i]);
		else
			printf("%dx^%d + ",a[i],i);
	}
	printf("\n");
}
void sum(int a[],int b[],int n,int m){  
	int d,i,s[30],ca,cb;
	d=n>m?n:m;
		
	for(i=d;i>=0;i--){
		if(i<=n)
			ca=a[i];
		else
			ca=0;
		if(i<=m)
			cb=b[i];
		else
			cb=0;
		s[i]=ca+cb;
	} 
	printf("\nSum of Polynomials:\n"); 
	disp(s,d);                              
}
int main(){
	int a[30],b[30],n,m,c,i;
	m=read(a,m);
	n=read(b,n);
	disp(a,m);
	disp(b,n);
	sum(a,b,m,n);     
	return 0;
}
