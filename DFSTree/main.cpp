#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool visited[100001];
int n, m, discTime[100001], low[100001], tail[100001];
vector<int> g[100001];

void MakeDFSTree(int u, int& time, int parent) {
    time++;
    discTime[u] = low[u] = time;
    for (auto v: g[u]) {
        if (discTime[v] == -1) { //Ban dau Init discTime va low bang -1
            MakeDFSTree(v, time, u); //Build cay con goc v
            low[u] = min(low[u], low[v]); //Cap nhat low de lien ket voi cay con goc v
        }
        else if (v != parent)
            low[u] = min(low[u], discTime[v]); //Cap nhat low va di nguoc lai theo backedge
    }
    tail[u] = time;
}

int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
