/*Aim: program to read and display of a Sparse matrix
@Ann Jo Mathew
Date:*/
#include<stdio.h>
int r,c,i,j,count=0,s[3][20];
void read(int a[20][20]){
	printf("Enter row and column size of sparse matrix: ");
	scanf("%d %d",&r,&c);
	printf("Enter the elements: \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			//printf("Enter element %d %d: ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	sparseArray(a);
}
void sparseArray(int a[20][20]){
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]!=0){
				s[0][count]=i;
				s[1][count]=j;
				s[2][count]=a[i][j];
				count++;

			}
		}
	}
}
void dispSparse(int a[20][20]){
	int k;
	printf("Sparse matrix array representation\n");
	for(k=0;k<3;k++){
		if(k==0)
			printf("Row:    ");
		else if(k==1)
			printf("Column: ");
		else
			printf("Values: ");
		
		for(i=0;i<count;i++){
		printf("%d\t",s[k][i]);
		}
	printf("\n");
	}
}
void dispMatrix(int a[20][20]){
	printf("The matrix is: ");
}
int main(){
	int a[20][20];
	read(a);
	dispSparse(a);
	return 0;
}
