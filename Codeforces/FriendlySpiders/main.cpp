#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef long long ll;
int n, s, t;
ll a[MaxN+5], dist[2*MaxN+5];
int pre[2*MaxN+5];
bool Sieve[MaxN+5], vis[2*MaxN+5];
vector<int> g[2*MaxN+5], primes, Div[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i<=MaxN; i++)
        if (!Sieve[i])
            for (int j=i; i*j <= MaxN; j++)
                Sieve[i*j] = true;
    for (int i=2; i<=MaxN; i++)
        if (!Sieve[i])
            primes.push_back(i);
}

void MakeGraph() {
    for (ll x: primes) {
        ll tmp = x;
        while (tmp <= MaxN) {
            Div[tmp].push_back(x+MaxN);
            tmp += x;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j: Div[a[i]]) {
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
}

int BFS(int s, int t) {
    for (int i=1; i<=2*MaxN; i++)
        dist[i] = 2e9+7;
    queue<int> q;
    vis[s] = true;
    q.push(s);
    dist[s] = 0;
    pre[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                if (dist[v]&1)
                    pre[v] = u;
                else
                    pre[v] = pre[u];
                q.push(v);
            }
        }
    }
    if (dist[t] >= 2e9+7)
        return -1;
    return ((dist[t] >> 1) + 1);
}

void PrintPath(int s, int t) {
    int i = t;
    vector<int> res;
    while (i != -1) {
        res.push_back(i);
        i = pre[i];
    }
    reverse(res.begin(), res.end());
    res[0] = s;
    for (int x: res)
        cout << x << ' ';
}

void Solve() {
    if (s == t) {
        cout << "1\n";
        cout << s;
        return;
    }
    if ((a[s] == 1) || (a[t] == 1)) {
        cout << "-1";
        return;
    }
    int ans = BFS(s, t);
    if (ans == -1) {
        cout << "-1";
        return;
    }
    cout << ans << '\n';
    PrintPath(s, t);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    cin >> n;
    ReadData();
    MakeGraph();
    cin >> s >> t;
    Solve();
    return 0;
}
