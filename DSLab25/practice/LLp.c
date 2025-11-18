#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(int e){
	node *t=head;
	if(head==NULL){
		head=(node*)malloc(sizeof(node));		//dynamic allocation assigns to pointers
		head->next=NULL;
		head->data=e;
		printf("Element %d inserted is the first element\n",head->data);
	}
	else{							//inserting last
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		t->next->data=e;
		t->next->next=NULL;
		printf("Element %d inserted successfully\n",t->next->data);
	}
}
void insertAfter(int a,int e){
	node *t=head;
	/*if(head->data==a){
		node *temp=head->next;		//element found is the head
		head->next=(node*)malloc(sizeof(node));
		head->next->data=e;
		haed->next->next=temp;
		printf("Element a is the head, element e inserted successfully\n");
	}*/
	while(t!=NULL&&t->data!=a)
		t=t->next;	
		if(t==NULL)
			printf("ELement not found\n");
		else{
			node *temp=t->next;
			t->next=(node*)malloc(sizeof(node));
			t->next->data=e;
			t->next->next=temp;	
			printf("Element %d inseted succssfully\n",t->next->data);
		}
			
}
void delete(int de){
	node *t=head;
	if(head==NULL)
		printf("List Empty\n");
	else if(head->data==de){	//deleting head pointing element
		node *temp=head;
		head=head->next;  //##############****
		free(temp);
		printf("head pointing element deleted successfully\n");
	}
	else{
		while(t->next!=NULL&&t->next->data!=de){
			t=t->next;
		}
		if(t->next==NULL)
			printf("ELement not found\n");
		else{
			node *temp=t->next;
			t->next=t->next->next;
			printf("Element %d deleted successfully\n",temp->data);
			free(temp);	
		}
	}
}
//normal swapSort
void sorted(){
	node *i,*j;
	int temp;
	if(head==NULL)
		printf("LL Empty\n");
	else{
		for(i=head;i!=NULL;i=i->next){
			for(j=i;j!=NULL;j=j->next){
				if(i->data>j->data){
					temp=i->data;
					i->data=j->data;
					j->data=temp;
				}
			}
		}
	}
}
void sort(){
	printf("Address\n");
	node *i,*j,*p_i,*p_j,*temp;
	p_i=NULL;
	p_j=NULL;
	for(i=head;i!=NULL;i=i->next){
		p_j=i;
		for(j=i->next;j!=NULL;j=j->next){
			if(i->data>j->data){
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
				
			
			}
			p_j=j;
		}
		p_i=i;
	}
}
void display(){
	node *t=head;
	while(t!=NULL){
		if(t->next!=NULL)
			printf("%d -> ",t->data);
		else
			printf("%d\n",t->data);
		t=t->next;
	}
}
void mean(){
	node *i;
	int sum=0,count=0;
	float avg;
	for(i=head;i!=NULL;i=i->next){
		sum=sum+i->data;
		count++;
	}
	avg=(float)sum/count;
	printf("Avg= %f",avg);
}
void reverse(){
	node *t,*n,*p;
	t=head;
	n=NULL;
	p=NULL;
	while(t!=NULL){
		n=t->next;
		t->next=p;
		p=t;
		t=n;	
	}
	head=p;
	display();
}
int main(){
	insert(10);
	insert(15);
	insert(78);
	display();
	mean();
	reverse();
	//insertAfter(15,26);
	/*display();
	insert(24);
	display();
	sort();
	printf("After Sort: \n");
	display();
	delete(200);
	delete(78);
	display();
	delete(10);
	display();*/
	return 0;
}
