#include<stdio.h>
#include<string.h>
char stack[20];
int top=-1;
void push(char e){
	stack[++top]=e;
}
char pop(){
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
void reverse(char re[20]){
	int i=0;
	int j=strlen(re)-1;
	while(i<j){
		char t=re[i];
		re[i]=re[j];
		re[j]=t;
		i++;
		j--;
	}
}
void prefix(char n[20]){
	char result[20];
	int k=-1,i;
	reverse(n);
	for(i=0;n[i]!='\0';i++){
		if(n[i]==')')
			n[i]='(';
		else if(n[i]=='(')
			n[i]=')';
	}
	for(i=0;n[i]!='\0';i++){
		if(n[i]>='0'&&n[i]<='9'||n[i]>='A'&&n[i]<='Z'||n[i]>='a'&&n[i]<='z'){
			result[++k]=n[i];
		}
		else if(n[i]=='('){
			push(n[i]);
		}
		else if(n[i]==')'){
			while(top!=-1&&stack[top]!='('){
				result[++k]=pop();
			}
			if(top!=-1&&stack[top]=='(')
				pop();
			
		}
		else{
			while(top!=-1&&order(n[i])<=order(stack[top])){
				result[++k]=pop();
			}
			push(n[i]);
		}
	}
	while(top!=-1){
		result[++k]=pop();
	}
	result[++k]='\0';
	reverse(result);
	printf("PREFIX %s",result);
}
int main(){
	char n[20];
	printf("INFIX: ");
	scanf("%s",n);
	prefix(n);
	return 0;
}
