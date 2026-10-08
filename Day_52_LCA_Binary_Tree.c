/*
 * Problem: Find Lowest Common Ancestor (LCA) of two nodes
 *          in a Binary Tree.
 *
 * Input:
 * - First line: integer N
 * - Second line: N integers in level-order
 * - -1 represents NULL
 * - Third line: two node values
 *
 * Output:
 * - Print the LCA value.
 *
 * Example:
 * Input:
 * 7
 * 1 2 3 4 5 6 7
 * 4 5
 *
 * Output:
 * 2
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

struct Node* findLCA(struct Node *root, int a, int b) {

    if (root == NULL) {
        return NULL;
    }

    if (root->data == a || root->data == b) {
        return root;
    }

    struct Node *left = findLCA(root->left, a, b);

    struct Node *right = findLCA(root->right, a, b);

    if (left != NULL && right != NULL) {
        return root;
    }

    if (left != NULL) {
        return left;
    }

    return right;
}

int main() {

    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node *root = buildTree(arr, n);

    struct Node *lca = findLCA(root, a, b);

    if (lca != NULL) {
        printf("%d", lca->data);
    }

    return 0;
}
