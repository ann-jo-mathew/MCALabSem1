#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(int a){
	node *t;
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->data=a;
		head->next=NULL;
	}
	else{
		t=head;
		while(t->!NULL)
			t=t->next;
		t->next=(node*)malloc(sizeof(node));
		t->next->data=a;
		t->next-next=NULL;
	}
}
void insertAfter(int e,int a){
	node *t=head;
	while(t->data!=e && t!=NULL)		//t->next!=NULL not possible it will execute the if statement
		t=t->next;								//last node (t->next == NULL) actually contains the value e then the data will come as not found 
	if(t->data==e){							//evenif the element is there
		node *temp=t->next;
		t->next=(node*)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=temp;
	}
	else  
 		printf("Node not found!\n");
}
void insertStart(int a){
	node *temp=head;
	head=(node*)malloc(sizeof(node));
	head->data=a;
	head->next=temp;
}
void deleteStart(){
	head=head->next;
}
void 
