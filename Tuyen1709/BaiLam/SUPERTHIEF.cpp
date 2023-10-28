#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100007
#define MaxK 200007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<int, pii> piii;
struct Cmd {
    int id;
    pii cor;
    int To; //To == 0 => Go to rows; To == 1 => Go to cols
};
int n, m, k;
ll d[MaxK+1];
pii a[MaxK+1];
vector<piii> Row[MaxN+1], Col[MaxN+1];
vector<pii> g[MaxN+1];
queue<Cmd> q;
const ll INF = 1e18+7;

void ReadData() {
    a[1] = pii(1, 1);
    k++;
    for (int i=2; i<=k; i++) {
        cin >> a[i].first >> a[i].second;
        Col[a[i].first].push_back(piii(i, a[i]));
        Row[a[i].second].push_back(piii(i, a[i]));
    }
    k++;
    a[k] = pii(m, n);
    Col[m].push_back(piii(k, a[k]));
    Row[n].push_back(piii(k, a[k]));
}

void MakeG() {
    for (piii x: Col[1]) {
        int len = abs(x.second.second - 1);
        g[1].push_back(pii(x.first, len));
    }
    for (int i=1; i<=m; i++) {
        if (Col[i].size() == 0)
            continue;
        for (int j=0; j<Col[i].size(); j++) {
            for (int t = j+1; t<Col[i].size(); t++) {
                int len = abs(Col[i][j].second.second - Col[i][t].second.second) + 1;
                g[Col[i][j].first].push_back(pii(Col[i][t].first, len));
                g[Col[i][t].first].push_back(pii(Col[i][j].first, len));
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (Row[i].size() == 0)
            continue;
        for (int j=0; j<Row[i].size(); j++) {
            for (int t = j+1; t<Row[i].size(); t++) {
                int len = abs(Row[i][j].second.first - Row[i][t].second.first) + 1;
                g[Row[i][j].first].push_back(pii(Row[i][t].first, len));
                g[Row[i][t].first].push_back(pii(Row[i][j].first, len));
            }
        }
    }
}

void Dijkstra() {
    for (int i=0; i<=k; i++)
        d[i] = INF;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[1] = 0;
    pq.push(pii(0, 1));
    while(!pq.empty()) {
        pii tmpu = pq.top();
        pq.pop();
        ll u = tmpu.second;
        if (tmpu.first > d[u])
            continue;
        for (pii tmpv: g[u]) {
            int v = tmpv.first;
            ll w = tmpv.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(pii(d[v], v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SUPERTHIEF.INP", "r", stdin);
    freopen("SUPERTHIEF.OUT", "w", stdout);
    cin >> m >> n >> k;
    if (k > 2000)
        cout << -1;
    else {
        ReadData();
        MakeG();
        Dijkstra();
        if (d[k] >= INF)
            cout << "-1";
        else
            cout << d[k];
    }
    return 0;
}
