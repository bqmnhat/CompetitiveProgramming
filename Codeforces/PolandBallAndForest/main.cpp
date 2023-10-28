#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, p[10001];
vector<int> g[10001];
bool visited[10001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
    for (int i=1; i<=n; i++) {
        g[i].push_back(p[i]);
        g[p[i]].push_back(i);
    }
}

void DFS(int u) {
    visited[u] = true;
    for (int v : g[u])
        if (!visited[v])
            DFS(v);
}

int Solution() {
    int val, ans = 0;
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            ans++;
            DFS(i);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
