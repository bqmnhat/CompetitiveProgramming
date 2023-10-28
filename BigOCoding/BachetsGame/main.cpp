#include <iostream>
#include <bits/stdc++.h>
#define MaxM 10
#define MaxN 1000000
using namespace std;
int m, s[MaxM+1], n;
bool dp[MaxN+1];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> s[i];
}

void SolveTestCase() {
    memset(dp, false, sizeof(dp));
    for (int i=1; i<=m; i++)
        dp[s[i]] = true;
    for (int i=2; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            if ((i - s[j] >= 0) && (!dp[i-s[j]])) {
                dp[i] = true;
                break;
            }
        }
    }
    if (dp[n])
        cout << "Stan wins";
    else
        cout << "Ollie wins";
    cout << '\n';
}

void Solve() {
    while (cin >> n >> m) {
        ReadData();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
