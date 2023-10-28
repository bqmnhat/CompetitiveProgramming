#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, Q, a[100001], prefix[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void MakePrefix() {
    for (int i=1; i<=n; i++)
        prefix[i] = prefix[i-1] + a[i];
}

void Solve() {
    for (int i = 1; i<=Q; i++) {
        int l, r, ans;
        cin >> l >> r;
        ans = prefix[r] - prefix[l-1];
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SUMQUERIES.INP", "r", stdin);
    freopen("SUMQUERIES.OUT", "w", stdout);
    cin >> n >> Q;
    ReadData();
    MakePrefix();
    Solve();
    return 0;
}
