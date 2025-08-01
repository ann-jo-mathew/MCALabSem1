#include<stdio.h>
void increment(){
	static int i=23;//Static Variable
	i++;
	printf("%d\t",i);
}
int main(){
	increment();
	increment();
	increment();
	return 0;
}
