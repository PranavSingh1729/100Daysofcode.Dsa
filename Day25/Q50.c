/* Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n, struct Node** nodes) {
    struct Node *head = NULL, *temp = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        nodes[i] = (struct Node*)malloc(sizeof(struct Node));
        nodes[i]->data = value;
        nodes[i]->next = NULL;

        if(head == NULL) {
            head = nodes[i];
            temp = nodes[i];
        } else {
            temp->next = nodes[i];
            temp = nodes[i];
        }
    }
    return head;
}

// Detect cycle start
struct Node* detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* nodes[n];
    struct Node* head = createList(n, nodes);

    int pos;
    scanf("%d", &pos);  // index where tail connects (-1 if no cycle)

    if(pos != -1)
        nodes[n-1]->next = nodes[pos];

    struct Node* cycleStart = detectCycle(head);

    if(cycleStart != NULL)
        printf("Cycle starts at node with value: %d\n", cycleStart->data);
    else
        printf("No cycle\n");

    return 0;
}