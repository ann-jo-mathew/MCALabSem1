#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node node;
node *front = NULL, *rear = NULL;   // front = deletion end, rear = insertion end
// Insert (enqueue) operation
void insert(int val) {
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL) {       // Empty queue
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted successfully\n", val);
}
// Delete (dequeue) operation
void deleteQ() {
    node *temp;
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        printf("Deleted element: %d\n", front->data);
        front = front->next;
        if (front == NULL)
            rear = NULL;  // If queue becomes empty
        free(temp);
    }
}
// Display all queue elements
void display() {
    node *t;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    t = front;
    while (t != NULL) {
        printf("%d\t", t->data);
        t = t->next;
    }
    printf("\n");
}
// Menu function
int menu() {
    int ch;
    printf("\n*MENU*\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}
// Controller function
void LinkedQueueOperation() {
    int ch, val;
    ch = menu();
    while (ch != 4) {
        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                deleteQ();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
        ch = menu();
    }
}
// Main function
int main() {
    LinkedQueueOperation();
    return 0;
}

