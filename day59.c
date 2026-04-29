#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int postIdx;

struct Node* buildTree(int in[], int post[], int inSt, int inEnd) {
    if (inSt > inEnd) return NULL;
    struct Node* tNode = (struct Node*)malloc(sizeof(struct Node));
    tNode->data = post[postIdx--];
    tNode->left = tNode->right = NULL;
    
    if (inSt == inEnd) return tNode;
    
    int inIndex;
    for (int i = inSt; i <= inEnd; i++) {
        if (in[i] == tNode->data) {
            inIndex = i; break;
        }
    }
    
    tNode->right = buildTree(in, post, inIndex + 1, inEnd);
    tNode->left = buildTree(in, post, inSt, inIndex - 1);
    return tNode;
}

int first = 1;
void preorder(struct Node* root) {
    if (root == NULL) return;
    if (!first) printf(" ");
    printf("%d", root->data);
    first = 0;
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int in[n], post[n];
    for(int i=0; i<n; i++) scanf("%d", &in[i]);
    for(int i=0; i<n; i++) scanf("%d", &post[i]);
    
    postIdx = n - 1;
    struct Node* root = buildTree(in, post, 0, n - 1);
    preorder(root);
    printf("\n");
    return 0;
}
