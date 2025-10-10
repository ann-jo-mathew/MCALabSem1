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
		while(t->next!=NULL)	//already its the last elemet
			t=t->next;
		t->next=(node*)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=NULL;	//next-next means new elemets next
	}
}
void delete(int a){
	node *t;
	if(head==NULL){
		printf("Empty linked list\n");
	}
	else if(head->data==a){	//1st element to delete
		head=head->next;
		printf("Element deleted successfully/n");
	}
	else{	//not first
		t=head;
		//printf("\nHead t= %d ",t);
		//printf("///t-next-data = %d\n",t->next->data);		//Here t-next-data points from the secomd elemet that is the first elemet is not checked

		while(t->next!=NULL && t->next->data!=a){	//here 1st element not included	and both must be true for the loop to exexcute
			
			//printf("/////t=%d\n",t);		//if one of them is false then loop wont execute
			//printf("///t-next= %d\n",t->next);
			//printf("////t-data= %d\n",t->data);
			t=t->next;
		}
		if(t->next==NULL){	
			printf("Element not found\n");
		}
		else{
			t->next=t->next->next;
			printf("Element deleted successfully\n");
		}
	}
}
void disp(){
	node *t;
	printf("Elements are: \n");
	for(t=head;t!=NULL;t=t->next){		//traversal 
		printf("%d\t",t->data);
	}
	printf("\n");
}
void sort(){
	int temp;
	node *t,*l;
	for(t=head;t!=NULL;t=t->next){
		for(l=t->next;l!=NULL;l=l->next){
			if(t->data > l->data){
				temp=t->data;
				t->data=l->data;
				l->data=temp;
			}
		}
	}
	disp();		//
}
void search(int a){
	node *t;
	
	
	if(head==NULL){
		printf("Linked List is empty");
	}
	else{
		t=head;
		int count=1;
		while(t!=NULL && t->data!=a){
			count++;
			t=t->next;
			//printf("\n****%d\n",t->data);
		}
		if(t==NULL){
			printf("Element not found\n");
		}
		else{
			printf("Element %d found at node %d\n",t->data,count);
		}
	}
}
void count(){
	node *t;
	int count=0;
	if(head==NULL){
		printf("Linked List is empty\nNumber of elements = 0\n");
	}
	else{
		for(t=head;t!=NULL;t=t->next){	
		count++;
		}
		printf("Number of elements = %d\n",count);
	}
}
void findReplace(int a,int e){
	node *t;
	if(head==NULL){
		printf("Linked List is empty\n");
	}
	else{
		t=head;
		while(t!=NULL && t->data!=a)
			t=t->next;
		if(t==NULL)
			printf("Element not found\n");
		else{
			t->data=e;		//element replaced
			printf("Element replaced successfully\n");
			disp();
		}
	}
}
void reverse(){
	node *t=head, *nxt=NULL, *pre=NULL;
	if(head==NULL){
		printf("Linked list is empty\n");
	}
	else{
		while(t!=NULL){
			nxt=t->next;
			t->next=pre;
			pre=t;
			t=nxt;
		}
		head=pre;
		disp();
	}
}
int menu(){
	int ch;
	printf("\n*MENU*\nInsert-1\nDelete-2\nDisplay-3\nExit-4\nSearch-5\nCount-6\nReplace-7\nReverse-8\nSort-9\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}
void LinkedListOperation(){
	int ch,e,s;
	for(ch=menu();ch!=4;ch=menu()){
		switch(ch){
			case 1:
				printf("Enter the element to insert: ");
				scanf("%d",&e);
				insert(e);
				break;
			case 2:
				printf("Enter the element to delete: ");
				scanf("%d",&e);
				delete(e);
				break;
			case 3:
				disp();
				break;
			case 5:
				printf("Enter the elements to serach: ");
				scanf("%d",&e);
				search(e);
				break;
			case 6:
				count();
				break;
			case 7:
				printf("Enter an element you want to find: ");
				scanf("%d",&s);
				printf("Enter element you want to replace with: ");
				scanf("%d",&e);
				findReplace(s,e);
				break;
			case 8:
				reverse();
				break;	
			case 9:
				sort();
				break;
			default:
				printf("Invalid choice");
		}
	}
}
int main(){
	LinkedListOperation();
	return 0;	
}
