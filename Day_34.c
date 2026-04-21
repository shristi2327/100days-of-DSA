#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        return 0; // underflow case (not expected here)
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If operand (number)
        if (isdigit(exp[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(&stack, num);
        }
        else {
            // Operator
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            if (exp[i] == '+') result = a + b;
            else if (exp[i] == '-') result = a - b;
            else if (exp[i] == '*') result = a * b;
            else if (exp[i] == '/') result = a / b;

            push(&stack, result);
            i++;
        }
    }

    return pop(&stack);
}

// Main
int main() {
    char exp[1000];

    // Read full line (including spaces)
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d\n", result);

    return 0;
}