#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, c[MaxN+5], SumDif = 0, cnt[MaxN+5];
vector<pii> edges;

void ReadData() {
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back(pii(u, v));
    }
    for (int i=1; i<=n; i++)
        cin >> c[i];
}

void Solve() {
    vector<int> res;
    res.clear();
    for (int i=0; i<n-1; i++) {
        int u = edges[i].first, v = edges[i].second;
        if (c[u] != c[v]) {
            SumDif++;
            cnt[u]++;
            cnt[v]++;
        }
    }
    for (int i=1; i<=n; i++)
        if (cnt[i] - SumDif == 0)
            res.push_back(i);
    if (res.size()) {
        cout << "YES\n";
        for (int x: res)
            cout << x << ' ';
    }
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
