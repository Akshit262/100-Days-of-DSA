/*
Problem Statement
Given an array of integers where each element represents the number of pages
in a book, and m students, allocate books such that each student gets at
least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).
*/

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
