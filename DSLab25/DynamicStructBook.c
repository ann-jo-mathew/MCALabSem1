#include <stdio.h>
#include <stdlib.h>
struct Book{
    char author_name[50];
    char book_name[50];
};
typedef struct Book Book;
Book* readBooks(int n) {		// Function to read n books
	int i;
    Book *books=(Book*)malloc(n*sizeof(Book));
    if(books==NULL) {
        printf("Memory not allocated.\n");
        exit(1);
    }
    for (i = 0;i < n; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Enter author name: ");
        getchar();  //remove leftover newline from nu. of books
        gets(books[i].author_name);  //simpler than pointer arithmetic
        printf("Enter book name: ");
        gets(books[i].book_name);
    }
    return books;
}
void displayBooks(Book *books, int n) {		// Function to display n books
    int i;
	printf("\nList of Books:\n");
    for (i = 0; i < n; i++) {
        printf("Book %d:\n", i + 1);
        printf("Author: %s\n", books[i].author_name);
        printf("Title : %s\n\n", books[i].book_name);
    }
}
int main() {
    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);
    Book *books = readBooks(n);
    displayBooks(books, n);
    free(books);
    return 0;
}

