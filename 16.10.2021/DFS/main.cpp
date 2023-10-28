#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Ipair;
int n, m, s, t, trace[100001];
vector<int> g[100001];
Ipair Vertices[1000001];
bool visited[100001];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> Vertices[i].first >> Vertices[i].second;
}

bool CmpIpair(Ipair a, Ipair b) {
    if (a.first == b.first)
        return (a.second < b.second);
    return (a.first < b.first);
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

bool DFS(int u) {
    if (u == t)
        return true;
    for (auto v: g[u]) {
        if (!visited[v]) {
            visited[v] = true;
            trace[v] = u;
            if (DFS(v))
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DFS.INP", "r", stdin);
    freopen("DFS.OUT", "w", stdout);
    cin >> n >> m >> s >> t;
    ReadData();
    MakeGraph();
    visited[s] = true;
    trace[s] = -1;
    if (DFS(s))
        PrintAns(t);
    return 0;
}
