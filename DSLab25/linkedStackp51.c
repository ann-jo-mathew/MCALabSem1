#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

node *top = NULL;

// Push operation
void push(int val) {
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("%d pushed successfully\n", val);
}

// Pop operation
void pop() {
    node *temp;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        temp = top;
        printf("Popped element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

// Display stack
void display() {
    node *t;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    t = top;
    while (t != NULL) {
        printf("%d\t", t->data);
        t = t->next;
    }
    printf("\n");
}

// Peek top element
void peek() {
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element = %d\n", top->data);
}

// Menu
int menu() {
    int ch;
    printf("\n*MENU*\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

// Main stack operation controller
void LinkedStackOperation() {
    int ch, val;
    ch = menu();
    while (ch != 5) {
        switch (ch) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            default:
                printf("Invalid choice\n");
        }
        ch = menu();
    }
}

int main() {
    LinkedStackOperation();
    return 0;
}

