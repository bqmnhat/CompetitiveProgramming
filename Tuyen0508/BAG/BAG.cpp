#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxV 100000
using namespace std;
typedef long long ll;
int n;
ll v0, c[MaxN+1], v[MaxN+1], p[MaxN+1], dp[MaxN+1][MaxV+1], MaxP = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> v[i] >> c[i] >> p[i];
        MaxP = max(MaxP, p[i]);
    }
}

ll Solution2Sub() {
    ll ans = 0;
    for (int i=1; i<(1 << n); i++) {
        int tmpbitset = i, cnt = 0;
        ll SumV = 0, SumC = 0, MinP = 1e9 + 7;
        while (tmpbitset > 0) {
            cnt++;
            int tmpbit = (tmpbitset&1);
            if (tmpbit == 1) {
                SumV += v[cnt];
                SumC += c[cnt];
                MinP = min(MinP, p[cnt]);
            }
            tmpbitset >>= 1;
        }
        if (MinP >= SumV - v0)
            ans = max(ans, SumC);
    }
    return ans;
}

ll SolutionSub3() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=v0; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - v[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]] + c[i]);
        }
    }
    return dp[n][v0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BAG.INP", "r", stdin);
    freopen("BAG.OUT", "w", stdout);
    cin >> n >> v0;
    ReadData();
    if (n <= 20)
        cout << Solution2Sub();
    else if (MaxP == 0)
        cout << SolutionSub3();
    return 0;
}
