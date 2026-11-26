/*
Problem Statement
Given n boards of different lengths and k painters, each painter paints
contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60),
while the other paints board of length 40.
*/

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
