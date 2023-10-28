#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxMask 16
using namespace std;
typedef long long ll;
int n;
ll a[5][MaxN+1], dp[MaxN+1][MaxMask+1], SumMasks[MaxN+1][MaxMask+1], MaxAi = -1e18;
bool AllNeg = true;

void ReadData() {
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
            MaxAi = max(MaxAi, a[i][j]);
            if (a[i][j] >= 0)
                AllNeg = false;
        }
    }
}

void MakeSumMasks() {
    for (int j=1; j<=n; j++) {
        for (int mask = 0; mask <= 15; mask++) {
            int tmpmask = mask, cnt = 0, prefbit = 0;
            while (tmpmask > 0) {
                cnt++;
                if (((tmpmask&1) == 1) && (prefbit == 1)) {
                    SumMasks[j][mask] = 0;
                    break;
                }
                if ((tmpmask & 1))
                    SumMasks[j][mask] += a[cnt][j];
                prefbit = (tmpmask&1);
                tmpmask >>= 1;
            }
        }
    }
}

ll Solution() {
    if (AllNeg)
        return MaxAi;
    for (int j=1; j<=n; j++)
        for (int mask = 0; mask <= 15; mask++)
            dp[j][mask] = -1e18;
    for (int j=1; j<=n; j++) {
        for (int mask = 0; mask <= 15; mask++) {
            for (int tmpmask = 0; tmpmask <= 15; tmpmask++) {
                int ForCheck = (mask&tmpmask);
                if (ForCheck == 0)
                    dp[j][mask] = max(dp[j][mask], dp[j-1][tmpmask] + SumMasks[j][mask]);
            }
        }
    }
    ll ans = 0;
    for (int mask = 0; mask <= 15; mask++)
        ans = max(ans, dp[n][mask]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    MakeSumMasks();
    cout << Solution();
    return 0;
}
