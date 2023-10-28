#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[10001][10001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
}

void Solve() {
    ll bij;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> bij;
            cout << ll(a[i][j] + bij);
            if (j < m)
                cout << " ";
        }
        if (i < n)
            cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
