#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 100000
#define MaxM 200000
#define Inf 1000000007
typedef pair<int, long long> iPair;
int n,m, routes[MaxN+1];
list<iPair> adj[MaxN+1];
map <int,long long> ans;

void LoadGraph() {
    int u,v,w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
}

void Solve() {
    priority_queue <iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> d(n+1,Inf);
    pq.push(make_pair(0,1));
    d[1] = 0;
    routes[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        list<iPair>::iterator i;
        for (i = adj[u].begin(); i!= adj[u].end(); i++) {
            int v = (*i).first, w = (*i).second;
            if (d[v] >= d[u] + w) {
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    pq.push(make_pair(d[v],v));
                }
                if (v == n)
                    ans[d[v]] = ((ans[d[v]]%Inf) + 1)%Inf;
            }
        }
    }
    cout << d[n] << " " << ans[d[n]];
}

int main()
{
    cin >> n >> m;
    LoadGraph();
    Solve();
    return 0;
}
