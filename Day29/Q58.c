/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Add two numbers
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {

    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;

        if(l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if(l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = sum % 10;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
    }

    return dummy.next;
}

int main() {

    int n1, n2;

    // First list
    scanf("%d", &n1);
    struct Node *head1 = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n1; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head1 == NULL) {
            head1 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Second list
    scanf("%d", &n2);
    struct Node *head2 = NULL;
    temp = NULL;

    for(int i = 0; i < n2; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head2 == NULL) {
            head2 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    struct Node* result = addTwoNumbers(head1, head2);

    // Print result
    while(result != NULL) {
        printf("%d ", result->data);
        result = result->next;
    }

    return 0;
}