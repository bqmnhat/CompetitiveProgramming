#include <iostream>
#include <bits/stdc++.h>
#define MaxN 400
using namespace std;
typedef pair<int, int> pii;
int n, dp[MaxN+5], rem[MaxN+5];
vector<int> g[MaxN+5];

void ReadData() {
    int u;
    while ((cin >> u) && (u != 0)) {
        int m, v;
        cin >> m;
        for (int i=1; i<=m; i++) {
            cin >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
}

void DFSDP(int u, int p) {
    if ((p != -1) && (g[u].size() == 1)) {
        dp[u] = 1;
        rem[u] = 0;
        return;
    }
    dp[u] = 0;
    vector<pii> tmp;
    for (int v: g[u]) {
        if (v != p) {
            DFSDP(v, u);
            tmp.push_back(pii(dp[v], rem[v]));
        }
    }
    sort(tmp.begin(), tmp.end(), greater<pii>());
    int curStone = 0;
    for (int i=0; i<tmp.size(); i++) {
        if (curStone < tmp[i].first) {
            dp[u] += (tmp[i].first - curStone);
            curStone += (tmp[i].first - curStone);
        }
        curStone = curStone - tmp[i].first + tmp[i].second;
    }
    if (u == 1)
        rem[u] = curStone + g[u].size() - 1;
    else
        rem[u] = curStone + g[u].size() - 2;
}

int Solution() {
    if (n == 1)
        return 1;
    DFSDP(1, -1);
    return dp[1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("RAISOI.INP", "r", stdin);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
