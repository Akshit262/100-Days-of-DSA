#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **top, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = *top;

    *top = newNode;
}

int pop(struct Node **top) {
    struct Node *temp = *top;
    int value = temp->data;

    *top = temp->next;

    free(temp);

    return value;
}

int main() {
    char expression[1000];

    fgets(expression, sizeof(expression), stdin);

    struct Node *top = NULL;

    char *token = strtok(expression, " \n");

    while (token != NULL) {

        if (token[0] >= '0' && token[0] <= '9') {
            push(&top, atoi(token));
        }

        else {
            int b = pop(&top);
            int a = pop(&top);

            int result;

            if (token[0] == '+') {
                result = a + b;
            }
            else if (token[0] == '-') {
                result = a - b;
            }
            else if (token[0] == '*') {
                result = a * b;
            }
            else if (token[0] == '/') {
                result = a / b;
            }

            push(&top, result);
        }

        token = strtok(NULL, " \n");
    }

    printf("%d", pop(&top));

    return 0;
}