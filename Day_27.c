#include <stdio.h>
#include <stdlib.h>

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
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1, *p2 = head2;

    // Step 1: Align both lists
    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            p1 = p1->next;
    } else {
        for (int i = 0; i < diff; i++)
            p2 = p2->next;
    }

    // Step 2: Traverse together
    while (p1 && p2) {
        if (p1->data == p2->data)   // comparing values
            return p1->data;

        p1 = p1->next;
        p2 = p2->next;
    }

    return -1; // No intersection
}

int main() {
    int n, m, x;

    struct Node *head1 = NULL, *head2 = NULL;

    // Input first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = append(head1, x);
    }

    // Input second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = append(head2, x);
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection\n");
    else
        printf("%d\n", result);

    return 0;
}