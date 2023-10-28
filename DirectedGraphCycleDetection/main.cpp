#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<int> g[1000001];
deque<int> dq;
stack<int> stk;
bool visited[1000001];

void ReadGraph() {
    int u, v;
    for (int i=1; i<=e; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

void PrintGraph() {
    for (auto i=dq.begin(); i != dq.end(); i++) {
        cout << (*i) << ' ';
        stk.push((*i));
    }
    cout << '\n';
}

void DetectGraph(int v) {
    if (visited[v] == true) {
        PrintGraph();
        return;
    }
    visited[v] = true;
    dq.push_back(v);
    for (auto i = g[v].begin(); i != g[v].end(); i++)
        DetectGraph((*i));
    visited[v] = false;
    dq.pop_back();
}

void FindAllGraph() {
    for (int i=1; i<=n; i++) {
        DetectGraph(i);
        while (!stk.empty()) {
            int tmp = stk.top();
            visited[tmp] = true;
            stk.pop();
        }
    }
}

int main()
{
    cin >> n >> e;
    ReadGraph();
    FindAllGraph();
    return 0;
}
