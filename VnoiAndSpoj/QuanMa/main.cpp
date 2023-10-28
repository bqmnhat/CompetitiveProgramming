#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxMask 8
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, z[MaxN+1], NumOfBits[MaxMask], dp[MaxN+1][MaxMask][MaxMask], prohMask[MaxN+1];
ll dpWays[MaxN+1][MaxMask][MaxMask];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> z[i];
}

void CntNumOfBits() {
    for (int i=0; i<MaxMask; i++) {
        int bit = i;
        while (bit > 0) {
            NumOfBits[i] += (bit&1);
            bit >>= 1;
        }
    }
}

int MakeMasks(int pos) {
    int mask = (1 << (pos-1));
    return mask;
}

void CalProhMasks() {
    for (int i=1; i<=n; i++) {
        if (z[i] == 0)
            continue;
        prohMask[i] = MakeMasks(z[i]);
    }
}

bool Check(int maskCur, int maskPrev, int dis) {
    if (dis == 1) {
        int tmpPrev1 = (maskPrev >> 2), tmpPrev2 = (maskPrev << 2);
        return (((tmpPrev1 & maskCur) == 0) && ((tmpPrev2 & maskCur) == 0));
    }
    if (dis == 2) {
        int tmpPrev1 = (maskPrev >> 1), tmpPrev2 = (maskPrev << 1);
        return (((tmpPrev1 & maskCur) == 0) && ((tmpPrev2 & maskCur) == 0));
    }
}

void Solve() {
    for (int mask1 = 0; mask1 < MaxMask; mask1++) {
        if ((mask1 & prohMask[1]) != 0)
            continue;
        dp[1][0][mask1] = NumOfBits[mask1];
        dpWays[1][0][mask1] = 1;
    }
    for (int i=2; i<=n; i++) {
        for (int mask2 = 0; mask2 < MaxMask; mask2++) {
            for (int mask1 = 0; mask1 < MaxMask; mask1++) {
                for (int mask = 0; mask < MaxMask; mask++) {
                    if ((!Check(mask, mask1, 1)) || (!Check(mask, mask2, 2)) || ((mask&prohMask[i]) != 0))
                        continue;
                    int NewVal = dp[i-1][mask2][mask1] + NumOfBits[mask];
                    if (NewVal > dp[i][mask1][mask]) {
                        dp[i][mask1][mask] = NewVal;
                        dpWays[i][mask1][mask] = dpWays[i-1][mask2][mask1];
                    }
                    else if (NewVal == dp[i][mask1][mask])
                        dpWays[i][mask1][mask] += dpWays[i-1][mask2][mask1];
                }
            }
        }
    }
    int ans = 0;
    ll Ways = 0;
    for (int mask2 = 0; mask2 < MaxMask; mask2++)
        for (int mask1 = 0; mask1 < MaxMask; mask1++)
            ans = max(ans, dp[n][mask2][mask1]);
    for (int mask2 = 0; mask2 < MaxMask; mask2++)
        for (int mask1 = 0; mask1 < MaxMask; mask1++)
            if (dp[n][mask2][mask1] == ans)
                Ways += dpWays[n][mask2][mask1];
    cout << ans << ' ' << Ways;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    CntNumOfBits();
    CalProhMasks();
    Solve();
    return 0;
}
