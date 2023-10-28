#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[1001][1001],x[1001],y[1001];

int MaxL() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            a[i][j] = max(a[i-1][j],a[i][j-1]);
            if (x[i] == y[j]) {
                a[i][j] += 1;
            }
        }
    }
    return a[n][m];
}

int ReadINP() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i];
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        cin >> y[i];
    }
}

int main()
{
    freopen("CHUOIDT.INP", "r", stdin);
    freopen("CHUOIDT.OUT", "w", stdout);
    ReadINP();
    cout << MaxL();
    return 0;
}
