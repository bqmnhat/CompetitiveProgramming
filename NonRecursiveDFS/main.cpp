#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Ipair;
Ipair Vertices[1000001];
vector<int> g[100001];
int n,m,trace[100001], s, t;
bool visited[100001];
stack<int> stk;

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> Vertices[i].first >> Vertices[i].second;
}

bool CmpIpair(Ipair a, Ipair b) {
    if (a.first == b.first)
        return (a.second > b.second);
    return (a.first > b.first);
}

void MakeGraph() {
    sort(Vertices+1, Vertices+1+m, CmpIpair);
    for (int i=1; i<=m; i++)
        g[Vertices[i].first].push_back(Vertices[i].second);
}

void PrintAns(int t) {
    int i = t, ans[100001], la = 0;
    while (i != -1) {
        la++;
        ans[la] = i;
        i = trace[i];
    }
    for (int i=la; i>=1; i--)
        cout << ans[i] << ' ';
}

void DFS(int s, int t) {
    stk.push(s);
    visited[s] = true;
    trace[s] = -1;
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if (u == t)
            break;
        for (auto v: g[u]) {
            if (!visited[v]) {
                stk.push(v);
                visited[v] = true;
                trace[v] = u;
            }
        }
    }
    PrintAns(t);//Ham nay tu viet khi can thiet
}

int main()
{
    cin >> n >> m >> s >> t;
    ReadData();
    MakeGraph();
    DFS(s,t);
    return 0;
}
