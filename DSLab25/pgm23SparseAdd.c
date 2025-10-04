/* Sparse Matrix Addition
@Ann Jo Mathew
Roll No: 12
03/10/2025 */

#include<stdio.h>
int r,c,i,j,sc[40][3],count=0;
void read(int a[20][20]){
	printf("Enter row and column size of sparse matrix: ");
	scanf("%d %d",&r,&c);
	printf("Enter the elements: \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n");
}
int sparseArray(int a[20][20],int s[20][3],int count){
	int k=1;
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
			if(a[i][j]!=0){
			s[k][0]=i;
			s[k][1]=j;
			s[k][2]=a[i][j];
			k++;
			}
		}
	}
	return count;
}
void dispSparse(int s[20][3],int count){
	int k;
	printf("Sparse matrix Triplet Form\n");
	printf("Row\tColumn\tValues\n");
	for(i=0;i<=count;i++){
		for(k=0;k<3;k++){
			printf("%d\t",s[i][k]);
		}
	printf("\n");
	}	
	printf("\n");
}
void SparseAdd(int sa[20][3],int sb[20][3],int counta,int countb){
	if(sa[0][0]==sb[0][0]&&sa[0][1]==sb[0][1]){
		int i=1,j=1,k=1;
		sc[0][0]=sa[0][0];
		sc[0][1]=sa[0][1];	
		while(i<=counta && j<=countb){
			if(sa[i][0]==sb[j][0]&&sa[i][1]==sb[j][1]){
				sc[k][0]=sa[i][0];
				sc[k][1]=sa[i][1];
				sc[k][2]=sa[i][2]+sb[j][2];
				i++;
				j++;
				k++;
			}
			else{
				if(sa[i][0]<sb[j][0]||(sa[i][0]==sb[j][0]&&sa[i][1]<sb[j][1])){
					sc[k][0]=sa[i][0];
					sc[k][1]=sa[i][1];
					sc[k][2]=sa[i][2];
					i++;
					k++;
				}
				else{
					sc[k][0]=sb[j][0];
					sc[k][1]=sb[j][1];
					sc[k][2]=sb[j][2];
					j++;
					k++;				
				}
			}
		}
		while(i<=counta){
			sc[k][0]=sa[i][0];
			sc[k][1]=sa[i][1];
			sc[k][2]=sa[i][2];
			i++;
			k++;
		}	
		while(j<=countb){
			sc[k][0]=sb[j][0];
			sc[k][1]=sb[j][1];
			sc[k][2]=sb[j][2];
			j++;
			k++;	
		}
		sc[0][2]=k-1;	
		dispSparse(sc,k-1);	
	}
	else
		printf("Addition not possible(Row and column of two should be equal)\n");	
}
int main(){
	int a[20][20],b[20][20],sb[20][3],sa[20][3],counta=0,countb=0;
	read(a);
	read(b);
	counta=sparseArray(a,sa,counta);
	countb=sparseArray(b,sb,countb);
	dispSparse(sa,counta);
	dispSparse(sb,countb);
	SparseAdd(sa,sb,counta,countb);
	return 0;
}
