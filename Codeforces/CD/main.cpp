#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int N, n, t[21];
bool dp[21][MaxN+1];

void Init() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=N; j++)
            dp[i][j] = false;
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> t[i];
}

void SolveTestCases() {
    dp[0][0] = true;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=N; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - t[i] >= 0)
                dp[i][j] = (dp[i][j] || dp[i-1][j - t[i]]);
        }
    }
    int i = n, j, sum = 0;
    for (j=N; j>=1; j--)
        if (dp[n][j]) {
            sum = j;
            break;
        }
    vector<int> res;
    res.clear();
    while ((i > 0) && (j > 0)) {
        if (dp[i][j] == dp[i-1][j])
            i--;
        else {
            res.push_back(t[i]);
            j = j - t[i];
            i--;
        }
    }
    for (auto x: res)
        cout << x << ' ';
    cout << "sum:" << sum << '\n';
}

void Solve() {
    while (cin >> N >> n) {
        ReadData();
        Init();
        SolveTestCases();
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
