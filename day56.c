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

int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;
    return (t1->data == t2->data) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
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
    
    if (root == NULL || isMirror(root->left, root->right)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
