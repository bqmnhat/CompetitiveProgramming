#include <iostream>
#include <bits/stdc++.h>
#define MaxMask 2000000
#define MaxN 20
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+1][MaxN+1], dp[MaxN+1][MaxMask], NumOfBits[MaxMask];

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
}

int CntBits(int val) {
    int ans = 0;
    while (val > 0) {
        ans += (val&1);
        val >>= 1;
    }
    return ans;
}

void CntNumOfBits() {
    for (int mask = 0; mask < (1 << n); mask++)
        NumOfBits[mask] = CntBits(mask);
}

ll Solution() {
    for (int i=1; i<=n; i++) {
        for (int mask=0; mask<(1 << n); mask++) {
            if (NumOfBits[mask] != i)
                continue;
            for (int j=1; j<=n; j++) {
                int tmp = mask^(1 << (j-1)), tmp2 = mask&(1 << (j-1));
                if (tmp2 != 0)
                    dp[i][mask] = max(dp[i][mask], dp[i-1][tmp] + a[i][j]);
            }
        }
    }
    return dp[n][(1 << n) - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    CntNumOfBits();
    ReadData();
    cout << Solution();
    return 0;
}
