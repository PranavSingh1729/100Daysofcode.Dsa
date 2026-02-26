/* Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
 */

 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create Doubly Linked List
    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Forward Traversal
    printf("Forward: ");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        if(temp->next == NULL) break;  // to reach last node
        temp = temp->next;
    }

    // Backward Traversal
    printf("\nBackward: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    return 0;
}