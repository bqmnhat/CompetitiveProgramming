#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
const int MAX_LOG = 32;
int n, q, par[MaxN+5][MAX_LOG+5];

void ReadData() {
    int u;
    for (int i=1; i<=n; i++) {
        cin >> u;
        par[i][0] = u;
    }
}

void Preprocess() {
    for (int k=1; k<=MAX_LOG; k++)
        for (int i=1; i<=n; i++)
            par[i][k] = par[par[i][k-1]][k-1];
}

void Solve() {
    int u;
    ll k;
    for (int i=1; i<=q; i++) {
        cin >> u >> k;
        for (ll t=MAX_LOG; t>=0; t--) {
            if ((1LL << t) <= k) {
                u = par[u][t];
                k -= (1LL << t);
            }
        }
        cout << u << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Preprocess();
    Solve();
    return 0;
}
