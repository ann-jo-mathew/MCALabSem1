#include<stdio.h>
struct date{
	int dd;
	int mm;
	int yy;	
};
typedef struct date date;
date readdate(date d)
{
	printf("Date: ");
	scanf("%d",&d.dd);
	printf("Month: ");
	scanf("%d",&d.mm);
	printf("Year: ");
	scanf("%d",&d.yy);
	return d;
}
void dispdate(date d){
	printf("%d / %d / %d\n",d.dd,d.mm,d.yy);
}
void compare(date d1,date d2){
	if(d1.dd == d2.dd && d1.mm == d2.mm && d1.yy == d2.yy)
		printf("Dates are equal\n");
	else
		printf("Dates are not equal\n");
}
int main(){
	date d1;
	date d2;
	printf("Enter date 1: \n");
	d1=readdate(d1);
	printf("Enter date 2: \n");	
	d2=readdate(d2);
	printf("date 1: \n");
	dispdate(d1);
	printf("date 2: \n");
	dispdate(d2);
	compare(d1,d2);
}
