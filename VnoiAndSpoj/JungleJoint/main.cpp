#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
int t, n, m;
ll a[MaxN+1][MaxN+1];
bool row[MaxN+1], col[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
}

void CheckRowsAndCols() {
    for (int i=1; i<=n; i++) {
        row[i] = true;
        for (int j=1; j<=m; j++) {
            if (i == 1)
                col[j] = true;
            if ((j > 1) && (a[i][j] != a[i][j-1]))
                row[i] = false;
            if ((i > 1) && (a[i][j] != a[i-1][j]))
                col[j] = false;
        }
    }
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if ((row[i]) && (col[j]))
                ans++;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        ReadData();
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        CheckRowsAndCols();
        cout << Solution() << '\n';
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
