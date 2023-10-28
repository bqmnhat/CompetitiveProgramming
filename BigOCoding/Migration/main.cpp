#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
#define MaxPos 1000001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, k, K[MaxN+5][MaxN+5];
pii a[MaxN+1];
ll dp[MaxN+5][MaxN+5], cost[MaxN+5][MaxN+5], SumWX[MaxPos+1], SumW[MaxPos+1];// dp[i][j] is minimum value when we already placed i starships and the last starships is at position j
const ll INF = 1e18 + 7;

inline void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].first >> a[i].second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    sort(a+1, a+1+n);
    auto GoLeft = [&] (int l, int r) {
        return SumWX[r] - SumWX[l] - (SumW[r] - SumW[l])*1LL*l;
    };
    auto GoRight = [&] (int l, int r) {
        return (SumW[r] - SumW[l])*1LL*r - (SumWX[r] - SumWX[l]);
    };
    for (int i=1; i<=n; i++) {
        SumW[a[i].first] += a[i].second;
        SumWX[a[i].first] += (a[i].first*a[i].second);
    }
    for (int i=1; i<=MaxPos; i++) {
        SumW[i] += SumW[i-1];
        SumWX[i] += SumWX[i-1];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int mid = ((a[i].first + a[j].first)>>1);
            cost[i][j] = GoLeft(a[i].first, mid) + GoRight(mid, a[j].first);
        }
    }
    for (int j=1; j<=n; j++) {
        dp[1][j] = GoRight(0, a[j].first);
        K[1][j] = 1;
    }

    for (int i=2; i<=k; i++) {
        K[i][n+1] = n;
        for (int j=n; j>=i; j--) {
            dp[i][j] = INF;
            for (int t=K[i-1][j]; t<=K[i][j+1]; t++) {
                ll val = dp[i-1][t] + cost[t][j];
                if (val < dp[i][j]) {
                    dp[i][j] = val;
                    K[i][j] = t;
                }
            }
        }
    }
    ll ans = INF;
    for (int i=1; i<=n; i++) {
        ll tmp = dp[k][i] + GoLeft(a[i].first, 1000001);
        ans = min(ans, tmp);
    }
    cout << ans;
    return 0;
}
