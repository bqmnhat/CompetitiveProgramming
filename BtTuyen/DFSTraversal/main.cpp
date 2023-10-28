#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,e;
bool visited[1000001];
stack<int> stk;

class Graph {
    list<int> * adjlist;
    int n;
public:
    Graph(int v) {
        adjlist = new list<int> [v];
        n = v;
    }
    void addedge(int u, int v, bool bi) {
        adjlist[u].push_back(v);
        if (bi)
            adjlist[v].push_back(u);
    }
    void DFS(int start);
};

void Graph::DFS(int start) {
    stk.push(start);
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if (!visited[u]) {
            cout << u << " ";
            visited[u] = true;
        }
        for (auto i = adjlist[u].begin(); i!=adjlist[u].end(); i++) {
            if (!visited[*i])
                stk.push(*i);
        }
    }
}

void Solve() {
    Graph g(n);
    for (int i=1; i<=e; i++) {
        int u,v;
        cin >> u >> v;
        g.addedge(u,v,false);
    }
    g.DFS(1);
}

int main()
{
    cin >> n >> e;
    Solve();
    return 0;
}
