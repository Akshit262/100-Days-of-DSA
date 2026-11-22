#include <stdio.h>

int main() {
    long long n;

    scanf("%lld", &n);

    if (n == 0 || n == 1) {
        printf("%lld", n);
        return 0;
    }

    long long left = 1;
    long long right = n;
    long long answer = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid <= n / mid) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%lld", answer);

    return 0;
}