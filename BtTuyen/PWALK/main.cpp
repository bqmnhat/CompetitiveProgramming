#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,q;
bool visited[1001];
long long dist[1001][1001];


class Graph {
public:
    list<pair<int,int>> *adjlist;
    int n;
    Graph(int v) {
        adjlist = new list<pair<int,int>> [v+1];
        n = v;
    }
    void addedge(int u, int v, int w, bool bi) {
        adjlist[u].push_back(make_pair(v,w));
        if (bi)
            adjlist[v].push_back(make_pair(u,w));
    }
    void BFS(int st);
    void Solve();
};

void Graph::BFS(int st) {
    for (int i=1; i<=1000; i++) {
        visited[i] = false;
    }
    queue <int> qu;
    qu.push(st);
    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();
        for (list<pair<int,int>>::iterator i = adjlist[v].begin(); i != adjlist[v].end(); i++) {
            if(!visited[(*i).first]) {
                dist[st][(*i).first] = dist[st][v] + (*i).second;
                visited[(*i).first] = true;
                qu.push((*i).first);
            }
        }
        cout << '\n';
    }
}

void Graph::Solve() {
    for (int i=1; i<=n; i++) {
        BFS(i);
    }
    int cmd1, cmd2;
    for (int i=1; i<=q; i++) {
        cin >> cmd1 >> cmd2;
        cout << dist[cmd1][cmd2] << '\n';
    }
}

int main()
{
    cin >> n >> q;
    Graph g(n);
    for (int i=1; i<=n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addedge(u,v,w,true);
    }
    g.Solve();
    return 0;
}
