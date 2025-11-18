#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *last = NULL;

// Function to insert at the end
void insertEnd(char value[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, value);

    if (last == NULL) {
        newNode->next = newNode->prev = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        newNode->prev = last;
        last->next->prev = newNode;
        last->next = newNode;
        last = newNode;
    }
    printf("'%s' inserted at the end.\n", value);
}

// Function to insert at the beginning
void insertBegin(char value[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, value);

    if (last == NULL) {
        newNode->next = newNode->prev = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        newNode->prev = last;
        last->next->prev = newNode;
        last->next = newNode;
    }
    printf("'%s' inserted at the beginning.\n", value);
}

// Function to delete a node
void deleteNode(char value[]) {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = last->next;
    struct Node *prev = last;

    // Single node case
    if (last == last->next && strcmp(last->data, value) == 0) {
        free(last);
        last = NULL;
        printf("'%s' deleted.\n", value);
        return;
    }

    do {
        if (strcmp(temp->data, value) == 0) {
            prev->next = temp->next;
            temp->next->prev = prev;
            if (temp == last)
                last = prev;
            free(temp);
            printf("'%s' deleted.\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);

    printf("'%s' not found in the list.\n", value);
}

// Function to display the circular doubly linked list forward
void displayForward() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;
    printf("Circular Doubly Linked List (Forward): ");
    do {
        printf("%s ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

// Function to display the list backward
void displayBackward() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last;
    printf("Circular Doubly Linked List (Backward): ");
    do {
        printf("%s ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("\n");
}

int main() {
    int choice;
    char value[50];

    while (1) {
        printf("\n--- Circular Doubly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete\n4. Display Forward\n5. Display Backward\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
        case 1:
            printf("Enter string to insert: ");
            scanf(" %[^\n]", value);
            insertBegin(value);
            break;
        case 2:
            printf("Enter string to insert: ");
            scanf(" %[^\n]", value);
            insertEnd(value);
            break;
        case 3:
            printf("Enter string to delete: ");
            scanf(" %[^\n]", value);
            deleteNode(value);
            break;
        case 4:
            displayForward();
            break;
        case 5:
            displayBackward();
            break;
        case 6:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

