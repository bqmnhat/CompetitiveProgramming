#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool vis[27];
vector<int> graph[27], res;

void Init() {
    for (int i=0; i<=25; i++)
        vis[i] = true;
}

void ReadGraph() {
    string PreS, s;
    cin >> PreS >> s;
    while (s != "#") {
        for (int i=0; i<min(PreS.length(), s.length()); i++)
            if (PreS[i] != s[i]) {
                graph[int(PreS[i] - 'A')].push_back(s[i] - 'A');
                vis[PreS[i] - 'A'] = vis[s[i] - 'A'] = false;
                break;
            }
        PreS = s;
        cin >> s;
    }
}

void DFS (int u) {
    vis[u] = true;
    for (auto v: graph[u])
        if (!vis[v])
            DFS(v);
    res.push_back(u);
}

void Solve() {
    for (int i=0; i<=25; i++)
        if (!vis[i])
            DFS(i);
    reverse(res.begin(), res.end());
    for (auto i: res)
        cout << char(i+'A');
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    ReadGraph();
    Solve();
    return 0;
}
