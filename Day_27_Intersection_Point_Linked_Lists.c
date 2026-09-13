/*
 * Day 27 - Find Intersection Point of Two Linked Lists
 *
 * Problem:
 * Find the intersection point of two linked lists.
 *
 * Input:
 * - First line: integer n
 * - Second line: n space-separated integers (first list)
 * - Third line: integer m
 * - Fourth line: m space-separated integers (second list)
 *
 * Output:
 * - Print the value of the intersection node
 * - Otherwise print "No Intersection"
 *
 * Example:
 * Input:
 * 5
 * 10 20 30 40 50
 * 4
 * 15 25 30 40 50
 *
 * Output:
 * 30
 *
 * Explanation:
 * Calculate the lengths of both lists, advance the pointer
 * in the longer list, and then traverse both lists together.
 * The first common value is treated as the intersection.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

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

int getLength(struct Node *head) {
    int length = 0;

    while (head != NULL) {
        length++;
        head = head->next;
    }

    return length;
}

int main() {
    int n, m;

    scanf("%d", &n);

    struct Node *head1 = NULL;
    struct Node *tail1 = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        insertEnd(&head1, &tail1, value);
    }

    scanf("%d", &m);

    struct Node *head2 = NULL;
    struct Node *tail2 = NULL;

    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);

        insertEnd(&head2, &tail2, value);
    }

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *current1 = head1;
    struct Node *current2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            current1 = current1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            current2 = current2->next;
        }
    }

    int found = 0;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data == current2->data) {
            printf("%d", current1->data);
            found = 1;
            break;
        }

        current1 = current1->next;
        current2 = current2->next;
    }

    if (!found) {
        printf("No Intersection");
    }

    return 0;
}
