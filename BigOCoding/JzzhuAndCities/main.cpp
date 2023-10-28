#include <iostream>
#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n, m, k;
bool vis[100001];
vector<pll> g[100001];
priority_queue<pll> setds;

void ReadData() {
    for (int i=1; i<=m; i++) {
        ll u,v,x;
        cin >> u >> v >> x;
        g[u].push_back(pll(v,x));
        g[v].push_back(pll(u,x));
    }
    for (int i=1; i<=k; i++) {
        ll s, y;
        cin >> s >> y;
        setds.push(pll(-y, -s));
    }
}

int Solution(int src)  {
    setds.push(pll(0, src));
    int ans = 0;
    while (!setds.empty()) {
        pll tmpu = setds.top();
        setds.pop();
        int u = tmpu.second;
        ll distU = tmpu.first;
        if ((u < 0) && (vis[u = -u]))
            ans++;
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto tmpv : g[u]) {
            int v = tmpv.first;
            ll w = tmpv.second;
            if (!vis[v])
                setds.push(pll(distU - w, v));
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
    cout << Solution(1);
    return 0;
}
