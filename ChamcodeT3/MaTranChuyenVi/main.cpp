#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[1001][1001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
}

void Solve() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cout << a[j][i];
            if (j < n)
                cout << " ";
        }
        if (i < m)
            cout << '\n';
    }
}

int main()
{
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
