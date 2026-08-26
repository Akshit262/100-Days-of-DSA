/*
 * Day 09 - Reverse a String
 *
 * Problem:
 * A secret system stores code names in forward order.
 * To display them in mirror format, transform the given
 * code name so that its characters appear in the opposite order.
 *
 * Input:
 * - Single line: a lowercase string containing only
 *   alphabetic characters (no spaces)
 *
 * Output:
 * - Print the transformed code name after reversing
 *   the characters.
 *
 * Example:
 * Input:
 * hello
 *
 * Output:
 * olleh
 *
 * Explanation:
 * The first character moves to the last position,
 * the second to the second-last, and so on until
 * the entire string is reversed.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    scanf("%s", str);

    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    printf("%s", str);

    return 0;
}
