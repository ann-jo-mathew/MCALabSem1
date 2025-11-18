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
		while(t->next!=NULL)
			t=t->next;
		t->next=(node*)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=NULL;
	}
}

void deleteStart(){
	if(head==NULL) printf("Linked list empty\n");
	else head=head->next;
}

void deleteEnd(){
	if(head==NULL) printf("Linked list empty\n");
	else if(head->next==NULL) head=NULL;
	else{
		node *t=head;
		while(t->next->next!=NULL)
			t=t->next;
		t->next=NULL;
	}
}

void deleteValue(int a){
	node *t=head;
	if(head==NULL) printf("Linked list empty\n");
	else if(head->data==a) head=head->next;
	else{
		while(t->next!=NULL && t->next->data!=a)
			t=t->next;
		if(t->next==NULL) printf("Element not found\n");
		else t->next=t->next->next;
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
	printf("\n*MENU*\n1.Insert\n2.Delete from start\n3.Delete from end\n4.Delete a value\n5.Display\n6.Exit\nEnter choice: ");
	scanf("%d",&ch);
	return ch;
}

void LinkedListOperation(){
	int ch,e;
	for(ch=menu();ch!=6;ch=menu()){
		switch(ch){
			case 1:
				printf("Enter element to insert: ");
				scanf("%d",&e);
				insert(e);
				break;
			case 2:
				deleteStart();
				break;
			case 3:
				deleteEnd();
				break;
			case 4:
				printf("Enter value to delete: ");
				scanf("%d",&e);
				deleteValue(e);
				break;
			case 5:
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

