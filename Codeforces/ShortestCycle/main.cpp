#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n;
bool markBFSOn[MaxN+1];
vector<int> SameBit[65], g[MaxN+1], BFSOn;
ll a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeGraph() {
    for (int j=0; j<=60; j++) {
        if (SameBit[j].size() < 2)
            continue;
        g[SameBit[j][0]].push_back(SameBit[j][1]);
        g[SameBit[j][1]].push_back(SameBit[j][0]);
        if (!markBFSOn[SameBit[j][0]]) {
            markBFSOn[SameBit[j][0]] = true;
            BFSOn.push_back(SameBit[j][0]);
        }
        if (!markBFSOn[SameBit[j][1]]) {
            markBFSOn[SameBit[j][1]] = true;
            BFSOn.push_back(SameBit[j][1]);
        }
    }
}

int BFS(int src) {
    queue<int> q;
    vector<int> dist(MaxN+1, (int)(1e9));
    vector<int> par(MaxN+1, -1);
    q.push(src);
    dist[src] = 0;
    int ans = 1e9;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (dist[v] == 1e9) {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
            else if ((par[u] != v) && (par[v] != u))
                ans = min(ans, dist[v] + dist[u] + 1);
        }
    }
    return ans;
}

int Solution() {
    for (int i=1; i<=n; i++) {
        for (ll j=0; j<=60; j++) {
            ll Mask = (1LL << j);
            if (a[i]&Mask)
                SameBit[j].push_back(i);
        }
    }
    for (int j=0; j<=60; j++)
        if (SameBit[j].size() >= 3)
            return 3;
    MakeGraph();
    int ans = 1e9+7;
    for (int u: BFSOn)
        ans = min(ans, BFS(u));
    if (ans >= 1e9)
        return -1;
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
