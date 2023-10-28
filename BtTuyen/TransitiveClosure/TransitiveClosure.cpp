#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, e;
bool a[1001][10001];

class Graph {
public:
    list<int> *adjlist;
    int n;
    Graph(int v) {
        adjlist = new list<int> [v];
        n = v;
    }
    void addedge(int u, int v, bool bi) {
        adjlist[u].push_back(v);
        if (bi)
            adjlist[v].push_back(u);
    }
    void DFS(int u, int v);
    void Solve();
};

void Graph::DFS(int u, int v) {
    list<int>::iterator i;
    a[u][v] = true;
    for (i = adjlist[v].begin(); i != adjlist[v].end(); ++i)
        if (a[u][*i] == false)
            DFS(u, *i);
}

void Graph::Solve() {
    for (int i=0; i<n; i++) {
        DFS(i,i);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}

void TransitiveClosure() {
    Graph g(n);
    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        g.addedge(u,v,false);
    }
    g.Solve();
}

int main()
{
    cin >> n >> e;
    TransitiveClosure();
    return 0;
}
