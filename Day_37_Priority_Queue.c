#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    int n;
    int queue[MAX];
    int size = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char operation[10];

        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            int x;
            scanf("%d", &x);

            if (size < MAX) {
                queue[size] = x;
                size++;
            }
        }

        else if (strcmp(operation, "delete") == 0) {

            if (size == 0) {
                printf("-1\n");
            } else {
                
                int minIndex = 0;

                for (int j = 1; j < size; j++) {
                    if (queue[j] < queue[minIndex]) {
                        minIndex = j;
                    }
                }

                printf("%d\n", queue[minIndex]);

                for (int j = minIndex; j < size - 1; j++) {
                    queue[j] = queue[j + 1];
                }

                size--;
            }
        }

        else if (strcmp(operation, "peek") == 0) {

            if (size == 0) {
                printf("-1\n");
            } else {
                
                int minIndex = 0;

                for (int j = 1; j < size; j++) {
                    if (queue[j] < queue[minIndex]) {
                        minIndex = j;
                    }
                }

                printf("%d\n", queue[minIndex]);
            }
        }
    }

    return 0;
}