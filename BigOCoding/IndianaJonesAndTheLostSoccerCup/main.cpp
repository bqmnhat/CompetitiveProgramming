#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int indeg[10001], c, n, h;
vector<int> graph[10001], TopoOrder;
bool Missing = false;

void Init() {
    for (int i=0; i<=n; i++) {
        indeg[i] = 0;
        graph[i].clear();
    }
    TopoOrder.clear();
}

void ReadGraph() {
    for (int i=1; i<=h; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }
}

bool Kahn() {
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        if ((int)q.size() > 1)
            Missing = true;
        int u = q.front();
        q.pop();
        TopoOrder.push_back(u);
        for (auto v: graph[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    return TopoOrder.size() == n;
}

void Solve() {
    for (int i=1; i<=c; i++) {
        cin >> n >> h;
        Init();
        ReadGraph();
        Missing = false;
        if (!Kahn())
            cout << "recheck hints";
        else if (Missing)
            cout << "missing hints";
        else {
            for (auto x : TopoOrder)
                cout << x << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c;
    Solve();
    return 0;
}
