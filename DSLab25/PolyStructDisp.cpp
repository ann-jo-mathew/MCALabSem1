#include <stdio.h>

// Structure to represent a term in a polynomial
struct term {
    int coeff;  // coefficient
    int exp;    // exponent
};

// Function to read polynomial
int readPoly(struct term p[]) {
    int n, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &p[i].coeff, &p[i].exp);
    }
    return n;
}

// Function to display polynomial
void displayPoly(struct term p[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%dx^%d", p[i].coeff, p[i].exp);
        if (i < n - 1)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct term p[10];
    int n;
    n = readPoly(p);
    printf("\nPolynomial: ");
    displayPoly(p, n);
    return 0;
}

