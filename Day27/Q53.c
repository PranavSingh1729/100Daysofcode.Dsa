/* Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list) */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create list
struct Node* createList(int n, struct Node** arr) {
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

// Find intersection
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    if(head1 == NULL || head2 == NULL)
        return NULL;

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    while(p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }

    return p1;  // either intersection node or NULL
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* arr1[n];
    struct Node* head1 = createList(n, arr1);

    scanf("%d", &m);
    struct Node* arr2[m];
    struct Node* head2 = createList(m, arr2);

    // OPTIONAL: create intersection manually
    int pos;
    scanf("%d", &pos); // index in list1 to connect list2 tail (-1 if no intersection)

    if(pos != -1)
        arr2[m-1]->next = arr1[pos];

    struct Node* intersection = getIntersection(head1, head2);

    if(intersection)
        printf("Intersection at node with value: %d\n", intersection->data);
    else
        printf("No intersection\n");

    return 0;
}