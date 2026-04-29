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

struct Node* lca(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;
    struct Node* left_lca = lca(root->left, n1, n2);
    struct Node* right_lca = lca(root->right, n1, n2);
    if (left_lca != NULL && right_lca != NULL) return root;
    return (left_lca != NULL) ? left_lca : right_lca;
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
        curr->left = createNode(val);
        if (curr->left != NULL) queue[rear++] = curr->left;
        i++;
        if (i < n) {
            scanf("%d", &val);
            curr->right = createNode(val);
            if (curr->right != NULL) queue[rear++] = curr->right;
            i++;
        }
    }
    
    while (i < n) { scanf("%d", &val); i++; }
    
    int n1, n2;
    if (scanf("%d %d", &n1, &n2) == 2) {
        struct Node* ans = lca(root, n1, n2);
        if (ans != NULL) printf("%d\n", ans->data);
    }
    return 0;
}
