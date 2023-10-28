#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int A, B, cnte[MaxN+5];
bool mark[MaxN+5];

void Factorize(int val, int coef) {
    int tmp = sqrt(val), i = 2;
    while ((i <= tmp) && (val > 1)) {
        while (val%i == 0) {
            mark[i] = true;
            cnte[i] += coef;
            val /= i;
        }
        i++;
    }
    if (val > 1) {
        mark[val] = true;
        cnte[val] += coef;
    }
}

void SolveTestCase() {
    Factorize(A, 1);
    Factorize(B, -1);
    int DSize = 0, Dist = 0;
    for (int i=1; i<=MaxN; i++) {
        if (mark[i]) {
            DSize++;
            Dist += abs(cnte[i]);
        }
    }
    cout << DSize << ":" << Dist << '\n';
}

void Solve() {
    int cnt = 0;
    while ((cin >> A >> B) && ((A != 0) || (B != 0))) {
        cnt++;
        memset(cnte, 0, sizeof(cnte));
        memset(mark, false, sizeof(mark));
        cout << cnt << ". ";
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
