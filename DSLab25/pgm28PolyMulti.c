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
void Multi(int a[],int b[],int n,int m){  
	int i,j,c[60]={0};  
    int d=n+m;         
    for(i=n;i>=0;i--){           
        for(j=m;j>=0;j--){       
            c[i+j] += a[i]*b[j]; 
        }
    }
    printf("\nProduct of Polynomials:\n");
    disp(c,d);                             
}
int main(){
	int a[30],b[30],n,m,c,i;
	m=read(a,m);
	n=read(b,n);
	disp(a,m);
	disp(b,n);
	Multi(a,b,m,n);     
	return 0;
}
