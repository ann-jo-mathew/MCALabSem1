#include<stdio.h>
//#include<string.h>
//int top=-1;
int strlength(char a[]){
	int i=0;
	//for(i=0;a[i]!='\0';i++)
	while(a[i]!='\0')	
	{
	i++;	
	}
	return i;
}
void strcopy(char a[]){
	int i;
	char cp[10];
	printf("String copied: ");
	for(i=0;a[i]!='\0';i++){
		cp[i]=a[i];
		printf("%c",cp[i]);
	}
	printf("\n");
	//return cp;
}
void strconcat(char a[],char b[]){
	int len2,i=0;
	int len=strlength(a);
	printf("***len=%d\n***a[len]=%d",len,a[len]);
	
	while(b[i]!='\0'){
		a[len+i]=b[i];
		i++;	
	}	
	//len2=i;
	/*for(i=len;i<=len2;i++)
		a[i]=b[i];
	a[i]='\0';*/
	a[len+i]='\0'; 
	printf("String is ");
	for(i=0;a[i]!='\0';i++)	{
		printf("%c",a[i]);
	}
	printf("\n");
}
void strreverse(char a[]){
	int i,len=strlength(a);
	printf("Reverse is: ");
	for(i=0;len>=0;i++){
		printf("%c",a[len--]);
	}
	printf("\n");
}
void strcmparison(char a[],char b[]){
	int i,count=0;
	for(i=0;a[i]!='\0' && b[i]!='\0';i++){
			if(a[i]!=b[i])
				count++;
	}
	if(count==0)
		printf("The two strings are equal");
	else
		printf("They are not equal with a difference in %d elements",count);		
}
void strcomparei(int a[],int b[]){
	int i,count=0;
	for(i=0;a[i]!='\0' && b[i]!='\0';i++){
			if(a[i]!=b[i])
				count++;
	}
	if(count==0)
		printf("The two strings are equal");
	else
		printf("They are not equal with a difference in %d elements",count);			
}
void display(char a[]){
	int i;
	printf("String is: ");
	for(i=0;a[i]!='\0';i++)	{
		printf("%c",a[i]);
	}
	printf("\n");
}
int menu(){
	int ch;
	printf("\nStrlen-1\nStrcpy-2\nStrcat-3\nStrrev-4\nStrcmp-5\nStrcmpi-6\nDisplay-7\nExit-8\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}
void input(char a[]){
	int ch,i;
	char b[50];
	printf("Enter a string: ");
	scanf("%s",a);
	for(ch=menu();ch!=8;ch=menu()){
		switch(ch){
			case 1:
				i=strlength(a);
				printf("String Length is:%d \n",i);
				break;
			case 2:
				strcopy(a);
				break;
			case 3:
				printf("Enter a string to concatinate: ");
				scanf("%s",b);
				strconcat(a,b);
				break;
			case 4:
				strreverse(a);
				break;
			case 5:
				printf("Enter a string to compare: ");
				scanf("%s",b);
				strcmparison(a,b);
				break;
			case 6:
				printf("Enter a string to compare: ");
				scanf("%s",b);
				strcomparei(a,b);
				break;
			case 7:
				display(a);
				break;
			default:
				printf("Wrong choice\n");
				//break;
		}
	}	
}
int main(){
	char a[50];	
	input(a);
}
