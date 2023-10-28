#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20
#define MaxMask 2000000
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 7;
int n;
ll dp[MaxMask+5], a[MaxN+5], Last[MaxMask+5], MaxWeight;

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
}

ll Solution() {
    dp[0] = 1;
    Last[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = Last[mask] = INF;
        for (int i=0; i<n; i++) {
            if (!(mask & (1 << i)))
                continue;
            int PrevMask = mask ^ (1 << i);
            if (Last[PrevMask] + a[i] <= MaxWeight) {
                if (dp[PrevMask] < dp[mask]) {
                    dp[mask] = dp[PrevMask];
                    Last[mask] = Last[PrevMask] + a[i];
                }
                if ((dp[PrevMask] == dp[mask]) && (Last[PrevMask] + a[i] < Last[mask]))
                    Last[mask] = Last[PrevMask] + a[i];
            }
            else {
                if (dp[PrevMask] + 1 < dp[mask]) {
                    dp[mask] = dp[PrevMask] + 1;
                    Last[mask] = a[i];
                }
                if ((dp[PrevMask] + 1 == dp[mask]) && (a[i] < Last[mask]))
                    Last[mask] = a[i];
            }
        }
    }
    return dp[(1 << n) - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> MaxWeight;
    ReadData();
    cout << Solution();
    return 0;
}
