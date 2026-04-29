#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int hd;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->hd = 0;
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
    
    if (!root) { printf("\n"); return 0; }
    root->hd = 0;
    struct Node* vq[10000];
    int vf=0, vr=0;
    vq[vr++] = root;
    
    int min_hd = 0, max_hd = 0;
    while(vf < vr) {
        struct Node* curr = vq[vf++];
        if(curr->hd < min_hd) min_hd = curr->hd;
        if(curr->hd > max_hd) max_hd = curr->hd;
        if(curr->left) { curr->left->hd = curr->hd - 1; vq[vr++] = curr->left; }
        if(curr->right){ curr->right->hd = curr->hd + 1; vq[vr++] = curr->right;}
    }
    
    int first = 1;
    for(int d = min_hd; d <= max_hd; d++) {
        for(int k=0; k<vr; k++) {
            if(vq[k]->hd == d) {
                if(!first) printf(" ");
                printf("%d", vq[k]->data);
                first = 0;
            }
        }
    }
    printf("\n");
    return 0;
}
