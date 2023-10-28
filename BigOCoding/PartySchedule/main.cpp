#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Bud, n, c[101], fun[101], dp[101][501];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> c[i] >> fun[i];
}

void SolveTestCases() {
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=Bud; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - c[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-c[i]] + fun[i]);
        }
    }
    int SumEntrance = Bud, i = n, j = Bud;
    while (dp[n][SumEntrance] == dp[n][Bud])
        SumEntrance--;
    SumEntrance++;
    cout << SumEntrance << ' ' << dp[n][Bud] << '\n';
}

void Solve() {
    cin >> Bud >> n;
    while ((Bud != 0) || (n != 0)) {
        ReadData();
        SolveTestCases();
        cin >> Bud >> n;
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
