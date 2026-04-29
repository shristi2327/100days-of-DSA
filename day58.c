#include <stdio.h>
#include <stdlib.h>

int preIdx = 0;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* buildTree(int in[], int pre[], int inSt, int inEnd) {
    if (inSt > inEnd) return NULL;
    struct Node* tNode = (struct Node*)malloc(sizeof(struct Node));
    tNode->data = pre[preIdx++];
    tNode->left = tNode->right = NULL;
    
    if (inSt == inEnd) return tNode;
    
    int inIndex;
    for (int i = inSt; i <= inEnd; i++) {
        if (in[i] == tNode->data) {
            inIndex = i;
            break;
        }
    }
    
    tNode->left = buildTree(in, pre, inSt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    return tNode;
}

int first = 1;
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    if (!first) printf(" ");
    printf("%d", root->data);
    first = 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int pre[n], in[n];
    for(int i=0; i<n; i++) scanf("%d", &pre[i]);
    for(int i=0; i<n; i++) scanf("%d", &in[i]);
    
    struct Node* root = buildTree(in, pre, 0, n - 1);
    postorder(root);
    printf("\n");
    return 0;
}
