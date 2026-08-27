/*
 * Day 10 - Check Palindrome Using Two Pointers
 *
 * Problem:
 * Read a string and check if it is a palindrome using
 * two-pointer comparison.
 *
 * Input:
 * - Single line: string s
 *
 * Output:
 * - Print YES if the string is a palindrome.
 * - Otherwise print NO.
 *
 * Example:
 * Input:
 * level
 *
 * Output:
 * YES
 *
 * Explanation:
 * The string reads the same forwards and backwards.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];

    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1;

    int isPalindrome = 1;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }

        left++;
        right--;
    }

    if (isPalindrome) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
