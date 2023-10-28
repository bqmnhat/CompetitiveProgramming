#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int path[1000001], n, e, a, b, lp = 0;
bool visited[1000001];
stack <int> stk;

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
    void AllPaths(int st);
};

void PrintAns() {
    for (int i=1; i<=lp; i++)
        cout << path[i] << " ";
    cout << '\n';
}

void Graph::AllPaths(int st) {
    visited[st] = true;
    lp++;
    path[lp] = st;
    if (st == b) {
        PrintAns();
    }
    else {
        list<int>::iterator i;
        for (i = adjlist[st].begin(); i != adjlist[st].end(); i++) {
            if (!visited[*i])
                AllPaths(*i);
        }
    }
    visited[st] = false;
    lp--;
}

int main()
{
    cin >> n >> e >> a >> b;
    Graph g(5);
    for (int i=1; i<=e; i++) {
        int u,v;
        cin >> u >> v;
        g.addedge(u,v,false);
    }
    g.AllPaths(a);
    return 0;
}
