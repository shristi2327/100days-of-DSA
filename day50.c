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

int search(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
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
    
    int target;
    if (scanf("%d", &target) == 1) {
        if (search(root, target)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    
    return 0;
}
