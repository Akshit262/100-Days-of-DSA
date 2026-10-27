/*
Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
- First line contains integer m, the size of the hash table.
- Second line contains integer n, the number of operations.
- Next n lines contain INSERT or SEARCH operations.

Output Format
- Print FOUND for successful SEARCH operations.
- Print NOT FOUND for unsuccessful SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions are resolved using i*i jumps.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int m, n;

    scanf("%d", &m);
    scanf("%d", &n);

    int table[m];

    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        char operation[10];
        int key;

        scanf("%s %d", operation, &key);

        int hash = key % m;

        if (strcmp(operation, "INSERT") == 0) {
            for (int j = 0; j < m; j++) {
                int index = (hash + j * j) % m;

                if (table[index] == -1) {
                    table[index] = key;
                    break;
                }
            }
        }

        else if (strcmp(operation, "SEARCH") == 0) {
            int found = 0;

            for (int j = 0; j < m; j++) {
                int index = (hash + j * j) % m;

                if (table[index] == key) {
                    found = 1;
                    break;
                }

                if (table[index] == -1) {
                    break;
                }
            }

            if (found) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    return 0;
}
