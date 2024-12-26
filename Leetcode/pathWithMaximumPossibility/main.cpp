#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<int, double> pii;
typedef pair<double, int> pdi;
const ll INF = 1e9 + 7;

double dist[MaxN+5];
vector<pii> g[MaxN+5];

void InitDist(int n) {
    for (int i = 0; i <= n; i++)
        dist[i] = 0;
}

double Djikstra(int st, int ed) {
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    dist[st] = -1;
    pq.push(pii(-1, st));
    while (!pq.empty()) {
        pdi tmp = pq.top();
        pq.pop();
        double d = tmp.first;
        int u = tmp.second;
        if (dist[u] < d)
            continue;
        for (pii e: g[u]) {
            int v = e.first;
            double w = e.second;
            if (dist[u]*w < dist[v]) {
                dist[v] = dist[u]*w;
                pq.push(pdi(dist[v], v));
            }
        }
    }
    return dist[ed];
}

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0], v = edges[i][1];
        g[u].push_back(pii(v, succProb[i]));
        g[v].push_back(pii(u, succProb[i]));
    }

    InitDist(n);
    return (Djikstra(start_node, end_node) * (-1.0));
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    cout << maxProbability(3, edges, succProb, 0, 2);
    return 0;
}
