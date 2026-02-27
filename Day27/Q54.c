/* Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n, struct Node* arr[]) {
    struct Node *head = NULL, *temp = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        arr[i] = (struct Node*)malloc(sizeof(struct Node));
        arr[i]->data = value;
        arr[i]->next = NULL;

        if(head == NULL) {
            head = arr[i];
            temp = arr[i];
        } else {
            temp->next = arr[i];
            temp = arr[i];
        }
    }
    return head;
}

// Remove cycle
bool removeLoop(struct Node* head) {

    if(head == NULL || head->next == NULL)
        return false;

    struct Node *slow = head, *fast = head;

    // Detect cycle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {

            slow = head;

            // If cycle starts at head
            if(slow == fast) {
                while(fast->next != slow)
                    fast = fast->next;
            }
            else {
                while(slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            // Break cycle
            fast->next = NULL;
            return true;
        }
    }

    return false;
}

// Print list safely (after cycle removal)
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    int n;
    scanf("%d", &n);

    struct Node* arr[n];
    struct Node* head = createList(n, arr);

    int pos;
    scanf("%d", &pos);  // position where tail connects (-1 if no cycle)

    // Create cycle if pos != -1
    if(pos != -1)
        arr[n-1]->next = arr[pos];

    bool removed = removeLoop(head);

    if(removed)
        printf("true\n");
    else
        printf("false\n");

    // Print list after removal
    printList(head);

    return 0;
}