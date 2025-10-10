#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

Node* head = NULL;

// Create a new node
Node* createNode(char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insert(char* value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Count nodes
int count() {
    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Find string
Node* find(char* value) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data, value) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Find and replace first occurrence
void findAndReplace(char* findStr, char* replaceStr) {
    Node* temp = find(findStr);
    if (temp) {
        strcpy(temp->data, replaceStr);
        printf("Replaced '%s' with '%s'.\n", findStr, replaceStr);
    } else {
        printf("'%s' not found.\n", findStr);
    }
}

// Replace all occurrences
void replaceAll(char* findStr, char* replaceStr) {
    Node* temp = head;
    int replaced = 0;
    while (temp != NULL) {
        if (strcmp(temp->data, findStr) == 0) {
            strcpy(temp->data, replaceStr);
            replaced++;
        }
        temp = temp->next;
    }

    if (replaced)
        printf("Replaced %d occurrence(s) of '%s' with '%s'.\n", replaced, findStr, replaceStr);
    else
        printf("'%s' not found.\n", findStr);
}

// Reverse list
void reverse() {
    Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Sort alphabetically
void sort() {
    if (head == NULL)
        return;

    Node *i, *j;
    char temp[100];

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->data, j->data) > 0) {
                strcpy(temp, i->data);
                strcpy(i->data, j->data);
                strcpy(j->data, temp);
            }
        }
    }
}

// Main program
int main() {
    int choice;
    char str[100], findStr[100], replaceStr[100];

    while (1) {
        printf("\n--- Singly Linked List Menu (Strings) ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Find\n");
        printf("5. Find and Replace (first)\n");
        printf("6. Replace All\n");
        printf("7. Reverse\n");
        printf("8. Sort\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter string to insert: ");
                gets(str);
                insert(str);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Total nodes: %d\n", count());
                break;

            case 4:
                printf("Enter string to find: ");
                gets(findStr);
                if (find(findStr))
                    printf("'%s' found in the list.\n", findStr);
                else
                    printf("'%s' not found.\n", findStr);
                break;

            case 5:
                printf("Enter string to find: ");
                gets(findStr);
                printf("Enter replacement string: ");
                gets(replaceStr);
                findAndReplace(findStr, replaceStr);
                break;

            case 6:
                printf("Enter string to replace: ");
                gets(findStr);
                printf("Enter replacement string: ");
                gets(replaceStr);
                replaceAll(findStr, replaceStr);
                break;

            case 7:
                reverse();
                printf("List reversed.\n");
                break;

            case 8:
                sort();
                printf("List sorted alphabetically.\n");
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
