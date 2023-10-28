#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
int n, m, trace[100001];
vector<pil> graph[100001];
ll dist[100001];

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v, wei;
        cin >> u >> v >> wei;
        graph[u].push_back(pil(v, wei));
        graph[v].push_back(pil(u, wei));
    }
}

void DijkStra(int s, int t) {
    set<pil> setds;
    for (int i=1; i<=n; i++)
        dist[i] = 1e18;
    setds.insert(pil(0, s));
    dist[s] = 0;
    while (!setds.empty()) {
        pil tmp = (*setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        for (auto e: graph[u]) {
            int v = e.first, wei = e.second;
            if (dist[v] > dist[u] + wei) {
                if (dist[v] != 1e18)
                    setds.erase(setds.find(pil(dist[v], v)));
                dist[v] = dist[u] + wei;
                setds.insert(pil(dist[v], v));
                trace[v] = u;
            }
        }
    }
    if (dist[t] == 1e18) {
        cout << "-1";
        return;
    }
    int i = t;
    vector<int> ans(0, n);
    while (i != s) {
        ans.push_back(i);
        i = trace[i];
    }
    ans.push_back(s);
    reverse(ans.begin(), ans.end());
    for (int x: ans)
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    DijkStra(1, n);
    return 0;
}
