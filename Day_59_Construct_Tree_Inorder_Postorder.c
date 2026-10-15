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

struct Node* buildTree(int inorder[], int postorder[],
                       int start, int end, int *index) {

    if (start > end) {
        return NULL;
    }

    int value = postorder[*index];
    (*index)--;

    struct Node *root = createNode(value);

    int position = start;

    while (inorder[position] != value) {
        position++;
    }

    root->right = buildTree(
        inorder,
        postorder,
        position + 1,
        end,
        index
    );

    root->left = buildTree(
        inorder,
        postorder,
        start,
        position - 1,
        index
    );

    return root;
}

void preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;

    scanf("%d", &n);

    int inorder[n];
    int postorderArray[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &postorderArray[i]);
    }

    int index = n - 1;

    struct Node *root = buildTree(
        inorder,
        postorderArray,
        0,
        n - 1,
        &index
    );

    preorder(root);

    return 0;
}