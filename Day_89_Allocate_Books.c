#include <stdio.h>

int canAllocate(int pages[], int n, int students, long long maxPages) {
    int count = 1;
    long long currentPages = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > maxPages) {
            return 0;
        }

        if (currentPages + pages[i] > maxPages) {
            count++;
            currentPages = pages[i];

            if (count > students) {
                return 0;
            }
        } else {
            currentPages += pages[i];
        }
    }

    return 1;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int pages[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    if (m > n) {
        printf("-1");
        return 0;
    }

    long long left = pages[0];
    long long right = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > left) {
            left = pages[i];
        }

        right += pages[i];
    }

    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (canAllocate(pages, n, m, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%lld", answer);

    return 0;
}