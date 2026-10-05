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