#include <stdio.h>
#include <stdlib.h>
#define SIZE 100   // Queue size increased to 100

int cq[SIZE];     // Circular queue array
int front = -1, rear = -1;

// Function to insert an element (enqueue)
void enqueue(int val) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow! Cannot insert %d\n", val);
        return;
    }

    if (front == -1)  // first insertion
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    cq[rear] = val;
    printf("%d inserted successfully\n", val);
}

// Function to delete an element (dequeue)
void dequeue() {
    int val;
    if (front == -1) {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }

    val = cq[front];

    if (front == rear)   // only one element
        front = rear = -1;
    else
        front = (front + 1) % SIZE;

    printf("%d deleted successfully\n", val);
}

// Function to display the elements
void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Circular Queue elements:\n");
    i = front;
    while (1) {
        printf("%d\t", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Function to view the front element
void peek() {
    if (front == -1)
        printf("Queue is empty\n");
    else
        printf("Front element = %d\n", cq[front]);
}

// Function to count number of elements
void count() {
    if (front == -1)
        printf("Queue is empty\n");
    else if (rear >= front)
        printf("Total elements = %d\n", rear - front + 1);
    else
        printf("Total elements = %d\n", SIZE - front + rear + 1);
}

// Menu display
int menu() {
    int ch;
    printf("\n*MENU*\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Count\n6.Exit\nEnter choice: ");
    scanf("%d", &ch);
    return ch;
}

// Controller function
void CircularQueueOperation() {
    int ch, val;
    ch = menu();
    while (ch != 6) {
        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                count();
                break;
            default:
                printf("Invalid choice\n");
        }
        ch = menu();
    }
}

// Main function
int main() {
    CircularQueueOperation();
    return 0;
}

