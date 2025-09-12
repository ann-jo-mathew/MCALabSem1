#include<stdio.h>
int main(){
	int a[10],b[10],c[10],i,m,n,cnt=0;
	for(i=0;i<=9;i++)
		a[i]=0;
	for(i=0;i<=9;i++)
		b[i]=0;
	printf(“\nEnter the order of first Polynomial”);
	scanf(“%d”,&m);
	printf(“\nEnter the Co-efficient”);
	for(i=m;i>=0;i–)
	{
		scanf(“%d”,&a[i]);
	}
	printf(“\nEnter the order of Second Polynomail”);
	scanf(“%d”,&n);
	printf(“\nEnter the Co-efficient”);
	for(i=n;i>=0;i–)
	{
		scanf(“%d”,&b[i]);
	}
	if(m>=n)
	{
		for(i=m;i>=0;i–)
		{
			c[i]=a[i]+b[i];
			cnt++;
		}
	}
	else
	{
		for(i=n;i>=0;i–)
		{
			c[i]=a[i]+b[i];
		}
	}
	printf(“\n\nRESULTANT POLYNOMIAL IS :A:=”);
	for(i=cnt-1;i>0;i–)
	{
		printf(“%dX^%d+”,c[i],i);
	}
	printf(“%d”,c[i]);
	getch();
	return 0;
}


