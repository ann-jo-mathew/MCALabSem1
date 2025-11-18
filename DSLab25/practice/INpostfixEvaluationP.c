#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char e) {
    if (top + 1 == 50)
        printf("Error: Stack Overflow\n");
    else
        stack[++top] = e;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int order(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            // directly copy numbers
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (top != -1 && order(stack[top]) >= order(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

int apply(int a, int b, char sign) {
    switch (sign) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default:  return 0;
    }
}

int evaluatePostfix(char postfix[]) {
    int vstack[50], vtop = -1;
    int i, v1, v2;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            vstack[++vtop] = postfix[i] - '0'; // convert char ? int
        } else if (postfix[i] == '+' || postfix[i] == '-' ||
                   postfix[i] == '*' || postfix[i] == '/') {
            v2 = vstack[vtop--];
            v1 = vstack[vtop--];
            vstack[++vtop] = apply(v1, v2, postfix[i]);
        }
    }
    return vstack[vtop];
}

int main() {
    char infix[50], postfix[50];
    printf("Enter infix expression (no spaces): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}

