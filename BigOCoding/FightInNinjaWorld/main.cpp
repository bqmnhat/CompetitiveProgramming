#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, dist[100001], mx;
vector<int> g[100001];
queue<int> q;

void ReadData() {
    for (int i=1; i<=n; i++) {
        int a,b;
        cin >> a >> b;
        mx = max(mx, a);
        mx = max(mx, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

int BFS(int s) {
    q.push(s);
    dist[s] = 0;
    int cnt[2] = {0, 0};
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt[dist[u]%2]++;
        for (auto v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    return max(cnt[0], cnt[1]);
}

int SolutionForTestCase() {
    for (int i=1; i<=mx; i++)
        dist[i] = -1;
    int ans = 0;
    for (int i=1; i<=mx; i++) {
        if ((dist[i] == -1) && (!g[i].empty()))
            ans += BFS(i);
    }
    for (int i=1; i<=mx; i++)
        g[i].clear();
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        mx = 0;
        ReadData();
        cout << "Case " << i << ": " << SolutionForTestCase() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
