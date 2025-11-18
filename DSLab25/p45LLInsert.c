#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;

void insert(int a){		//Insert at end
	node *t;
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->data=a;
		head->next=NULL;
	}
	else{
		t=head;
		while(t->next!=NULL)
			t=t->next;
		t->next=(node*)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=NULL;
	}
}

void insertStart(int a){	//Insert at beginning
	node *temp=head;
	head=(node*)malloc(sizeof(node));
	head->data=a;
	head->next=temp;
}

void insertAfter(int e,int a){	//Insert after element e
	node *t=head;
	while(t!=NULL && t->data!=e)
		t=t->next;
	if(t==NULL)
		printf("Node not found!\n");
	else{
		node *temp=t->next;
		t->next=(node*)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=temp;
	}
}

void disp(){
	node *t;
	printf("Elements are: \n");
	for(t=head;t!=NULL;t=t->next)
		printf("%d\t",t->data);
	printf("\n");
}

int menu(){
	int ch;
	printf("\n*MENU*\n1.Insert at end\n2.Insert at beginning\n3.Insert after element\n4.Display\n5.Exit\nEnter choice: ");
	scanf("%d",&ch);
	return ch;
}

void LinkedListOperation(){
	int ch,e,a;
	for(ch=menu();ch!=5;ch=menu()){
		switch(ch){
			case 1:
				printf("Enter element to insert at end: ");
				scanf("%d",&e);
				insert(e);
				break;
			case 2:
				printf("Enter element to insert at start: ");
				scanf("%d",&e);
				insertStart(e);
				break;
			case 3:
				printf("Enter element after which to insert: ");
				scanf("%d",&a);
				printf("Enter element to insert: ");
				scanf("%d",&e);
				insertAfter(a,e);
				break;
			case 4:
				disp();
				break;
			default:
				printf("Invalid choice\n");
		}
	}
}

int main(){
	LinkedListOperation();
	return 0;
}

