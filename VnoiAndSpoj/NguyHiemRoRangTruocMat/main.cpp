#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxM 10000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll INF = 1e12 + 7;
int n, m, a[MaxM+5];
ll w[MaxN+5][MaxN+5], dist[MaxN+5][MaxN+5];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> w[i][j];
}

void Init() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j)
                continue;
            dist[i][j] = INF;
        }
    }
}

void FindDist(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0LL, src));
    dist[src][src] = 0LL;
    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        ll d = tmp.first;
        if(d > dist[src][u])
            continue;
        for (int v=1; v<=n; v++) {
            if (u == v)
                continue;
            if (dist[src][v] > dist[src][u] + w[u][v]) {
                dist[src][v] = dist[src][u] + w[u][v];
                pq.push(pii(dist[src][v], v));
            }
        }
    }
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++)
        FindDist(i);
    a[0] = 1;
    a[m+1] = n;
    for (int i=1; i<=m+1; i++)
        ans += dist[a[i-1]][a[i]];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Init();
    cout << Solution();
    return 0;
}
