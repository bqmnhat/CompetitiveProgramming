#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll sumcol[10001], sumrow[10001];

void Solve() {
    ll aij;
    for (int i=1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            cin >> aij;
            sumcol[j] += aij;
            sumrow[i] += aij;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << sumrow[i];
        if (i < n)
            cout << " ";
    }
    cout << '\n';
    for (int j=1; j<=m; j++) {
        cout << sumcol[j];
        if (j < m)
            cout << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Solve();
    return 0;
}
