#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int t, q, n, cnt[2][MaxN+1];
string s;

void CalCnt() {
    for (int i=0; i<n; i++) {
        if (i == 0)
            cnt[0][i] = cnt[1][i] = 0;
        else {
            cnt[0][i] = cnt[0][i-1];
            cnt[1][i] = cnt[1][i-1];
        }
        if ((s[i] == '[') || (s[i] == ']'))
            cnt[i%2][i]++;
    }
}

int Cost(int l, int r) {
    int even = cnt[0][r] - cnt[0][l-1], odd = cnt[1][r] - cnt[1][l-1];
    int rem = max(even, odd) - min(even, odd);
    return rem;
}

void SolveTestCase() {
    cin >> q;
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << Cost(l, r) << '\n';
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        n = s.length();
        CalCnt();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
