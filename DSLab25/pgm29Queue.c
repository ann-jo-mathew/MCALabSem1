#include<stdio.h>
int equeue(int a[],int n,int e,int f,int r){
	if(r==n-1){
		printf("Queue is full\n");
		return r;
	}
	else{
		r++;
		a[r]=e;
		printf("Element %d pushed successfully",a[r]);
		return r;
	}
}
int dequeue(int a[],int f,int r){
	if(r<f||f==-1){
		printf("Queue Empty\n");
		return f;
	}
	else{
		printf("The element %d deleted from queue",a[f++]);
		return f;
	}
}
void display(int a[],int f,int r){
	int i;
	if(r<f||f==-1){
		printf("Queue Empty\n");

	}
	else{
		for(i=f;i<=r;i++){
			printf("%d\t",a[i]);
		}
	}
}
int menu(){
	int ch;
	printf("\n\nINSERT-1\nDELETE-2\nDISPLAY-3\nEXIT-4\nEnter your choice : ");
	scanf("%d",&ch);
	return ch;
}
void processQueue(int a[],int n,int f,int r){
	int ch,e;
	for(ch=menu();ch!=4;ch=menu()){
		switch(ch){
			case 1:
				printf("Enter an element to push: ");
				scanf("%d",&e);
				r=equeue(a,n,e,f,r);
				if(f==-1){
					f++;
				}
				break;
			case 2:
				f=dequeue(a,f,r);
				break;
			case 3:
				display(a,f,r);
				break;
			default:
				printf("Invalid choice");
		}
	}
}
int main(){
	int a[20],front=-1,rear=-1,n;
	printf("Enter the limit of the queue: ");
	scanf("%d",&n);
	processQueue(a,n,front,rear);
	return 0;
}
