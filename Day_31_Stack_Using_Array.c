#include <stdio.h>

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int operation;

        scanf("%d", &operation);

        if (operation == 1) {
            int value;
            scanf("%d", &value);

            if (top == MAX - 1) {
                printf("Stack Overflow\n");
            } else {
                top++;
                stack[top] = value;
            }
        }

        else if (operation == 2) {
            if (top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top]);
                top--;
            }
        }

        else if (operation == 3) {
            for (int j = top; j >= 0; j--) {
                printf("%d ", stack[j]);
            }

            printf("\n");
        }
    }

    return 0;
}