#include <stdio.h>
struct term {
    int coeff;
    int exp;
};
// Function to read polynomial
int readPoly(struct term p[]) {
    int n, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coeff and exp: ");
        scanf("%d%d", &p[i].coeff, &p[i].exp);
    }
    return n;
}

void sort(struct term p[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			struct term temp;
			if(p[i].exp<p[j].exp){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}
// Function to add two polynomials
int addPoly(struct term p1[], int n1, struct term p2[], int n2, struct term res[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {	//same no. of elemnts not same power
        if (p1[i].exp == p2[j].exp) {	//here same power
            res[k].coeff = p1[i].coeff + p2[j].coeff;
            res[k].exp = p1[i].exp;
            i++; j++;
        } else if (p1[i].exp > p2[j].exp) {	//here greater power
            res[k] = p1[i];
            i++;
        } else {	//less power 
            res[k] = p2[j];
            j++;
        }
        k++;
    }
    while (i < n1) res[k++] = p1[i++];	//tarnsfer balance elements to result
    while (j < n2) res[k++] = p2[j++];
    return k;
}
// Function to display polynomial
void displayPoly(struct term p[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%dx^%d", p[i].coeff, p[i].exp);
        if (i < n - 1) printf(" + ");
    }
    printf("\n");
}
int main() {
    struct term p1[10], p2[10], res[20];
    int n1, n2, n3;
    printf("\nEnter first polynomial:\n");
    n1 = readPoly(p1);
    printf("\nEnter second polynomial:\n");
    n2 = readPoly(p2);
    sort(p1,n1);
    sort(p2,n2);
    n3 = addPoly(p1, n1, p2, n2, res);
    printf("\nSum: ");
    displayPoly(res, n3);
    return 0;
}
