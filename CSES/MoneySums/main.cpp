#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxVal 100000
using namespace std;
int n, x[MaxN+5];
bool dp[MaxN+5][MaxVal+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}

void Solve() {
    for (int i=0; i<=n; i++)
        dp[i][0] = true;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=MaxVal; j++) {
            if (j - x[i] >= 0)
                dp[i][j] |= dp[i-1][j-x[i]];
            dp[i][j] |= dp[i-1][j];
        }
    }
    vector<int> ans;
    for (int i=1; i<=MaxVal; i++)
        if (dp[n][i])
            ans.push_back(i);
    cout << ans.size() << '\n';
    for (int val: ans)
        cout << val << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
