/*Aim: program to read and display of a Sparse matrix
@Ann Jo Mathew
Date:*/
#include<stdio.h>
int r,c,i,j,count=0,s[20][3];
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
	int k;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]!=0){
				count++;
			}
		}
	}
	s[0][0]=r;
	s[0][1]=c;
	s[0][2]=count;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			for(k=1;k<=count;k++){
				if(a[i][j]!=0){
				s[k][0]=i;
				s[k][1]=j;
				s[k][2]=a[i][j];
				}
			}
		}
	}
}
void dispSparse(int a[20][20]){
	int k;
	printf("Sparse matrix array representation\n");
	
		/*if(k==0)
			printf("Row:    ");
		else if(k==1)
			printf("Column: ");
		else
			printf("Values: ");
		*/
	printf("Row\tColumn\tValues\n");
	for(i=0;i<=count;i++){
		for(k=0;k<3;k++){
			printf("%d\t",s[i][k]);
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
