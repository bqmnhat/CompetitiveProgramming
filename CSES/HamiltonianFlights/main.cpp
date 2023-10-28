#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20
#define MaxMask 2000000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, m;
ll dp[MaxN+1][MaxMask];
bool vis[MaxN+1][MaxMask];
vector<int> g[MaxN+1];
const ll Mod = 1e9 + 7;
queue<pii> q;

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[v].push_back(u);
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            dp[i][mask] = -1;
    dp[1][1] = 1;
}

void DpCalculation(int CurNode, int Mask) {
    dp[CurNode][Mask] = 0;
    int PrevMask = (Mask^(1 << (CurNode-1)));
    for (int v: g[CurNode]) {
        if ((PrevMask&(1 << (v-1))) != 0) {
            if (dp[v][PrevMask] == -1)
                DpCalculation(v, PrevMask);
            dp[CurNode][Mask] = (dp[CurNode][Mask] + dp[v][PrevMask])%Mod;
        }
    }
}

ll Solution() {
    DpCalculation(n, ((1 << n) - 1));
    return dp[n][(1 << n) - 1];
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
