#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Ipair;
Ipair Vertices[1000001];
vector<int> g[100001];
int n, m, trace[100001], s, t;
bool visited[100001];
queue<int> q;

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> Vertices[i].first >> Vertices[i].second;
}

bool CmpIpair(Ipair a, Ipair b) {
    if (a.first == b.first)
        return (a.second < b.second);
    return (a.first < b.first);
}

void AddEdge(int u, int v, bool directed) {
    g[u].push_back(v);
    if (!directed)
        g[v].push_back(u);
}

void MakeGraph() {
    sort(Vertices+1, Vertices+1+m, CmpIpair);
    for (int i=1; i<=m; i++)
        AddEdge(Vertices[i].first, Vertices[i].second, true);
}

void PrintAns(int t) {
    int i = t;
    int ans[100001], la = 0;
    while (i != -1) {
        la++;
        ans[la] = i;
        i = trace[i];
    }
    for (int i=la; i>=1; i--)
        cout << ans[i] << ' ';
}

void BFS(int s, int t) {
    q.push(s);
    visited[s] = true;
    trace[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t)
            break;
        for (auto v: g[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                trace[v] = u;
            }
        }
    }
    PrintAns(t);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BFS.INP", "r", stdin);
    freopen("BFS.OUT", "w", stdout);
    cin >> n >> m >> s >> t;
    ReadData();
    MakeGraph();
    BFS(s,t);
    return 0;
}
