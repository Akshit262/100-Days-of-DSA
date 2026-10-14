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

struct Node* buildTree(int preorder[], int inorder[],
                       int start, int end, int *index) {

    if (start > end) {
        return NULL;
    }

    int value = preorder[*index];
    (*index)++;

    struct Node *root = createNode(value);

    int position = start;

    while (inorder[position] != value) {
        position++;
    }

    root->left = buildTree(preorder, inorder,
                           start, position - 1, index);

    root->right = buildTree(preorder, inorder,
                            position + 1, end, index);

    return root;
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

    int preorder[n];
    int inorder[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int index = 0;

    struct Node *root = buildTree(
        preorder,
        inorder,
        0,
        n - 1,
        &index
    );

    postorder(root);

    return 0;
}