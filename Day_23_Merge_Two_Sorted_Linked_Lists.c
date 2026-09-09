#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Add node at the end of a linked list
void insertEnd(struct Node **head, struct Node **tail, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Merge two sorted linked lists
struct Node* mergeLists(struct Node *head1, struct Node *head2) {
    struct Node dummy;
    struct Node *tail = &dummy;

    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {

        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }

        tail = tail->next;
    }

    // Add remaining nodes
    if (head1 != NULL) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }

    return dummy.next;
}

// Print linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);

    struct Node *head1 = NULL;
    struct Node *tail1 = NULL;

    // Create first sorted list
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertEnd(&head1, &tail1, value);
    }

    scanf("%d", &m);

    struct Node *head2 = NULL;
    struct Node *tail2 = NULL;

    // Create second sorted list
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        insertEnd(&head2, &tail2, value);
    }

    // Merge both lists
    struct Node *merged = mergeLists(head1, head2);

    // Print merged list
    printList(merged);

    return 0;
}