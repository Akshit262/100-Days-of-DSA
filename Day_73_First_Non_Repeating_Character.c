#include <stdio.h>

int main() {
    char s[1000];
    int count[26] = {0};

    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (count[s[i] - 'a'] == 1) {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("$");

    return 0;
}