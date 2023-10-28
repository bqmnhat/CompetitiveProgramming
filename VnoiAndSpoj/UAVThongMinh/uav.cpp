#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
typedef long long ll;
int n, L;
ll x[MaxN+5], dp[MaxN+5];

void ReadData() {
    x[1] = 1000;
    x[n] = x[1] + 1;
    for (int i=2; i<=n-1; i++)
        cin >> x[i];
}

int SolutionFirstProb() {
    int i = 1, cnt = 1;
    while (i < n) {
        int NxtLim = min(n, i + L), NxtI;
        for (NxtI = NxtLim; NxtI > i; NxtI--)
            if (x[NxtI] & 1)
                break;
        cnt++;;
        i = NxtI;
    }
    return cnt;
}

ll SolutionSecondProb() {
    for (int i=1; i<=n; i++)
        dp[i] = -1e18;
    dp[n] = x[n];
    ll MaxDpId = n;
    for (int i=n-1; i>=1; i--) {
        if (x[i]&1)
            continue;
        ll tmp = -1e18;
        if (((i+L < n) && (!(x[i + L]&1))) || (i + L == n))
            tmp = dp[i+L] + x[i];
        dp[i] = max(dp[i], max(dp[MaxDpId] - x[i], tmp));
        if (dp[i] > dp[MaxDpId])
            MaxDpId = i;
    }
    return dp[1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("uav.INP", "r", stdin);
    freopen("uav.OUT", "w", stdout);
    cin >> L >> n;
    ReadData();
    cout << SolutionFirstProb() << '\n' << SolutionSecondProb();
    return 0;
}
