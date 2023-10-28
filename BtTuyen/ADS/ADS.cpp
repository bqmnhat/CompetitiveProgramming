#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
bool visited[2001];

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
    int BFS();
};

int Graph::BFS() {
    int ConCom = 0;
    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            ConCom++;
            queue<int> qu;
            qu.push(i);
            while(!qu.empty()) {
                int u = qu.front();
                qu.pop();
                list<int>::iterator it;
                for(it = adjlist[u].begin(); it != adjlist[u].end(); it++) {
                    if(!visited[*it]) {
                        visited[*it] = 1;
                        qu.push(*it);
                    }
                }
            }
        }
    }
    return m - n + ConCom;
}

int main()
{
    cin >> n >> m;
    Graph g(n);
    for (int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        g.addedge(u,v,true);
    }
    cout << g.BFS();
    return 0;
}
