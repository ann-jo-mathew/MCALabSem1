#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(int a){		// Insert at end
	node *t;
	if(head==NULL){		//1st node inserted    
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
void disp(){		// Display list
	node *t;
	printf("Elements are: \n");
	for(t=head;t!=NULL;t=t->next)
		printf("%d\t",t->data);
	printf("\n");
}
void sortByValues(){		// Sort by swapping values(ascending)
	node *i,*j;
	int temp;
	for(i=head;i!=NULL;i=i->next){
		for(j=i->next;j!=NULL;j=j->next){
			if(i->data > j->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
	printf("Linked list sorted by swapping values(ascending):\n");
	disp();
}
void sortByAddresses(){		// Sort by swapping addresses(descending order)
	if(head==NULL || head->next==NULL) 
		return;
	node *i,*j,*temp,*p_i=NULL,*p_j=NULL;
	int swapped=0;

	for(i=head;i!=NULL;i=i->next){
		p_j=i;
		for(j=i->next;j!=NULL;j=j->next){
			if(i->data < j->data){		//descending
				swapped=1;

				if(p_i!=NULL)
					p_i->next=j;
				else
					head=j;

				p_j->next=i;

				temp=i->next;
				i->next=j->next;
				j->next=temp;

				temp=i;
				i=j;
				j=temp;

				p_j=j;
			}
		}
		p_i=i;
	}
	if(swapped)
		printf("Linked list sorted by swapping addresses(descending):\n");
	else
		printf("List was already sorted.\n");
	disp();
}
int menu(){		// Menu
	int ch;
	printf("\n*MENU*\n1.Insert\n2.Display\n3.Sort by values\n4.Sort by addresses\n5.Exit\nEnter choice: ");
	scanf("%d",&ch);
	return ch;
}
void LinkedListOperation(){			// Menu-driven operations
	int ch,e;
	for(ch=menu();ch!=5;ch=menu()){
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
				sortByValues();
				break;
			case 4:
				sortByAddresses();
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

