#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, c[2001], dp[2001], t;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
}

void Clear(int n, int m) {
    for (int i=1; i<=n; i++)
        c[i] = 0;
    for (int i=1; i<=m; i++) {
        dp[i] = 0;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        int ans = 0;
        cin >> n >> m;
        ReadData();
        sort(c+1, c+1+n);
        dp[0] = 0;
        for (int p=1; p<=m; p++) {
            int j = 1;
            while ((c[j] <= p) && (j <= n)) {
                if (dp[p - c[j]] + c[j] > dp[p]) {
                    dp[p] = dp[p - c[j]] + c[j];
                }
                j++;
            }
        }
        cout << dp[m] << endl;
        Clear(n,m);
    }
}

int main()
{
    freopen("EXPENSE.INP", "r", stdin);
    freopen("EXPENSE.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
