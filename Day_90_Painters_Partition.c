#include <stdio.h>

int canPaint(int boards[], int n, int painters, long long maxTime) {
    int count = 1;
    long long currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) {
            return 0;
        }

        if (currentTime + boards[i] > maxTime) {
            count++;
            currentTime = boards[i];

            if (count > painters) {
                return 0;
            }
        } else {
            currentTime += boards[i];
        }
    }

    return 1;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int boards[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    if (k > n) {
        k = n;
    }

    long long left = boards[0];
    long long right = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > left) {
            left = boards[i];
        }

        right += boards[i];
    }

    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (canPaint(boards, n, k, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%lld", answer);

    return 0;
}