#include <stdio.h>
#include <stdlib.h>

// Structure of doubly linked list node
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

// Create new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    struct node* temp = head;

    // Traverse to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Display forward
void display(struct node* head) {
    struct node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int n, i, x;
    struct node* head = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    display(head);

    return 0;
}