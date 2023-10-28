#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, indeg[100001];
vector<int> graph[200001], res;

void ReadGraph() {
    int a, b;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }
}

bool Kahn() {
    queue<int> q;
    for (int i=1; i<=n; i++)
        if (indeg[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int v : graph[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    return (res.size() == n);
}

void Solve() {
    if (Kahn()) {
        for (auto i: res)
            cout << i << ' ';
    }
    else
        cout << "IMPOSSIBLE";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    Solve();
    return 0;
}
