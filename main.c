#include <stdio.h>

int result[9][9];
int markR[9][9];
int markC[9][9];
int markS[3][3][9];

void solution() {
    for (int r = 0; r <= 8; r++) {
        for (int c = 0; c <= 8; c++) {
            printf("%d ", result[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int check(int r, int c, int v) {
    if (markR[r][v-1] == 1) return 0;
    if (markC[c][v-1] == 1) return 0;
    if (markS[r/3][c/3][v-1] == 1) return 0;
    return 1;
}

void find(int r, int c) {
    for (int v = 1; v <= 9 ; v++) {
        if (check(r, c, v) == 1) {
            result[r][c] = v;
            markR[r][v-1] = 1;
            markR[c][v-1] = 1;
            markS[r/3][c/3][v-1] = 1;
            if (r == 0 && c == 8) {solution();}
            else {
                if (c == 8) {find(r + 1, 0);}
                else {find(r, c + 1);}
            }
            markR[r][v-1] = 0;
            markC[c][v-1] = 0;
            markS[r/3][c/3][v-1] = 0;
        }
    }
}

int main() {
    for (int r = 0; r <= 8; r ++) {
        for (int c = 0; c <= 8; c ++) {
            for (int v = 1; v <= 9; v ++) {
                markR[r][v-1] = 0;
                markC[c][v-1] = 0;
                markS[r/3][c/3][v-1] = 0;
            }
        }
    }
    find(0, 0);
    return 0;
}