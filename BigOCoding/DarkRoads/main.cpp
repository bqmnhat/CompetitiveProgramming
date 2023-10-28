#include <iostream>
#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
typedef pair<int,int> pii;
int n, m, dist[200001], sum = 0;
vector<pii> graph[200001];
bool vis[200001];

void ReadGraph() {
    int u, v, w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(pii(v, w));
        graph[v].push_back(pii(u, w));
        sum += w;
    }
}

void Init() {
    for (int i=0; i<n; i++) {
        dist[i] = INF;
        graph[i].clear();
        vis[i] = false;
    }
}

int Solution() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, 0));
    dist[0] = 0;
    int u, v, w, cnt = 0;
    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();
        u = tmp.second;
        if (vis[u])
            continue;
        vis[u] = true;
        for (pii i: graph[u]) {
            v = i.first;
            w = i.second;
            if ((!vis[v]) && (dist[v] > w)) {
                dist[v] = w;
                pq.push(pii(w, v));
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (dist[i] != INF)
            cnt += dist[i];
    }
    return (sum - cnt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while ((n != 0) && (m != 0)) {
        sum = 0;
        Init();
        ReadGraph();
        cout << Solution() << '\n';
        cin >> n >> m;
    }
    return 0;
}
