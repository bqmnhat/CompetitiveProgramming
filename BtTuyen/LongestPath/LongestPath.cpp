#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, e;
bool visited[1000001];

class Graph {
public:
    list<pair<int,int>> *adjlist;
    int n;
    Graph(int v) {
        adjlist = new list<pair<int,int>> [v+1];
        n = v;
    }
    void addedge(int u, int v, int w, bool bi) {
        pair<int,int> a (v,w);
        adjlist[u].push_back(a);
        if (bi) {
            pair<int,int> a (u,w);
            adjlist[v].push_back(a);
        }
    }
    void DFS(int str, int prev, int &maxlen);
    int Solution();
};

void Graph::DFS(int str, int prev, int &maxlen) {
    visited[str] = true;
    int current = 0;
    list<pair<int,int>>::iterator i;
    for (i = adjlist[str].begin(); i != adjlist[str].end(); i++) {
        if (!visited[(*i).first]) {
            current = prev + (*i).second;
            DFS((*i).first, current, maxlen);
        }
        if (current > maxlen)
            maxlen = current;
        current = 0;
    }
}

int Graph::Solution() {
    int ans = -1e9;
    for (int i=1; i<=n; i++) {
        for (int i=0; i<=1000001; i++)
            visited[i] = false;
        DFS(i,0,ans);
    }
    return ans;
}

int main()
{
    cin >> n >> e;
    Graph g(n);
    for (int i=1; i<=e; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        g.addedge(u,v,w,true);
    }
    cout << g.Solution();
    return 0;
}
