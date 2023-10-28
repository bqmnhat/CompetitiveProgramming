#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int n, k, a[MaxN+1], dp[MaxN+1][MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    int Max = 1, MaxI = 1, MaxJ = a[1];
    dp[0][0] = dp[1][a[1]] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            if ((j - a[i] >= 0) && (dp[i-1][j-a[i]] != 0))
                dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]] + 1);
            if ((j + a[i] <= k) && (dp[i-1][j+a[i]] != 0))
                dp[i][j] = max(dp[i][j], dp[i-1][j+a[i]] + 1);
            if (dp[i][j] > Max) {
                Max = dp[i][j];
                MaxI = i;
                MaxJ = j;
            }
        }
    }
    cout << Max << '\n';
    vector<char> actions;
    while ((MaxI > 1) && (MaxJ >= 0)) {
        if ((dp[MaxI][MaxJ] == dp[MaxI-1][MaxJ+a[MaxI]] + 1) && (MaxJ + a[MaxI] <= k) && (dp[MaxI-1][MaxJ+a[MaxI]] != 0)) {
            actions.push_back('-');
            MaxJ += a[MaxI];
        }
        else if ((MaxJ - a[MaxI] >= 0) && (dp[MaxI-1][MaxJ-a[MaxI]] != 0)) {
            actions.push_back('+');
            MaxJ -= a[MaxI];
        }
        MaxI--;
    }
    actions.push_back('+');
    reverse(actions.begin(), actions.end());
    for (auto x: actions)
        cout << x;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
