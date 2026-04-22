#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

// Enqueue operation
void enqueue(int val) {
    if (size == MAX) return;  // overflow (not expected here)

    rear = (rear + 1) % MAX;
    queue[rear] = val;
    size++;
}

// Dequeue operation
void dequeue() {
    if (size == 0) return;  // underflow (not expected here)

    front = (front + 1) % MAX;
    size--;
}

// Display queue from front to rear
void display() {
    if (size == 0) return;

    int i = front;
    for (int count = 0; count < size; count++) {
        printf("%d", queue[i]);
        if (count != size - 1) printf(" ");
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    // Input number of elements
    scanf("%d", &n);

    // Enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Number of dequeues
    scanf("%d", &m);

    // Perform dequeue operations
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Display remaining elements
    display();

    return 0;
}