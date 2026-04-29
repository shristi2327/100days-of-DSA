#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) return 0;
    
    int val;
    scanf("%d", &val);
    struct Node* root = createNode(val);
    
    struct Node* queue[10000];
    int front = 0, rear = 0;
    if (root != NULL) queue[rear++] = root;
    
    int i = 1;
    while (front < rear && i < n) {
        struct Node* curr = queue[front++];
        scanf("%d", &val);
        struct Node* leftNode = createNode(val);
        curr->left = leftNode;
        if (leftNode != NULL) queue[rear++] = leftNode;
        i++;
        if (i < n) {
            scanf("%d", &val);
            struct Node* rightNode = createNode(val);
            curr->right = rightNode;
            if (rightNode != NULL) queue[rear++] = rightNode;
            i++;
        }
    }
    
    front = 0; rear = 0;
    if (root != NULL) queue[rear++] = root;
    int first = 1;
    while (front < rear) {
        struct Node* curr = queue[front++];
        if (!first) printf(" ");
        printf("%d", curr->data);
        first = 0;
        if (curr->left != NULL) queue[rear++] = curr->left;
        if (curr->right != NULL) queue[rear++] = curr->right;
    }
    printf("\n");
    return 0;
}
