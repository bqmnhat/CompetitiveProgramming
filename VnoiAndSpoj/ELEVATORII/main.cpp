#include <iostream>
#include <bits/stdc++.h>
#define MaxVer 100000
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
ll h, d[MaxVer+1], a[4];
const ll INF = LLONG_MAX/2;

void Dijkstra() {
    for (int i=0; i<=MaxVer; i++)
        d[i] = INF;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[0] = 0;
    pq.push(pii(0, 0));
    while(!pq.empty()) {
        pii tmpu = pq.top();
        pq.pop();
        ll u = tmpu.second;
        if (tmpu.first > d[u])
            continue;
        for (int i=1; i<=3; i++) {
            ll v = (u + a[i])%a[1];
            if (d[v] > d[u] + 1LL*a[i]) {
                d[v] = d[u] + 1LL*a[i];
                pq.push(pii(d[v], v));
            }
        }
    }
}

ll Solution() {
    if ((a[1] == 1) || (a[2] == 1) || (a[3] == 1))
        return h;
    h--;
    ll ans = 0;
    for (ll i=0; i<a[1]; i++) {
        ll x = (h - i)%a[1];
        if ((h >= i) && (d[x] < INF)) {
            if (h - i - d[x] < 0)
                continue;
            ans += max((h - i - d[x])/(1LL*a[1])+1LL, 0LL);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    cin >> h >> a[1] >> a[2] >> a[3];
    Dijkstra();
    cout << Solution();
    return 0;
}
