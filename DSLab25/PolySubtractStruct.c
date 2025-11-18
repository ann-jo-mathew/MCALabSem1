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
// Function to subtract polynomials
int subPoly(struct term p1[], int n1, struct term p2[], int n2, struct term r[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (p1[i].exp == p2[j].exp) {
            r[k].coeff = p1[i].coeff - p2[j].coeff;
            r[k].exp = p1[i].exp;
            i++; j++;
        } else if (p1[i].exp > p2[j].exp) {
            r[k] = p1[i];
            i++;
        } else {
            r[k].coeff = -p2[j].coeff;
            r[k].exp = p2[j].exp;
            j++;
        }
        k++;
    }
    while (i < n1) r[k++] = p1[i++];
    while (j < n2) {
        r[k].coeff = -p2[j].coeff;
        r[k++].exp = p2[j++].exp;
    }
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
    struct term p1[10], p2[10], r[20];
    int n1, n2, n3;
    printf("\nEnter first polynomial:\n");
    n1 = readPoly(p1);
    printf("\nEnter second polynomial:\n");
    n2 = readPoly(p2);
    n3 = subPoly(p1, n1, p2, n2, r);
    printf("\nDifference: ");
    displayPoly(r, n3);
    return 0;
}

