#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, t;
vector<int> graph[30001];
bool visited[30001];

void ReadGraph() {
    for (int i=1; i<=n-1; i++) {
        int ai;
        cin >> ai;
        graph[i].push_back(i + ai);
    }
}

bool DFS(int u) {
    visited[u] = true;
    if (u == t)
        return true;
    bool Reach = false;
    for (auto v: graph[u]) {
        if (!visited[v]) {
            Reach = Reach || DFS(v);
            if (Reach)
                return true;
        }
    }
    return false;
}

void Solve() {
    if (DFS(1))
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    ReadGraph();
    Solve();
    return 0;
}
