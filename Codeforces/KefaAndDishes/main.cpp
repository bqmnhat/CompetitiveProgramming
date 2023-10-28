#include <iostream>
#include <bits/stdc++.h>
#define MaxN 19
using namespace std;
typedef long long ll;
int n, m, k;
ll a[MaxN+1], Add[MaxN+1][MaxN+1], dp[(1 << MaxN)][MaxN], NumOfBits[(1 << MaxN)];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=1; i<=k; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--;
        v--;
        Add[u][v] = c;
    }
}

void CntBits() {
    for (int mask=0; mask<(1 << n); mask++) {
        int tmpmask = mask, cnt = 0;
        while (tmpmask > 0) {
            if (tmpmask&1)
                cnt++;
            tmpmask >>= 1;
        }
        NumOfBits[mask] = cnt;
    }
}

ll Solution() {
    ll ans = 0;
    for (int mask=0; mask<(1 << n); mask++) {
        for (int i=0; i<n; i++) {
            if ((mask != 0) && (!((1 << i) & mask)))
                continue;
            if (NumOfBits[mask] == m)
                ans = max(ans, dp[mask][i]);
            for (int j=0; j<n; j++) {
                if (mask == 0)
                    dp[mask|(1 << j)][j] = max(dp[mask|(1 << j)][j], dp[mask][i] + a[j]);
                else if (!(mask & (1 << j)))
                    dp[mask|(1 << j)][j] = max(dp[mask|(1 << j)][j], dp[mask][i] + Add[i][j] + a[j]);
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    CntBits();
    cout << Solution();
    return 0;
}
