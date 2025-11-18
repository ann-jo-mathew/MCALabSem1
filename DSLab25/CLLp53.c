#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;   // points to first node
// Function to insert at end
void insert(int val) {
    node *newNode, *t;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;    // points to itself (circular)
    } else {
        t = head;
        while (t->next != head)   // go till last node
            t = t->next;
        t->next = newNode;
        newNode->next = head;     // maintain circular link
    }
    printf("%d inserted successfully\n", val);
}
// Function to delete an element
void deleteNode(int val) {
    node *t, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    // If only one node and it matches
    if (head->data == val && head->next == head) {
        free(head);
        head = NULL;
        printf("%d deleted successfully\n", val);
        return;
    }
    // If head node is to be deleted
    if (head->data == val) {
        t = head;
        while (t->next != head)
            t = t->next;
        t->next = head->next;
        free(head);
        head = t->next;
        printf("%d deleted successfully\n", val);
        return;
    }
    // Otherwise, search for element
    prev = head;
    t = head->next;
    while (t != head && t->data != val) {
        prev = t;
        t = t->next;
    }
    if (t == head) {
        printf("Element not found\n");
    } else {
        prev->next = t->next;
        free(t);
        printf("%d deleted successfully\n", val);
    }
}
// Function to display all elements
void display() {
    node *t;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Elements in circular linked list:\n");
    t = head;
    do {
        printf("%d\t", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}
// Count total nodes
void countNodes() {
    node *t;
    int count = 0;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    t = head;
    do {
        count++;
        t = t->next;
    } while (t != head);
    printf("Number of nodes = %d\n", count);
}
// Search element
void search(int val) {
    node *t;
    int pos = 1;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    t = head;
    do {
        if (t->data == val) {
            printf("%d found at position %d\n", val, pos);
            return;
        }
        t = t->next;
        pos++;
    } while (t != head);
    printf("%d not found\n", val);
}
int menu() {
    int ch;
    printf("\n*MENU*\n1.Insert\n2.Delete\n3.Display\n4.Count\n5.Search\n6.Exit\nEnter choice: ");
    scanf("%d", &ch);
    return ch;
}
void CircularLinkedListOperation() {
    int ch, val;
    ch = menu();
    while (ch != 6) {
        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
            case 3:
                display();
                break;
            case 4:
                countNodes();
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            default:
                printf("Invalid choice\n");
        }
        ch = menu();
    }
}
int main() {
    CircularLinkedListOperation();
    return 0;
}

