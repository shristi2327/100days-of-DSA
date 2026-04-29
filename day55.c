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
    
    struct Node* q2[10000];
    int f2=0, r2=0;
    if (root) q2[r2++] = root;
    int first = 1;
    while(f2 < r2) {
        int count = r2 - f2;
        int rightmost = -1;
        for(int k=0; k<count; k++) {
            struct Node* curr = q2[f2++];
            rightmost = curr->data;
            if(curr->left) q2[r2++] = curr->left;
            if(curr->right) q2[r2++] = curr->right;
        }
        if(!first) printf(" ");
        printf("%d", rightmost);
        first = 0;
    }
    printf("\n");
    return 0;
}
