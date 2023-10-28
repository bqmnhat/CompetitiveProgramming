#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, p[501], mark[501];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        mark[p[i]] = i;
    }
}

void SolveTestCase() {
    int l = n, r = n;
    for (int i=1; i<=n; i++) {
        if (p[i] > i) {
            l = i;
            r = mark[i];
            break;
        }
    }
    for (int i=1; i<l; i++)
        cout << p[i] << ' ';
    for (int i=r; i>=l; i--)
        cout << p[i] << ' ';
    for (int i=r+1; i<=n; i++)
        cout << p[i] << ' ';
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
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
