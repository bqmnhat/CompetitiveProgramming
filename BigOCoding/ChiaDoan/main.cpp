#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, q, Jumps[MaxN+1][31];
ll m, a[MaxN+1], pref[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
}

int BinSearch(int id) {
    int lo = 1, hi = id, ans;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (pref[id] - pref[mid - 1] <= m) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

void CalculateJumps() {
    for (int i=1; i<=n; i++)
        Jumps[i][0] = BinSearch(i) - 1;
    for (int j=1; j<=30; j++)
        for (int i=1; i<=n; i++)
            Jumps[i][j] = Jumps[Jumps[i][j-1]][j-1];
}

void Solve() {
    for (int i=1; i<=q; i++) {
        int u, v;
        cin >> u >> v;
        int tmp = 0;
        for (int i=30; i>=0; i--) {
            if (tmp + (1 << i) < v) {
                tmp += (1 << i);
                u = Jumps[u][i];
            }
        }
        cout << Jumps[u][0] + 1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> m;
    ReadData();
    CalculateJumps();
    Solve();
    return 0;
}
