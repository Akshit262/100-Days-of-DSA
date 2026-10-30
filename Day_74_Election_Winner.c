#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_SIZE 100

struct Candidate {
    char name[NAME_SIZE];
    int votes;
};

int main() {
    int n;

    scanf("%d", &n);

    struct Candidate candidates[MAX];
    int count = 0;

    for (int i = 0; i < n; i++) {
        char name[NAME_SIZE];
        int found = 0;

        scanf("%s", name);

        for (int j = 0; j < count; j++) {
            if (strcmp(candidates[j].name, name) == 0) {
                candidates[j].votes++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(candidates[count].name, name);
            candidates[count].votes = 1;
            count++;
        }
    }

    int winner = 0;

    for (int i = 1; i < count; i++) {
        if (candidates[i].votes > candidates[winner].votes) {
            winner = i;
        }
        else if (candidates[i].votes == candidates[winner].votes) {
            if (strcmp(candidates[i].name, candidates[winner].name) < 0) {
                winner = i;
            }
        }
    }

    printf("%s %d", candidates[winner].name, candidates[winner].votes);

    return 0;
}