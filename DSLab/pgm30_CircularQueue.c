#include<stdio.h>
int q[3];
int f=-1,r=-1;
void enqueue(int e){
	if((r+1)%3==f)	
		printf("Error:Queue is full");
	else{
		if(r==-1)		//checking if no element has been inserted yet 
			f=0;		//f as 0 since queue is empty
		r=(r+1)%3;		//rear updated 
		q[r]=e;		//element inserted
	}
}
void dequeue(){
	if(f==-1)		
		printf("Error:Queue Empty");
	else{
		printf("%d\t",q[f]);
		if(f==r)		//checking if there is only one element
			f=r=-1;		//making it empty and deleting the only elemet
		else
			f=(f+1)%3;		//deleting an element
	}
}
void display(){
	int i;
	if(f==-1){
		printf("Queue Empty\n");

	}
	else{
		for(i=f;i<=r;i=(r+1)%3){
			printf("%d\t",q[i]);
		}
	}
}
int menu(){
	int ch;
	printf("\n\nINSERT-1\nDELETE-2\nDISPLAY-3\nEXIT-4\nEnter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void processQueue(){
	int ch,e;
	for(ch=menu();ch!=4;ch=menu()){
		switch(ch){
			case 1:
				printf("Enter an element to push: ");
				scanf("%d",&e);
				enqueue(e);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("Invalid choice");
		}
	}
}
int main(){
	float f=1%3;
	printf("%f",f);
	//int front=-1,rear=-1,n;
	//printf("Enter the limit of the queue: ");
	//scanf("%d",&n);
	processQueue();
	return 0;
}
