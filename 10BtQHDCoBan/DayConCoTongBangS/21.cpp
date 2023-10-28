#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, S, a[2001], trace[2001][40001];
bool dp[2001][40001], ans[2001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    for (int i=0; i<=n; i++)
        dp[i][0] = true;
    for (int i=1; i<=n; i++) {
        for (int j = S; j>=a[i]; j--) {
            if (dp[i-1][j-a[i]]) {
                dp[i][j] = true;
                trace[i][j] = j-a[i];
            }
            else if (dp[i-1][j]) {
                dp[i][j] = true;
                trace[i][j] = j;
            }
        }
    }
    if (dp[n][S])
        //cout << "1\n";
        cout << "YES";
    else {
        //cout << "0";
        cout << "NO";
        //return;
    }
    /*int i = n, j = S;
    while (i >= 1) {
        if (trace[i][j] == j-a[i])
            ans[i] = true;
        j = trace[i][j];
        i--;
    }
    for (int i=1; i<=n; i++)
        cout << (int)ans[i] << ' ';*/
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("21.INP", "r", stdin);
    freopen("21.OUT", "w", stdout);
    cin >> n >> S;
    ReadData();
    Solve();
    return 0;
}
