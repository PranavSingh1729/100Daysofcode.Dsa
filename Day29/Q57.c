/* Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Rotate list right by k
struct Node* rotateRight(struct Node* head, int k) {

    if(head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    // Find length and last node
    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make circular
    temp->next = head;

    k = k % length;

    int steps = length - k;

    // Move to new tail
    while(steps--) {
        temp = temp->next;
    }

    // New head
    head = temp->next;

    // Break circle
    temp->next = NULL;

    return head;
}

int main() {

    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int k;
    scanf("%d", &k);

    head = rotateRight(head, k);

    // Print rotated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}