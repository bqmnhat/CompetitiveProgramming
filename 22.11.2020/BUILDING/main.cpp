#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int h[1001][1001], b[1001][1001], hmax = 0,m,n;

void ReadData() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> h[i][j];
        }
    }
}

void SeeSea(int i, int j) {
    if (h[i][j] >= hmax) {
        hmax = h[i][j];
        b[i][j] = true;
    }
}

int NotAvailable() {
    for (int i = 1; i<=m; i++) {
        hmax = 0;
        for (int j=1; j<=n; j++) {
            SeeSea(i,j);
        }
        hmax = 0;
        for (int j=n; j>=1; j--) {
            SeeSea(i,j);
        }
    }
    for (int j=1; j<=n; j++) {
        hmax = 0;
        for (int i=1; i<=m; i++) {
            SeeSea(i,j);
        }
        hmax = 0;
        for (int i=m; i>=1; i--) {
            SeeSea(i,j);
        }
    }
    int ans = 0;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (b[i][j] == false)
                ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("BUILDING.INP", "r", stdin);
    freopen("BUILDING.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    cout << NotAvailable();
    return 0;
}

