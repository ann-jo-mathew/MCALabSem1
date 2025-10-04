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
void SparseMulti(int sa[20][3],int sb[20][3],int counta,int countb){
    int m,n,p,q,r,c,v,i,j,k=1;
	m=sa[0][0];  
    n=sa[0][1]; 
    p=sb[0][0];  
    q=sb[0][1]; 
    if (n!=p) {
        printf("Multiplication not possible (Columns of A != Rows of B)\n");
        sc[0][2]=0;
        return;
    }
    sc[0][0]=m;
    sc[0][1]=q;
    for(i=1;i<=counta;i++){
        for(j=1;j<=countb;j++){
            if(sa[i][1]==sb[j][0]){  
                r=sa[i][0];      
                c=sb[j][1];       
                v=sa[i][2]*sb[j][2];
                int y,found=0;
                for(y=1;y<k;y++){
                    if(sc[y][0]==r&&sc[y][1]==c){
                        sc[y][2]+=v;
                        found=1;
                        break;
                    }
                }
                if (!found) {
                    sc[k][0]=r;
                    sc[k][1]=c;
                    sc[k][2]=v;
                    k++;
                }
            }
        }
    }
    sc[0][2]=k-1; 
	printf("\nProduct of Matrices:\n"); 
    dispSparse(sc,k-1);
}	
int main(){
	int a[20][20],b[20][20],sb[20][3],sa[20][3],counta=0,countb=0;
	read(a);
	read(b);
	counta=sparseArray(a,sa,counta);
	countb=sparseArray(b,sb,countb);
	dispSparse(sa,counta);
	dispSparse(sb,countb);
	SparseMulti(sa,sb,counta,countb);
	return 0;
}
