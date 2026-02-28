/* Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;

    scanf("%d", &n);

    if(n <= 0) {
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create first node
    head = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d", &head->data);
    head->next = head;   // Point to itself initially
    temp = head;

    // Create remaining nodes
    for(int i = 1; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);

        newNode->next = head;   // New node points to head
        temp->next = newNode;   // Previous node points to new node
        temp = newNode;         // Move temp forward
    }

    // Traversal of circular linked list
    struct Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while(current != head);

    return 0;
}