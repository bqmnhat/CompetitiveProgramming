#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, dist[100001], INF = 1e9;
vector<pair<int,int>> g[100001];
set<pair<int,int>> setds;

void Init() {
    for (int i=0; i<=n; i++)
        dist[i] = INF;
}

void Dijkstra(int s/*, int t */) {
    setds.insert(make_pair(0, s));
    dist[s] = 0;
    while (!setds.empty()) {
        pair<int, int> top = *(setds.begin());
        setds.erase(setds.begin());
        int u = top.second;
        for (auto e: g[u]) {
            int v = e.first, wei = e.second;
            if (dist[v] > dist[u] + wei) {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v],v)));
                dist[v] = dist[u] + wei;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    for (int i=0; i<n; i++)
        if (dist[i] != INF)
            cout << i << " " << dist[i] << '\n';
    //cout << dist[t];
    //Bo dau comment cho truong hop chi in ra duong di ngan nhat tu 1 diem
}

void addEdge(int u, int v, int wei) {
    g[u].push_back(make_pair(v, wei));
    g[v].push_back(make_pair(u, wei));
}

int main()
{
    n = 30;
    addEdge(0,1,4);
    addEdge(0,7,8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);
    Init();
    Dijkstra(0);
    return 0;
}
