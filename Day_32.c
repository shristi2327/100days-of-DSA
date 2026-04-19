#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int val) {
    if (top == MAX - 1) {
        // Overflow (not needed in problem, but safe)
        return;
    }
    stack[++top] = val;
}

// Pop function
void pop() {
    if (top == -1) {
        // Underflow (not expected here)
        return;
    }
    top--;
}

// Display stack (top to bottom)
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) printf(" ");
    }
}

int main() {
    int n, m, x;

    // Input number of elements
    scanf("%d", &n);

    // Push elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}