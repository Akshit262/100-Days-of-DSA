/*
 * Day 44 - Inorder, Preorder and Postorder Traversals
 *
 * Problem:
 * Perform inorder, preorder, and postorder traversals
 * of a given binary tree.
 *
 * Input:
 * - First line contains integer N
 * - Second line contains level-order traversal
 * - -1 represents NULL
 *
 * Output:
 * - Print inorder traversal
 * - Print preorder traversal
 * - Print postorder traversal
 *
 * Example:
 * Input:
 * 7
 * 1 2 3 4 5 6 7
 *
 * Output:
 * 4 2 5 1 6 3 7
 * 1 2 4 5 3 6 7
 * 4 5 2 6 7 3 1
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

void inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}
