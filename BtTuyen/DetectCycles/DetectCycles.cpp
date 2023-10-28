#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, e;
bool visited[1000001];

class Graph {
public:
    list<int> *adjlist;
    int n;
    Graph(int v) {
        adjlist = new list<int> [v+1];
        n = v;
    }
    void addedge(int u, int v, bool bi) {
        adjlist[u].push_back(v);
        if (bi)
            adjlist[v].push_back(u);
    }
    bool IsCycle(int u, int ParOfu, bool visited[1000001]);
    bool Solution();
};

bool Graph::IsCycle(int u, int ParOfu, bool visited[1000001]) {
    visited[u] = true;
    list<int>:: iterator i;
    for (i = adjlist[u].begin(); i != adjlist[u].end(); i++) {
        if (!visited[*i]) {
            if (IsCycle(*i, u, visited))
                return true;
        }
        else if (*i != ParOfu)
            return true;
    }
    return false;
}

bool Graph::Solution() {
    for (int i=1; i<=1000000; i++)
        visited[i] = false;
    for (int v = 0; v < n; v++) {
        if (!visited[v])
            if (IsCycle(v,-1,visited))
                return true;
    }
    return false;
}

int main()
{
    cin >> n >> e;
    Graph g(n);
    for (int i = 1; i<=e; i++) {
        int u,v;
        cin >> u >> v;
        g.addedge(u,v,true);
    }
    if (g.Solution())
        cout << "Graph contains cycle" << '\n';
    else
        cout << "Graph does not contain cycle" << '\n';
    return 0;
}
