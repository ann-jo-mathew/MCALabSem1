#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for doubly linked list
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;

node *head = NULL;

// Function to insert at the end
void insertEnd(int val) {
    node *temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {  // First node
        head = temp;
    } else {
        node *t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = temp;
        temp->prev = t;
    }
    printf("%d inserted at end\n", val);
}

// Function to insert at the beginning
void insertStart(int val) {
    node *temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL)
        head->prev = temp;
    head = temp;
    printf("%d inserted at start\n", val);
}

// Function to delete a node with a specific value
void deleteNode(int val) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *t = head;
    while (t != NULL && t->data != val)
        t = t->next;

    if (t == NULL) {
        printf("%d not found\n", val);
        return;
    }

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        head = t->next;  // Deleting first node

    if (t->next != NULL)
        t->next->prev = t->prev;

    free(t);
    printf("%d deleted successfully\n", val);
}

// Function to display the list
void display() {
    node *t = head;
    if (t == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List elements:\n");
    while (t != NULL) {
        printf("%d\t", t->data);
        t = t->next;
    }
    printf("\n");
}

// Function to display the list in reverse
void reverseDisplay() {
    node *t = head;
    if (t == NULL) {
        printf("List is empty\n");
        return;
    }

    while (t->next != NULL)
        t = t->next;

    printf("List in reverse order:\n");
    while (t != NULL) {
        printf("%d\t", t->data);
        t = t->prev;
    }
    printf("\n");
}

// Function to count number of nodes
void countNodes() {
    node *t = head;
    int count = 0;
    while (t != NULL) {
        count++;
        t = t->next;
    }
    printf("Total nodes = %d\n", count);
}

// Function to sort the list using values (bubble sort)
void sortList() {
    node *i, *j;
    int temp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully\n");
}

// Menu function
int menu() {
    int ch;
    printf("\n*MENU*\n1.Insert at End\n2.Insert at Start\n3.Delete Node\n4.Display\n5.Reverse Display\n6.Exit\nEnter choice: ");
    scanf("%d", &ch);
    return ch;
}

// Controller function
void DoublyLinkedListOperation() {
    int ch, val;
    ch = menu();
    while (ch != 6) {
        switch (ch) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 2:
                printf("Enter value to insert at start: ");
                scanf("%d", &val);
                insertStart(val);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
            case 4:
                display();
                break;
            case 5:
                reverseDisplay();
                break;
            default:
                printf("Invalid choice\n");
        }
        ch = menu();
    }
}

// Main function
int main() {
    DoublyLinkedListOperation();
    return 0;
}

