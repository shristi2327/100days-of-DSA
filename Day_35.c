#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int val) {
    if (rear == MAX - 1) {
        // Overflow (not needed here but safe)
        return;
    }

    if (front == -1) front = 0;

    queue[++rear] = val;
}

// Display queue
void display() {
    if (front == -1) return;

    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i != rear) printf(" ");
    }
}

// Main function
int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    return 0;
}