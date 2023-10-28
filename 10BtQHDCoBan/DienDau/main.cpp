#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, S, a[2001], Base = 200000;
bool dp[2001][400001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    dp[1][a[1]] = true;
    for (int i=1; i<=n; i++)
        for (int j = 0; j<=S; j++)
            dp[i][j+Base] = (dp[i][j] | dp[i-1][j+a[i]+Base] | dp[i-1][j-a[i]+Base]);
    if (dp[n][S+Base])
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("23.INP", "r", stdin);
    freopen("23.OUT", "w", stdout);
    cin >> n >> S;
    ReadData();
    Solve();
    return 0;
}
