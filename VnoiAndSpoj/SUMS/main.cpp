#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5001
#define MaxVer 50000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m;
ll a[MaxN+1], b[MaxN+1], d[MaxVer+1];
bool vis[MaxVer+1];

void ReadData() {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    cin >> m;
    for (int i=1; i<=m; i++)
        cin >> b[i];
}

void Dijkstra(int src) {
    memset(d, 0x300000f, sizeof(d));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0LL, src));
    d[0] = 0;
    while (!pq.empty()) {
        pii tmpu = pq.top();
        pq.pop();
        int u = tmpu.second;
        if (tmpu.first > d[u])
            continue;
        for (int i=1; i<=n; i++) {
            int v = (u+a[i])%a[1];
            if (d[v] > d[u] + a[i]) {
                d[v] = d[u] + a[i];
                pq.push(pii(d[v], v));
            }
        }
    }
}

void Solve() {
    Dijkstra(0);
    for (int i=1; i<=m; i++) {
        ll r = b[i]%a[1];
        if (b[i] >= d[r])
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ReadData();
    Solve();
    return 0;
}
