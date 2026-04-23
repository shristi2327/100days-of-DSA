#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;
int count = 0;

// Check empty
bool empty() {
    return count == 0;
}

// Size
int size() {
    return count;
}

// Push front
void push_front(int x) {
    if (count == MAX) return;

    if (empty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
    count++;
}

// Push back
void push_back(int x) {
    if (count == MAX) return;

    if (empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
    count++;
}

// Pop front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (count == 1) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    count--;
}

// Pop back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (count == 1) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }

    count--;
}

// Front element
void get_front() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// Back element
void get_back() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// Clear deque
void clearDeque() {
    front = rear = -1;
    count = 0;
}

// Reverse deque
void reverse() {
    if (count <= 1) return;

    int i = front, j = rear;

    for (int k = 0; k < count / 2; k++) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

// Sort (simple bubble sort for clarity)
void sortDeque() {
    if (count <= 1) return;

    int arr[MAX];
    int i = front;

    // Copy elements
    for (int k = 0; k < count; k++) {
        arr[k] = deque[i];
        i = (i + 1) % MAX;
    }

    // Bubble sort
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    // Copy back
    front = 0;
    rear = count - 1;
    for (int i = 0; i < count; i++) {
        deque[i] = arr[i];
    }
}

// Display deque
void display() {
    if (empty()) return;

    int i = front;
    for (int k = 0; k < count; k++) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main driver
int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            get_front();
        }
        else if (strcmp(op, "back") == 0) {
            get_back();
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%s\n", empty() ? "true" : "false");
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(op, "clear") == 0) {
            clearDeque();
        }
        else if (strcmp(op, "reverse") == 0) {
            reverse();
        }
        else if (strcmp(op, "sort") == 0) {
            sortDeque();
        }
        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}