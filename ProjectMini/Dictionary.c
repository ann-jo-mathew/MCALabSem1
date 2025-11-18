#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct Node {			// Structure of a Dictionary Node
    char word[50];
    char meaning[200];
    struct Node *left, *right;
};
struct Node* createNode(char *word, char *meaning) {		// Function to create a new node and insert first node/leaf
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, char *word, char *meaning) {		// Insert a word into BST
    if (root == NULL)
        return createNode(word, meaning);
    int cmp = strcmp(word, root->word);
    if (cmp < 0)		//cmp less them root is greater so left child
        root->left = insert(root->left, word, meaning);
    else if (cmp > 0)		//root is less so right child
        root->right = insert(root->right, word, meaning);
    else
        printf("Word already exists!\n");
    return root;
}
void search(struct Node* root, char *word) {		// finds a words meaning
    if (root == NULL) {
        printf("Word not found.\n");
        return;
    }
    int cmp = strcmp(word, root->word);
    if (cmp == 0)
        printf("%s : %s\n", root->word, root->meaning);
    else if (cmp < 0)		//search left subtree.
        search(root->left, word);
    else							//search right subtree
        search(root->right, word);
}
struct Node* findMin(struct Node* node) {		// Find minimum value node for deletion
    struct Node* current = node;
    while (current && current->left != NULL)	//it finds the node graeter than the deleted 
        current = current->left;
    return current;
}
struct Node* deleteW(struct Node* root, char *word) {		// Delete a word from BST
    if (root == NULL) return root;
    int cmp = strcmp(word, root->word);
    if (cmp < 0)
        root->left = deleteW(root->left, word);
    else if (cmp > 0)
        root->right = deleteW(root->right, word);
    else {											// Node found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);
        root->right = deleteW(root->right, temp->word);
    }
    return root;
}
void display(struct Node* root) {		// Display dictionary (Inorder traversal)
    if (root != NULL) {
        display(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        display(root->right);
    }
}
void collectNodes(struct Node* root, struct Node* arr[], int *count) {		// Collect words into an array for quiz
    if (root == NULL) return;
    collectNodes(root->left, arr, count);
    arr[(*count)++] = root;
    collectNodes(root->right, arr, count);
}
void selfTest(struct Node* root) {		// Self-Test Game
    if (root == NULL) {
        printf("Dictionary is empty. Add some words first!\n");
        return;
    }
    struct Node* arr[100];
    int count = 0;
    collectNodes(root, arr, &count);
    srand(time(0));					//seed random number generator
    int index = rand() % count;
    char guess[50];
    printf("\nMeaning: %s\n", arr[index]->meaning);
    printf("Guess the word: ");
    scanf(" %[^\n]", guess);
    if (strcmp(guess, arr[index]->word) == 0)
        printf("Correct! Well done.\n");
    else
        printf("Wrong! The correct word is '%s'.\n", arr[index]->word);
}
int main() {
    struct Node* root = NULL;
    int choice;
    char word[50], meaning[200];
    printf("--- INTERACTIVE DICTIONARY WITH SELF-TEST ---\n");
    while (1) {
        printf("\n1. Insert new word");
        printf("\n2. Search word");
        printf("\n3. Delete word");
        printf("\n4. Display all words (sorted)");
        printf("\n5. Play Self-Test");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter word: ");
            scanf(" %[^\n]", word);
            printf("Enter meaning: ");
            scanf(" %[^\n]", meaning);
            root = insert(root, word, meaning);
            break;
        case 2:
            printf("Enter word to search: ");
            scanf(" %[^\n]", word);
            search(root, word);
            break;
        case 3:
            printf("Enter word to delete: ");
            scanf(" %[^\n]", word);
            root = deleteW(root, word);
            break;
        case 4:
            printf("\n--- Dictionary Words (Sorted) ---\n");
            display(root);
            break;
        case 5:
            selfTest(root);
            break;
        case 6:
            printf("Exiting... Thank you!\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

