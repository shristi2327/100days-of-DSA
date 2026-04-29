#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = key;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

int first = 1;
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    if (!first) printf(" ");
    printf("%d", root->data);
    first = 0;
    inorder(root->right);
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
    
    inorder(root);
    printf("\n");
    return 0;
}
