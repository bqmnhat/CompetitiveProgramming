#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll c[100001];
vector<int> graph[100001];
bool vis[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> c[i];
    int u,v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

ll GroupCost(int u) {
    vis[u] = true;
    ll ans = c[u];
    for (auto v: graph[u])
        if (!vis[v])
            ans = min(ans, GroupCost(v));
    return ans;
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++)
        if (!vis[i])
            ans += GroupCost(i);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
