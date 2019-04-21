#include <bits/stdc++.h>
using namespace std;

int n, value, diagonal, a, b;

int main() {
    while(scanf("%d", &n) == 1) {
        value = n;
        for(diagonal = 1; value > diagonal; diagonal++)
            value -= diagonal;

        if(diagonal % 2) a = 1 + diagonal - value;
        else a = value;

        b = diagonal - a + 1;
        printf("TERM %d IS %d/%d\n", n, a, b);
    }
}
