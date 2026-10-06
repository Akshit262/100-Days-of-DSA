/*
 * Day 50 - BST Search
 *
 * Problem:
 * Search for a given value in a Binary Search Tree.
 *
 * Input:
 * - First line: integer N
 * - Second line: N integers used to create the BST
 * - Third line: value to search
 *
 * Output:
 * - Print the value if it is found.
 * - Otherwise print "Not Found".
 *
 * Example:
 * Input:
 * 5
 * 4 2 7 1 3
 * 2
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

struct Node* insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

struct Node* search(struct Node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
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

    struct Node *result = search(root, value);

    if (result != NULL) {
        printf("%d", result->data);
    } else {
        printf("Not Found");
    }

    return 0;
}
