#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char c) {
    stack[++top] = c;
}

// Pop
char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Peek
char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Check precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Main function to convert infix to postfix
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand → add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If '(' → push
        else if (ch == '(') {
            push(ch);
        }
        // If ')' → pop until '('
        else if (ch == ')') {
            while (peek() != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s\n", postfix);
}

// Main
int main() {
    char infix[MAX];

    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}