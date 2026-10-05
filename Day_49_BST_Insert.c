/*
 * Day 49 - BST Insert
 *
 * Problem:
 * Insert a given value into a Binary Search Tree.
 *
 * Input:
 * - First line: integer N
 * - Second line: N integers representing the BST
 * - Third line: integer value to insert
 *
 * Output:
 * - Print the inorder traversal of the BST after insertion.
 *
 * Example:
 * Input:
 * 5
 * 4 2 7 1 3
 * 5
 *
 * Output:
 * 1 2 3 4 5 7
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

struct Node* insert(struct Node *root, int value) {

    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
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

int main() {

    int n;
    scanf("%d", &n);

    struct Node *root = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        root = insert(root, value);
    }

    int value;
    scanf("%d", &value);

    root = insert(root, value);

    inorder(root);

    return 0;
}
