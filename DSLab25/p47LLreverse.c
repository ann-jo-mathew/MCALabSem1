#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;

void insert(int a){		//function to insert elements to the end
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

void disp(){		//function to display the elements
	node *t;
	printf("Elements are: \n");
	for(t=head;t!=NULL;t=t->next)
		printf("%d\t",t->data);
	printf("\n");
}

void dispReverse(node *t){		//Function to display the reverse using recursion
	if(t==NULL) return;
	dispReverse(t->next);
	printf("%d\t",t->data);
}

int menu(){
	int ch;
	printf("\n*MENU*\n1.Insert\n2.Display\n3.Display in reverse\n4.Exit\nEnter choice: ");
	scanf("%d",&ch);
	return ch;
}

void LinkedListOperation(){
	int ch,e;
	for(ch=menu();ch!=4;ch=menu()){
		switch(ch){
			case 1:
				printf("Enter element to insert: ");
				scanf("%d",&e);
				insert(e);
				break;
			case 2:
				disp();
				break;
			case 3:
				printf("Linked list in reverse: \n");
				dispReverse(head);
				printf("\n");
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

