/*
 * Day 53 - Vertical Order Traversal of Binary Tree
 *
 * Problem:
 * Given a binary tree, print its vertical order traversal.
 * Nodes on the same vertical line are printed from top
 * to bottom and from left to right.
 *
 * Input:
 * - First line contains integer N
 * - Second line contains N space-separated integers
 * - -1 represents NULL
 *
 * Output:
 * - Print nodes column by column from leftmost to rightmost.
 *
 * Example:
 * Input:
 * 7
 * 1 2 3 4 5 6 7
 *
 * Output:
 * 4
 * 2
 * 1 5 6
 * 3
 * 7
 *
 * Explanation:
 * Nodes are grouped according to their horizontal distance
 * from the root.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* buildTree(int arr[], int n) {

    if (n == 0 || arr[0] == -1) {
        return NULL;
    }

    struct Node *root = createNode(arr[0]);

    struct Node *queue[n];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n && front < rear) {

        struct Node *current = queue[front++];

        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }

        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }

        i++;
    }

    return root;
}

int main() {

    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);

    if (root == NULL) {
        return 0;
    }

    struct Node *nodeQueue[n];
    int hdQueue[n];

    int front = 0;
    int rear = 0;

    nodeQueue[rear] = root;
    hdQueue[rear] = 0;
    rear++;

    int values[n];
    int distances[n];

    int count = 0;

    int minHD = 0;
    int maxHD = 0;

    while (front < rear) {

        struct Node *current = nodeQueue[front];
        int hd = hdQueue[front];

        front++;

        values[count] = current->data;
        distances[count] = hd;
        count++;

        if (hd < minHD) {
            minHD = hd;
        }

        if (hd > maxHD) {
            maxHD = hd;
        }

        if (current->left != NULL) {
            nodeQueue[rear] = current->left;
            hdQueue[rear] = hd - 1;
            rear++;
        }

        if (current->right != NULL) {
            nodeQueue[rear] = current->right;
            hdQueue[rear] = hd + 1;
            rear++;
        }
    }

    for (int hd = minHD; hd <= maxHD; hd++) {

        int first = 1;

        for (int i = 0; i < count; i++) {

            if (distances[i] == hd) {

                if (!first) {
                    printf(" ");
                }

                printf("%d", values[i]);

                first = 0;
            }
        }

        printf("\n");
    }

    return 0;
}
