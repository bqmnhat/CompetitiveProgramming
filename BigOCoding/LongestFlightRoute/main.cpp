#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, trace[100001], dist[100001], indeg[100001];
vector<int> graph[100001], TopoOrder;

void ReadGraph() {
    int a, b;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        trace[i] = -1;
}

void Kahn() {
    queue<int> q;
    for (int i=1; i<=n; i++)
        if (indeg[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        TopoOrder.push_back(u);
        for (auto v: graph[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    dist[1] = 1;
    for (int u: TopoOrder)
        if (dist[u] > 0)
            for (int v: graph[u])
                if (dist[v] < dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    trace[v] = u;
                }
}

void PrintPath() {
    int i = n, la = 0, a[100001];
    while (i != -1) {
        la++;
        a[la] = i;
        i = trace[i];
    }
    for (int i=la; i>=1; i--)
        cout << a[i] << ' ';
}

void Solve() {
    Init();
    Kahn();
    if (dist[n] == 0) {
        cout << "IMPOSSIBLE";
        return;
    }
    else {
        cout << dist[n] << '\n';
        PrintPath();
    }
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
