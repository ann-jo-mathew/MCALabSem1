#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
	char data[50];
	struct node *next;
};
typedef struct node node;
node *t,*head=NULL;
void insert(char e[50]){
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->next=NULL;
		strcpy(head->data,e);
	}
	else{
		t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		strcpy(t->next->data,e);
		t->next->next=NULL;
	}
		
}
void display(){
	printf("LL is:\n");
	t=head;
	while(t!=NULL){
		printf("%s\t",t->data);	
		t=t->next;
	}
	printf("\n");
}
int main(){
	char e[50];
	int ch;

	while(1){
	printf("enter");
	scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the string:");
				scanf(" %[^\n]",e);
				insert(e);
				break;
			case 2:
				display();
				break;
			case 3:
				exit(1);
				break;
			default:
				printf("invalid\n");
		}
	}
	return 0;
}
