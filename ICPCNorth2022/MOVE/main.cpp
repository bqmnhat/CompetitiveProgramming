#include <iostream>
#include <bits/stdc++.h>
#define MaxM 1000000
#define MaxN 10
using namespace std;
typedef long long ll;
ll a[MaxN+1], b[MaxN+1], m, s;
int n;
bool vis[MaxM+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i] >> b[i];
}

int BFS(int src) {
    queue<ll> q;
    vis[src] = true;
    q.push(src);
    int dist = -1;
    while (!q.empty()) {
        dist++;
        int sz = q.size();
        while (sz--) {
            ll u = q.front();
            q.pop();
            if (u == 0)
                return dist;
            for (int i=1; i<=n; i++) {
                ll Nxt = ((u*a[i])%m + b[i])%m;
                if (!vis[Nxt]) {
                    vis[Nxt] = true;
                    q.push(Nxt);
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> s;
    ReadData();
    cout << BFS(s);
    return 0;
}
