#include <bits/stdc++.h>
using namespace std;
#define Max 1000
int n;
char s[Max + 1];

void knuths_permutation(int i, char* t) {
    if (i == n) {
        t[n] = '\0';
        printf("%s\n", t);
        return;
    }
    char u[n + 1];
    u[0] = s[i];
    memcpy(&u[1], t, i); 
    knuths_permutation(i + 1, u);
    for (int j = 0; j < i; j++) {
        swap(u[j], u[j + 1]);
        knuths_permutation(i + 1, u);
    }
}

int main(void) {

    bool printed = false;
    char t[Max + 1];
    while (scanf("%s", s) != EOF) {
        n = strlen(s);
        if (printed)
            putchar('\n');
        else
            printed = true;
        knuths_permutation(0, t);
    }
    return 0;
}
