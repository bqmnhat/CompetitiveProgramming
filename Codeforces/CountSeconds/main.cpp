#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
const ll Mod = 998244353;
int t, n, m, h[MaxN+5];
ll dp[MaxN+5], a[MaxN+5], sum[MaxN+5];
vector<int> g[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
}

void Init() {
    for (int i=1; i<=n; i++) {
        dp[i] = -1;
        sum[i] = 0;
        g[i].clear();
    }
}

bool ExistOne() {
    for (int i=1; i<=n; i++)
        if (a[i] > 0)
            return true;
    return false;
}

int Simulate(int times) {
    int cnt = 0, nxt[MaxN+5];
    while ((times > 0) && (ExistOne())) {
        memset(nxt, 0, sizeof(nxt));
        for (int u=1; u<=n; u++) {
            if (a[u] == 0)
                continue;
            a[u]--;
            for (int v: g[u])
                nxt[v]++;
        }
        for (int u=1; u<=n; u++)
            a[u] += nxt[u];
        cnt++;
        times--;
    }
    for (int u=1; u<=n; u++)
        sum[u] = a[u];
    return cnt;
}

void CalDp(int u) {
    if (dp[u] != -1)
        return;
    ll tmp = 0;
    bool Last = true;
    for (int v: g[u]) {
        //sum[v] = (sum[v] + sum[u])%Mod;
        Last = false;
        CalDp(v);
        tmp = (tmp + dp[v])%Mod;
    }
    if (Last)
        dp[u] = 1;
    else
        dp[u] = tmp;
}

ll Solution() {
    int SimulatedSteps = Simulate(n);
    if (!ExistOne())
        return SimulatedSteps;
    ll ans = n;
    for (int u = 1; u<=n; u++)
        CalDp(u);
    for (int u=1; u<=n; u++)
        ans = (ans + (a[u]*dp[u])%Mod)%Mod;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        Init();
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}

//998244353 0 0 0 998244353 0 0 0 0 0
