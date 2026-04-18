#include <stdio.h>
#include <stdlib.h>

// Structure for node
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* createCircularList(int n) {
    if (n == 0) return NULL;

    int x;
    struct Node *head = NULL, *temp = NULL, *newNode;

    // Input first node
    scanf("%d", &x);
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = x;
    head->next = head; // points to itself (circular)
    temp = head;

    // Remaining nodes
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;

        newNode->next = head; // new node points to head
        temp->next = newNode; // previous node points to new node
        temp = newNode;
    }

    return head;
}

// Function to traverse circular linked list
void traverse(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // stop when back to head
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createCircularList(n);

    traverse(head);

    return 0;
}