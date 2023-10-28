#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1001][1001], n,k, cd[1001][1001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

void CD() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cd[i][j] = cd[i-1][j] + cd[i][j-1] - cd[i-1][j-1] + a[i][j];
        }
    }
}

void Solve() {
    int ans = 0;
    for (int i=k; i<=n; i++) {
        for (int j=k; j<=n; j++) {
            int tmp = cd[i][j] - cd[i-k][j] - cd[i][j-k] + cd[i-k][j-k];
            if (tmp > ans)
                ans = tmp;
        }
    }
    cout << ans;
}

int main()
{
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    CD();
    Solve();
    return 0;
}
