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
// Function to multiply two polynomials
int multiplyPoly(struct term p1[], int n1, struct term p2[], int n2, struct term r[]) {
    int i, j, k = 0;
    // Multiply every term of p1 with every term of p2
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            int coeff = p1[i].coeff * p2[j].coeff;
            int exp = p1[i].exp + p2[j].exp;
            //Check if exponent already exists in result
            int m,found = 0;
            for ( m = 0; m < k; m++) {
                if (r[m].exp == exp) {   // If exponent matches, combine it
                    r[m].coeff += coeff;
                    found = 1;
                    break;
                }
            }
            //If exponent not found, add as new term
            if (!found) {
                r[k].coeff = coeff;
                r[k].exp = exp;
                k++;
            }
        }
    }
    return k;  // return number of resulting terms
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
    struct term p1[10], p2[10], r[50];
    int n1, n2, n3;
    printf("\nEnter first polynomial:\n");
    n1 = readPoly(p1);
    printf("\nEnter second polynomial:\n");
    n2 = readPoly(p2);
    n3 = multiplyPoly(p1, n1, p2, n2, r);
    printf("\nProduct");
    displayPoly(r, n3);
    return 0;
}

