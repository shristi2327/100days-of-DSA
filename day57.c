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

void mirror(struct Node* root) {
    if (root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
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
    int vals[10000];
    int n = 0;
    while(scanf("%d", &vals[n]) == 1) n++;
    if (n == 0) return 0;
    
    int start = 0;
    if (n > 1 && vals[0] == n - 1) start = 1;
    
    struct Node* root = createNode(vals[start]);
    struct Node* q[10000];
    int f=0, r=0;
    if(root) q[r++] = root;
    int i = start + 1;
    while(f < r && i < n) {
        struct Node* curr = q[f++];
        curr->left = createNode(vals[i++]);
        if(curr->left) q[r++] = curr->left;
        if (i < n) {
            curr->right = createNode(vals[i++]);
            if(curr->right) q[r++] = curr->right;
        }
    }
    
    mirror(root);
    inorder(root);
    printf("\n");
    return 0;
}
