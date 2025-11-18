#include<stdio.h>
int q[50],n;
int f=-1,r=-1;
void enqueue(int e){		//Function to insert a new element to the rear
	if((r+1)%n==f)	
		printf("Error:Queue is full");
	else{
		if(r==-1)		//checking if no element has been inserted yet 
			f=0;		//f as 0 since queue is empty
		r=(r+1)%n;		//rear updated 
		q[r]=e;		//element inserted
	}
}
void dequeue(){		//function to delete an element from the front
	if(f==-1)		
		printf("Error:Queue Empty");
	else{
		printf("%d\t",q[f]);
		if(f==r)		//checking if there is only one element
			f=r=-1;		//making it empty and deleting the only elemet
		else
			f=(f+1)%n;		//deleting an element
	}
}
void display(){			//Function to display all elements
	int i;
	if(f==-1){
		printf("Queue Empty\n");

	}
	else{
		for(i=f;i!=r;i=(i+1)%n){
			printf("%d\t",q[i]);
		}
		printf("%d",q[i]);
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
	printf("CIRCULAR QUEUE OPERATIONS\n");
	printf("Enter the siz of queue: ");
	scanf("%d",&n);
	float f=1%n;
	//printf("%f",f);
	processQueue();
	return 0;
}
