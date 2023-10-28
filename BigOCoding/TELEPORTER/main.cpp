#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 0;
vector <int> graph[100001];

void ReadGraph() {
    for (int i = 1; i<=n ; i++) {
        int x;
        cin >> x;
        if (i == 1)
            ans += (x != 1);
        else
            graph[x].push_back(i);
    }
}

void BFS() {
    queue<int> q;
    vector<int> dist(n+1, -1);
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : graph[u]) {
            if (dist[v] != -1)
                continue;
            dist[v] = dist[u] + 1;
            q.push(v);
            if (dist[v] > k) {
                dist[v] = 1;
                ans++;
            }
        }
    }
}

void Solve() {
    BFS();
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadGraph();
    Solve();
    return 0;
}
