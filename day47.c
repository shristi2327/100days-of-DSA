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

int getHeight(struct Node* root) {
    if (root == NULL) return 0;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) { printf("0\n"); return 0; }
    
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
    
    printf("%d\n", getHeight(root));
    return 0;
}
