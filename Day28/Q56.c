/* 234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome or false otherwise. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Reverse linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Check palindrome
bool isPalindrome(struct Node* head) {

    if(head == NULL || head->next == NULL)
        return true;

    struct Node *slow = head, *fast = head;

    // Find middle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct Node* secondHalf = reverse(slow);
    struct Node* firstHalf = head;

    // Compare
    while(secondHalf != NULL) {
        if(firstHalf->data != secondHalf->data)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
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

    if(isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}