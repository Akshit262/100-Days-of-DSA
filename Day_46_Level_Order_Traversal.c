/*
 * Day 46 - Level Order Traversal
 *
 * Problem:
 * Implement level order traversal of a binary tree.
 *
 * Input:
 * - First line: integer N
 * - Second line: N integers in level-order
 * - -1 represents NULL
 *
 * Output:
 * - Print the level-order traversal of the tree.
 *
 * Example:
 * Input:
 * 7
 * 1 2 3 4 5 6 7
 *
 * Output:
 * 1 2 3 4 5 6 7
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

void levelOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    struct Node *queue[1000];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node *current = queue[front++];

        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}
