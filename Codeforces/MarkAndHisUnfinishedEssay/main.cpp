#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int t, c, q;
ll n, l, r, k, DisFromOrg[MaxN+1];
string s;
pii Queries[MaxN+1], Segs[MaxN+1];

void ReadQueries() {
    for (int i=1; i<=c; i++) {
        cin >> Queries[i].first >> Queries[i].second;
        ll len = Queries[i].second - Queries[i].first + 1;
        Segs[i].first = n + 1;
        Segs[i].second = n + len;
        DisFromOrg[i] = Segs[i].first - Queries[i].first;
        n += len;
    }
}

void SolveTestCase() {
    cin >> n >> c >> q >> s;
    ReadQueries();
    for (int i=1; i<=q; i++) {
        cin >> k;
        for (int i=c; i>=1; i--)
            if ((Segs[i].first <= k) && (k <= Segs[i].second))
                k = k - DisFromOrg[i];
        cout << s[k-1] << '\n';
    }
}

void Solve() {
    for (int i=1; i<=t; i++)
        SolveTestCase();
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
