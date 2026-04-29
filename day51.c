#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

struct Node* lca(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    int n1, n2;
    if (scanf("%d %d", &n1, &n2) == 2) {
        struct Node* ans = lca(root, n1, n2);
        if (ans != NULL) printf("%d\n", ans->data);
    }
    return 0;
}
