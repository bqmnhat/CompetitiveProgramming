#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u,v,w;
};
int n,m,s,t;
vector<Edge> edges;
struct DSU {
    public:
        int parent[1001];
        void MakeSet(int v) {
            parent[v] = v;
        }
        int FindSet(int v) {
            if (parent[v] == 0)
                return -1;
            if (parent[v] == v)
                return v;
            return (parent[v] = FindSet(parent[v]));
        }
        void UnionSet(int u, int v) {
            u = FindSet(u);
            v = FindSet(v);
            if (u != v)
                parent[v] = u;
        }
};

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
}

bool Check(int mid) {
    DSU dsu;
    for (int i=1; i<=n; i++)
        dsu.MakeSet(i);
    for (auto i: edges) {
        if (i.w >= mid)
            dsu.UnionSet(i.u, i.v);
    }
    int SSet = dsu.FindSet(s), TSet = dsu.FindSet(t);
    if (SSet == TSet)
        return true;
    else
        return false;
}

int Solution() {
    int lo = 0, hi = 100001, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (Check(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    ReadData();
    cout << Solution();
    return 0;
}
