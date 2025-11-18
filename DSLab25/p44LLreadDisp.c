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

void disp(){
	node *t;
	printf("Elements are: \n");
	for(t=head;t!=NULL;t=t->next){
		printf("%d\t",t->data);
	}
	printf("\n");
}

int main(){
	int n,e,i;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter element %d: ",i+1);
		scanf("%d",&e);
		insert(e);
	}
	disp();
	return 0;
}

