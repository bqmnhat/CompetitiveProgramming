#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, c[51];
ll dp[251];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> c[i];
}

ll Solution() {
    dp[0] = 1;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (j - c[i] >= 0)
                dp[j] += dp[j-c[i]];
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
