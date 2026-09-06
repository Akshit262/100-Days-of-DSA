#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long count = 0;
    long long prefixSum = 0;

    long long prefix[n + 1];
    int frequency[n + 1];

    int unique = 0;

    prefix[unique] = 0;
    frequency[unique] = 1;
    unique++;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int found = -1;

        for (int j = 0; j < unique; j++) {
            if (prefix[j] == prefixSum) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            
            count += frequency[found];
            frequency[found]++;
        } else {
            prefix[unique] = prefixSum;
            frequency[unique] = 1;
            unique++;
        }
    }

    printf("%lld", count);

    return 0;
}