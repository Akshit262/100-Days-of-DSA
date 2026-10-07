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

struct Node* findLCA(struct Node *root, int a, int b) {

    while (root != NULL) {

        if (a < root->data && b < root->data) {
            root = root->left;
        }

        else if (a > root->data && b > root->data) {
            root = root->right;
        }

        else {
            return root;
        }
    }

    return NULL;
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

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node *lca = findLCA(root, a, b);

    if (lca != NULL) {
        printf("%d", lca->data);
    }

    return 0;
}