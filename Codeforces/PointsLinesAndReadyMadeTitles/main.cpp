#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll Mod = 1e9 + 7;
int n;
bool vis[MaxN+5];
struct Point {
    int id;
    ll x, y;
} a[MaxN+5];
vector<int> g[MaxN+5];
unordered_set<ll> cntX, cntY;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
}

bool CmpId(Point a, Point b) {
    return (a.id < b.id);
}

bool CmpX(Point a, Point b) {
    if (a.x == b.x)
        return (a.y < b.y);
    return (a.x < b.x);
}

bool CmpY(Point a, Point b) {
    if (a.y == b.y)
        return (a.x < b.x);
    return (a.y < b.y);
}

ll FastPow(ll base, ll e, const ll Mod) {
    ll ans = 1;
    while (e) {
        if (e&1LL)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

void MakeGraph() {
    sort(a+1, a+1+n, CmpX);
    for (int i=2; i<=n; i++) {
        if (a[i].x == a[i-1].x) {
            g[a[i].id].push_back(a[i-1].id);
            g[a[i-1].id].push_back(a[i].id);
        }
    }
    sort(a+1, a+1+n, CmpY);
    for (int i=2; i<=n; i++) {
        if (a[i].y == a[i-1].y) {
            g[a[i].id].push_back(a[i-1].id);
            g[a[i-1].id].push_back(a[i].id);
        }
    }
    sort(a+1, a+1+n, CmpId);
}

void DFS(int u, int & SumDeg, int& CompSize) {
    if (cntX.find(a[u].x) == cntX.end())
        cntX.insert(a[u].x);
    if (cntY.find(a[u].y) == cntY.end())
        cntY.insert(a[u].y);
    CompSize++;
    SumDeg += g[u].size();
    for (int v: g[u]) {
        if (vis[v] == 0) {
            vis[v] = true;
            DFS(v, SumDeg, CompSize);
        }
    }
}

ll Solution() {
    memset(vis, false, sizeof(vis));
    ll ans = 1;
    for (int i=1; i<=n; i++) {
        if (vis[i] == 0) {
            int SumDeg = 0, CompSize = 0;
            cntX.clear();
            cntY.clear();
            vis[i] = true;
            DFS(i, SumDeg, CompSize);
            ll tmp = FastPow(2, cntX.size() + cntY.size(), Mod);
            if (2*CompSize - SumDeg == 2)
                tmp = (tmp - 1LL + Mod)%Mod;
            ans = (ans*tmp)%Mod;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    MakeGraph();
    cout << Solution();
    return 0;
}
