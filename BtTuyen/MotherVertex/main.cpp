#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, e;

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
    int DFS();
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
