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
    int i = 1;

    queue[rear++] = root;

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

int isMirror(struct Node *left, struct Node *right) {
    if (left == NULL && right == NULL) {
        return 1;
    }

    if (left == NULL || right == NULL) {
        return 0;
    }

    if (left->data != right->data) {
        return 0;
    }

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
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
        printf("YES");
    }
    else if (isMirror(root->left, root->right)) {
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}