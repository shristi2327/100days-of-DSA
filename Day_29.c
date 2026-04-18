#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append node at end
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Rotate right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int n = getLength(head);
    k = k % n;  // handle k > n

    if (k == 0)
        return head;

    struct Node* temp = head;

    // Step 1: go to last node
    while (temp->next != NULL)
        temp = temp->next;

    // Step 2: make circular
    temp->next = head;

    // Step 3: move to (n-k)th node
    int steps = n - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // Step 4: set new head
    struct Node* newHead = newTail->next;

    // Step 5: break circle
    newTail->next = NULL;

    return newHead;
}

// Traverse list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main
int main() {
    int n, k, x;
    struct Node* head = NULL;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = append(head, x);
    }

    scanf("%d", &k);

    // Rotate
    head = rotateRight(head, k);

    // Output
    printList(head);

    return 0;
}