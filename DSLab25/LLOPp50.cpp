#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node{
	char name[50];
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insertEnd(char n[]){	//inserting at the end of list
	node *t,*temp;
	temp=(node*)malloc(sizeof(node));
	strcpy(temp->name,n);
	temp->next=NULL;

	if(head==NULL)
		head=temp;
	else{
		t=head;
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
	}
}
void deleteName(char n[]){
	node *t;
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	if(strcmp(head->name,n)==0){
		head=head->next;
		printf("Deleted successfully\n");
		return;
	}
	t=head;
	while(t->next!=NULL && strcmp(t->next->name,n)!=0)
		t=t->next;
	if(t->next==NULL)
		printf("Name not found\n");
	else{
		t->next=t->next->next;
		printf("Deleted successfully\n");
	}
}
void disp(){
	node *t;
	printf("Names in the list:\n");
	for(t=head;t!=NULL;t=t->next)
		printf("%s\n",t->name);
}
void count(){
	node *t;
	int c=0;
	for(t=head;t!=NULL;t=t->next)
		c++;
	printf("Total names = %d\n",c);
}
void reverse(){
	node *pre=NULL,*t=head,*nxt=NULL;
	while(t!=NULL){
		nxt=t->next;
		t->next=pre;
		pre=t;
		t=nxt;
	}
	head=pre;
	printf("List reversed successfully\n");
}
void sort(){
	if(head==NULL) return;
	node *i,*j;
	char temp[50];
	for(i=head;i!=NULL;i=i->next){
		for(j=i->next;j!=NULL;j=j->next){
			if(strcmp(i->name,j->name)>0){
				strcpy(temp,i->name);
				strcpy(i->name,j->name);
				strcpy(j->name,temp);
			}
		}
	}
	printf("List sorted alphabetically\n");
}
int menu(){
	int ch;
	printf("\n*MENU*\n1.Insert at End\n2.Delete\n3.Display\n4.Sort\n5.Reverse\n6.Count\n7.Exit\nEnter choice: ");
	scanf("%d",&ch);
	return ch;
}
void NameListOperation(){
	int ch;
	char name[50],after[50];
	for(ch=menu();ch!=7;ch=menu()){
		switch(ch){
			case 1:
				printf("Enter name to insert at end: ");
				scanf("%s",name);
				insertEnd(name);
				break;
			case 2:
				printf("Enter name to delete: ");
				scanf("%s",name);
				deleteName(name);
				break;
			case 3:
				disp();
				break;
			case 4:
				sort();
				break;
			case 5:
				reverse();
				break;
			case 6:
				count();
				break;
			default:
				printf("Invalid choice\n");
		}
	}
}
int main(){
	NameListOperation();
	return 0;
}

