#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int dp[7001][7001], l;
//int t;

void Init() {
    for (int i=0; i<=l; i++)
        for (int j=0; j<=l; j++)
            dp[i][j] = -1;
}

void MinChanges(int i, int j) {
    if (dp[i][j] != -1)
        return;
    if (i > j) {
        dp[i][j] = 0;
        return;
    }
    if (i == j) {
        dp[i][j] = 0;
        return;
    }
    if (s[i] == s[j]) {
        MinChanges(i+1, j-1);
        dp[i][j] = dp[i+1][j-1];
    }
    else {
        MinChanges(i, j-1);
        MinChanges(i+1, j);
        dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;
    }
}

/*void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        l = s.length();
        Init();
        MinChanges(0, l-1);
        cout << dp[0][l-1] << '\n';
    }
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("31.INP", "r", stdin);
    freopen("31.OUT", "w", stdout);
    //cin >> t;
    cin >> s;
    l = s.length();
    Init();
    MinChanges(0, l-1);
    cout << dp[0][l-1];
    //Solve();
    return 0;
}
