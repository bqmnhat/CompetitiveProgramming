#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
int n;
ll dpSum[MaxN+5], dp[MaxN+5][MaxN+5], ans = 0;
vector<int> g[MaxN+5];

void ReadData() {
    for (int i=2; i<=n; i++) {
        int u;
        cin >> u;
        g[i].push_back(u);
        g[u].push_back(i);
    }
}

void DFS(int u, int p) {
    dpSum[u] = 0;
    for (int v: g[u]) {
        if (v != p) {
            DFS(v, u);
            dpSum[u] += dpSum[v];
        }
    }
    ll CurSum = 0, UAns = 0;
    int cnt = 0;
    for (int v: g[u]) {
        if (v != p) {
            CurSum += dpSum[v];
            cnt++;
            for (ll Less = 0; Less <= dpSum[u]; Less++) {
                if (cnt == 1) {
                    dp[cnt][Less] = 0;
                    continue;
                }
                dp[cnt][Less] = 0;
                for (ll LessAtV = max(0LL, Less - (CurSum - dpSum[v])); LessAtV <= min(dpSum[v], Less); LessAtV++) {
                    ll OtherLess = Less - LessAtV;
                    ll OtherGreater = (CurSum - dpSum[v]) - OtherLess;
                    ll GreaterAtV = dpSum[v] - LessAtV;
                    dp[cnt][Less] = max(dp[cnt][Less], (dp[cnt-1][Less - LessAtV] + LessAtV*OtherGreater + GreaterAtV*OtherLess));
                }
            }
            for (ll Less = 0; Less <= dpSum[u]; Less++)
                UAns = max(UAns, dp[cnt][Less]);
        }
    }
    ans += UAns;
    dpSum[u]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    DFS(1, -1);
    cout << ans;
    return 0;
}
