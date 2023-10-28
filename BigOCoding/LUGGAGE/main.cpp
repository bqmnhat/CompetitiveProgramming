#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m, n, w[21], sum;
bool dp[21][201];
string inp;

void ReadData() {
    sum = 0, n = 1;
    stringstream ss(inp);
    while (ss >> w[n]) {
        sum += w[n];
        n++;
    }
    n--;
}

void SolveTestCase() {
    memset(dp, false, sizeof(dp));
    if (sum % 2 != 0) {
        cout << "NO";
        return;
    }
    for (int i=0; i<=n; i++)
        dp[i][0] = true;
    for (int i=1; i <= n; i++) {
        for (int j=1; 2*j<=sum; j++) {
            dp[i][j] = (dp[i][j] || dp[i-1][j]);
            if (j - w[i] >= 0)
                dp[i][j] = (dp[i][j] || dp[i-1][j-w[i]]);
        }
    }
    int t = sum/2;
    if (dp[n][t])
        cout << "YES";
    else
        cout << "NO";
}

void Solve() {
    cin.ignore();
    for (int i=1; i<=m; i++) {
        getline(cin, inp);
        ReadData();
        SolveTestCase();
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    Solve();
    return 0;
}
