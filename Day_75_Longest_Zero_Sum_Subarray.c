#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

struct Pair {
    long long sum;
    int index;
};

int main() {
    int arr[MAX];
    int n = 0;

    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }

    struct Pair *first = malloc((2 * MAX + 1) * sizeof(struct Pair));

    int size = 2 * MAX + 1;

    for (int i = 0; i < size; i++) {
        first[i].sum = 0;
        first[i].index = -2;
    }

    int offset = MAX;
    long long prefixSum = 0;
    int longest = 0;

    first[offset].sum = 0;
    first[offset].index = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = (int)prefixSum + offset;

        if (first[index].index == -2) {
            first[index].sum = prefixSum;
            first[index].index = i;
        } else {
            int length = i - first[index].index;

            if (length > longest) {
                longest = length;
            }
        }
    }

    printf("%d", longest);

    free(first);

    return 0;
}