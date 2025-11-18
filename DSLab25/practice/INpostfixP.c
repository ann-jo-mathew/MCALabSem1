#include<stdio.h>
char stack[20];
int top=-1;
void push(char e){
	if(top+1==20)
		printf("OVERFLOW\n");
	else
		stack[++top]=e;
}
char pop(){
	if(top==-1)
		printf("UNDERFLOW\n");
	else
		return stack[top--];
}
int order(char e){
	if(e=='*'||e=='/')
		return 2;
	else if(e=='+'||e=='-')
		return 1;
	else
		return 0;
}
void postfix(char n[]){
	int k=-1,i;
	char result[20];
	for(i=0;n[i]!='\0';i++){
		if((n[i]>='0'&&n[i]<='9')||(n[i]>='A'&&n[i]<='Z')||(n[i]>='a'&&n[i]<='z')){
			result[++k]=n[i];
		}
		else if(n[i]=='(')
			push(n[i]);
		else if(n[i]==')'){
			while(top!=-1&&stack[top]!='('){
				result[++k]=pop();
			}
			if(top!=-1&&stack[top]=='('){
				pop();
			}
		}
		else{
			while(top!=-1&&order(n[i])<order(stack[top]))		//need to use loop to check if the next is of high order or not
				result[++k]=pop();
			push(n[i]);
		}
	}
	while(top!=-1)
		result[++k]=pop();
	result[++k]='\0';
	printf("POSTFIX IS: %s",result);
}
int main(){
	char n[20];
	printf("Eneter the expression\n");
	scanf("%s",n);
	postfix(n);
	return 0;
}
