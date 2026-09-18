#include <stdio.h>

#define MAX 1000

int main() {
    int stack[MAX];
    int n, m;
    int top = -1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        top++;
        stack[top] = value;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}