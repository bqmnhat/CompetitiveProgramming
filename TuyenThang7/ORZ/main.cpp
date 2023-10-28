#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
struct To {
    int y, u, v;
};
int n, m, k, t[6];
bool IsStudent[MaxN+1], vis[MaxN+1], cal[MaxN+1];
vector<To> g[MaxN+1], NewG[MaxN+1];
ll ans = 1e18;

void ReadData() {
    int x, y;
    ll u, v;
    for (int i=1; i<=m; i++) {
        cin >> x >> y >> u >> v;
        g[x].push_back({y, u, v});
        g[y].push_back({x, u, v});
    }
    for (int i=1; i<=k; i++) {
        cin >> t[i];
        IsStudent[t[i]] = true;
    }
    IsStudent[1] = IsStudent[n] = true;
}

void DFSMakeNewGraph(const int& x,const ll& SumU,const ll& SumV, int PrevMarked) {
    if (IsStudent[x]) {
        if (PrevMarked != -1) {
            NewG[PrevMarked].push_back({x, SumU, SumV});
            NewG[x].push_back({PrevMarked, SumU, SumV});
            return;
        }
        PrevMarked = x;
    }
    for (auto ty: g[x])
        if ((!vis[ty.y]) && (!cal[ty.y]))
            DFSMakeNewGraph(ty.y, SumU + 1LL*ty.u, SumV + 1LL*ty.v, PrevMarked);
}

void InitVis() {
    for (int i=1; i<=n; i++)
        vis[i] = false;
}

void FindHamiltonPath(const int& x,const int& cnt,const ll& cost) {
    if (cost > ans)
        return;
    if ((cnt == k+3) && (x == n)) {
        ans = min(ans, cost);
        return;
    }
    for (auto ty: NewG[x]) {
        if (!vis[ty.y]) {
            vis[ty.y] = true;
            FindHamiltonPath(ty.y, cnt+1, cost + 1LL*ty.u + 1LL*ty.v*1LL*cnt);
            vis[ty.y] = false;
        }
    }
}

ll Solution() {
    cal[1] = true;
    vis[1] = true;
    DFSMakeNewGraph(1, 0, 0, -1);
    cal[n] = true;
    vis[1] = false;
    vis[n] = true;
    DFSMakeNewGraph(n, 0, 0, -1);
    for (int i=1; i<=k; i++) {
        if (!cal[t[i]]) {
            InitVis();
            cal[t[i]] = true;
            vis[t[i]] = true;
            DFSMakeNewGraph(t[i], 0, 0, -1);
        }
    }
    InitVis();
    vis[1] = true;
    FindHamiltonPath(1, 2, 0);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ORZ.INP", "r", stdin);
    freopen("ORZ.OUT", "w", stdout);
    cin >> n >> m >> k;
    ReadData();
    cout << Solution();
    return 0;
}
