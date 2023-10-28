#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll Mod = 1e9 + 7;
ll dpDown[MaxN+5], SumDown[MaxN+5];
int n;
vector<pii> g[MaxN+5];

void ReadData() {
    int u, v;
    ll w;
    for (int i=1; i<n; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }
}

void DFSDown(int u, int p) {
    dpDown[u] = 0;
    SumDown[u] = 0;
    for (pii tmp: g[u]) {
        int v = tmp.first;
        ll w = tmp.second;
        if (v != p) {
            DFSDown(v, u);
            dpDown[u] =((dpDown[u] + (SumDown[v]+1LL)*w + dpDown[v])%Mod)%Mod;
            if (SumDown[u] != 0)
                dpDown[u] = (dpDown[u] + ((((SumDown[v]+1LL)*w)%Mod)*SumDown[u])%Mod)%Mod;
            SumDown[u] = (SumDown[u] + ((SumDown[v]+1LL)*w)%Mod)%Mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    DFSDown(1, -1);
    cout << dpDown[1];
    return 0;
}
