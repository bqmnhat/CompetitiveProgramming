#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii; // first i height, second i IsLeaf, Last i is node
int n, k;
ll ans = 0, dp[MaxN+1];
bool mark[MaxN+1];
vector<int> g[MaxN+1];
priority_queue<ll> pq;

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}\

void DFS(int u, int p, int h) {
    for (int v: g[u]) {
        if (v == p)
            continue;
        DFS(v, u, h+1);
        dp[u] += (dp[v] + 1);
    }
    pq.push(dp[u] - h);
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n-k; i++) {
        ll tmp = pq.top();
        ans += tmp;
        pq.pop();
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    DFS(1, -1, 0);
    cout << Solution();
    return 0;
}
