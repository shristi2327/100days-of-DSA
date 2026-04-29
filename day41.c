#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int val;
            scanf("%d", &val);
            struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = val;
            temp->next = NULL;
            if (rear == NULL) {
                front = temp;
                rear = temp;
            } else {
                rear->next = temp;
                rear = temp;
            }
        } else if (op == 2) {
            if (front == NULL) {
                printf("-1\n");
            } else {
                printf("%d\n", front->data);
                struct Node* temp = front;
                front = front->next;
                if (front == NULL) {
                    rear = NULL;
                }
                free(temp);
            }
        }
    }
    return 0;
}
