#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100007
#define MaxK 200007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<int, pii> piii;
struct Cmd {
    ll dist;
    int id;
    int To; //To == 0 => Ver; To == 1 => Hor
};
struct Node {
    int x, y, id;
};
int n, m, k;
ll d[MaxK+1];
Node a[MaxK+1];
vector<pii> Row[MaxN+1], Col[MaxN+1];
vector<int> g[MaxK+1];
const ll INF = 1e12+7;

void ReadData() {
    a[1] = {1, 1, 1};
    k++;
    for (int i=2; i<=k; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    k++;
    a[k] = {m, n, k};
}

bool CmpSecond(Node a, Node b) {
    return (a.y < b.y);
}

bool CmpFirst(Node a, Node b) {
    return (a.x < b.x);
}

bool CmpId(Node a, Node b) {
    return (a.id < b.id);
}

void MakeG() {
    sort(a+2, a+k, CmpSecond);
    for (int i=2; i<k; i++)
        Col[a[i].x].push_back(pii(a[i].y, a[i].id));
    sort(a+2, a+k, CmpFirst);
    for (int i=2; i<k; i++)
        Row[a[i].y].push_back(pii(a[i].x, a[i].id));
    sort(a+1, a+1+k, CmpId);
    if (Col[1].size() > 0)
        g[1].push_back(Col[1][0].second);
    if (Col[m].size() > 0)
        g[Col[m][Col[m].size()-1].second].push_back(k);
    if (Row[n].size() > 0)
        g[Row[n][Row[n].size()-1].second].push_back(k);
    for (int i=1; i<=m; i++) {
        if (Col[i].size() == 0)
            continue;
        for (int j=0; j<Col[i].size()-1; j++) {
            g[Col[i][j].second].push_back(Col[i][j+1].second);
            g[Col[i][j+1].second].push_back(Col[i][j].second);
        }
    }
    for (int i=1; i<=n; i++) {
        if (Row[i].size() == 0)
            continue;
        for (int j=0; j<Row[i].size()-1; j++) {
            g[Row[i][j].second].push_back(Row[i][j+1].second);
            g[Row[i][j+1].second].push_back(Row[i][j].second);
        }
    }
}

struct CmpCmd {
    bool operator() (Cmd const& a, Cmd const& b) {
        return (a.dist > b.dist);
    }
};

void Dijkstra() {
    for (int i=0; i<=k; i++)
        d[i] = INF;
    priority_queue<Cmd, vector<Cmd>, CmpCmd> pq;
    d[1] = 0;
    pq.push({0, 1, 0});
    while(!pq.empty()) {
        Cmd tmpu = pq.top();
        pq.pop();
        int u = tmpu.id;
        if (tmpu.dist > d[u])
            continue;
        if (u == k)
            break;
        for (int v: g[u]) {
            ll Len = 1e18;
            if (a[v].x == a[u].x) {
                if (tmpu.To == 0) {
                    Len = abs(a[v].y - a[u].y);
                    if (d[v] > d[u] + Len) {
                        d[v] = d[u] + Len;
                        pq.push({d[v], v, 0});
                    }
                }
                else {
                    Len = abs(a[v].y - a[u].y) + 1LL;
                    if (d[v] > d[u] + Len) {
                        d[v] = d[u] + Len;
                        pq.push({d[v], v, 0});
                    }
                }
            }
            if (a[v].y == a[u].y) {
                if (tmpu.To == 1) {
                    Len = abs(a[v].x - a[u].x);
                    if (d[v] > d[u] + Len) {
                        d[v] = d[u] + Len;
                        pq.push({d[v], v, 1});
                    }
                }
                else {
                    Len = abs(a[v].x - a[u].x) + 1LL;
                    if (d[v] > d[u] + Len) {
                        d[v] = d[u] + Len;
                        pq.push({d[v], v, 1});
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("SUPERTHIEF.INP", "r", stdin);
    //freopen("SUPERTHIEF.OUT", "w", stdout);
    cin >> m >> n >> k;
    ReadData();
    MakeG();
    Dijkstra();
    if (d[k] >= INF)
        cout << "-1";
    else
        cout << d[k];
    return 0;
}
